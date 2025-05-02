// signal_receiver.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t bit_count = 0;
volatile sig_atomic_t received_value = 0;

void handle_signal(int signum) {
    received_value <<= 1;
    if (signum == SIGUSR2) {
        received_value |= 1;
    }
    bit_count++;
}

int main() {
    printf("My PID is %d\n", getpid());

    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (bit_count < 8) {
        pause(); // מחכה לסיגנל
    }

    printf("Received %d\n", received_value);

    return 0;
}