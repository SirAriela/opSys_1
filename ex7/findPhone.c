#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Check for exactly one argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Name> \n", argv[0]);
        exit(1);
    }

    int pipe1[2], pipe2[2];

    // Create the pipes
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(1);
    }

    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(1);
    }

    // First child process: "cat phonebook.txt"
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Redirect stdout to pipe1 write end
        close(pipe1[0]);
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[1]);

        char* exe[3] = {"cat", "phonebook.txt", NULL};

        execvp("cat", exe);

        // If execvp fails
        perror("execvp cat");
        exit(1);
    }

    // Second child process: executes "grep <Name>"
    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Redirect stdin from pipe1 read end
        close(pipe1[1]);
        dup2(pipe1[0], STDIN_FILENO);
        close(pipe1[0]);

        // Redirect stdout to pipe2 write end
        close(pipe2[0]);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe2[1]);

        // Set up arguments for execvp to run "grep <Name>"
        argv[0] = "grep";
        argv[argc] = NULL; // Ensure NULL-terminated arguments
        execvp("grep", argv);

        // If execvp fails
        perror("execvp grep");
        exit(1);
    }

    // Parent closes pipe1 ends (not used anymore)
    close(pipe1[0]);
    close(pipe1[1]);

    // Third child process: executes "cut -d, -f2"
    pid_t pid3 = fork();
    if (pid3 == 0) {
        // Redirect stdin from pipe2 read end
        close(pipe2[1]);
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe2[0]);

        char* exe[4] = {"cut", "-d,", "-f2", NULL};
        execvp("cut", exe);

        // If execvp fails
        perror("execvp cut");
        exit(1);
    }

    // Parent closes pipe2 ends (not used anymore)
    close(pipe2[0]);
    close(pipe2[1]);

    // Parent waits for all child processes to finish
    for (int i = 0; i < 3; i++) wait(NULL);

    return 0;
}
