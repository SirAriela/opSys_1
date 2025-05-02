// signal_sender.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    pid_t receiver_pid;
    int message;

    printf("Enter receiver PID: ");
    scanf("%d", &receiver_pid);

    printf("Enter message: ");
    scanf("%d", &message);

    for (int i = 7; i >= 0; i--) {
        int bit = (message >> i) & 1;
        int signal_to_send = bit ? SIGUSR2 : SIGUSR1;
        kill(receiver_pid, signal_to_send);
        usleep(100000); // 0.1 שניות
    }

    return 0;
}