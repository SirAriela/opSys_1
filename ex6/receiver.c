 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <signal.h>
 
 // Global variables
 // These variables are declared as volatile to prevent compiler optimizations that could
 volatile unsigned int received_number = 0; 
 volatile int bit_position = 0;            
 volatile int receiving = 0;               
 
 // Signal handler for SIGUSR1 (represents bit value 0)
 void handle_sigusr1(int sig) {
     (void)sig; 
     if (!receiving) { // Check if we are already receiving a number
         receiving = 1;
         received_number = 0;
         bit_position = 0;
         return;
     }
     
     // Here we want to increase the bit position
     bit_position++;
     
     // Check if we've received all 8 bits
     if (bit_position >= 8) {
         printf("Number received: %u\n", received_number);
         receiving = 0;
     }
 }
 
 // Signal handler for SIGUSR2 (represents bit value 1)
 void handle_sigusr2(int sig) {
     (void)sig; 
     if (!receiving) {
         receiving = 1;
         received_number = 0;
         bit_position = 0;
         return;
     }
     
     // Set the bit at the current position to 1
     received_number |= (1 << bit_position);
     bit_position++;
     
     // Check if we've received all 8 bits
     if (bit_position >= 8) {
         printf("Number received: %u\n", received_number);
         receiving = 0;
     }
 }
 
 int main() {
     // Register signal handlers
     if (signal(SIGUSR1, handle_sigusr1) == SIG_ERR) {
         perror("Unable to register SIGUSR1 handler");
         exit(1);
     }
     
     if (signal(SIGUSR2, handle_sigusr2) == SIG_ERR) {
         perror("Unable to register SIGUSR2 handler");
         exit(1);
     }
     
     // Print PID so the sender knows where to send signals
     printf("Receiver PID: %d\n", getpid());
     printf("Waiting for signals...\n");
     
     // Wait indefinitely for signals
     while (1) {
         pause(); 
     }
     
     return 0;
 }