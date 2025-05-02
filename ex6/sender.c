#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sched.h>
// Sends a single bit to another process using SIGUSR1 (for 0) or SIGUSR2 (for 1)
void send_bit(pid_t receiver_pid, int bit) {
    int sig = (bit == 1) ? SIGUSR2 : SIGUSR1;
    
    if (kill(receiver_pid, sig) == -1) {
        perror("Failed to send signal");
        exit(1);
    }
     
    // Sleep briefly to allow receiver to process the signal
    usleep(100000); // 100ms (adjust as needed)
}
 
int main() {
    pid_t receiver_pid;
    unsigned int number;
    int bit;
     
    // Get receiver's PID
    printf("Enter receiver's PID: ");
    if (scanf("%d", &receiver_pid) != 1) {
        printf("Invalid PID\n");
        return 1;
    }
     
    // Get number to send (must be 8-bit, 0-255)
    printf("Enter a number (0-255): ");
    if (scanf("%u", &number) != 1 || number > 255) {
        printf("Invalid number. Must be between 0 and 255.\n");
        return 1;
    }
     
    printf("Sending number %u to process %d\n", number, receiver_pid);
     
    // Signal the start of transmission (either signal works as a "start" indicator)
    if (kill(receiver_pid, SIGUSR1) == -1) {
        perror("Failed to send start signal");
        return 1;
    }
    usleep(200000); // 200ms to ensure receiver is ready
     
    // Send each bit, starting from the least significant bit (LSB)
    for (int i = 0; i < 8; i++) {
        bit = (number >> i) & 1; // Extract the i-th bit
        printf("Sending bit %d: %d\n", i, bit);
        send_bit(receiver_pid, bit);
    }
     
    printf("Transmission complete.\n");
    return 0;
}