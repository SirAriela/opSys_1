/*
 * mandelbrot.c - Check if a complex number belongs to the Mandelbrot set
 *
 * Compilation: gcc -o mandelbrot mandelbrot.c -lm
 * Execution: ./mandelbrot real_part imaginary_part [iterations]
 */

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

// Default values
#define DEFAULT_N 100  // Default number of iterations
#define M 2.0          // Divergence threshold

void print_help() {
    fprintf(stderr, "Usage: ./mandelbrot real_part imaginary_part [iterations]\n");
    fprintf(stderr, "Check if a complex number c = real_part + imaginary_part*i belongs to the Mandelbrot set\n");
    fprintf(stderr, "  real_part      - real part of the complex number\n");
    fprintf(stderr, "  imaginary_part - imaginary part of the complex number\n");
    fprintf(stderr, "  iterations     - optional: number of iterations (default: %d)\n", DEFAULT_N);
    fprintf(stderr, "\nExample: ./mandelbrot -0.5 0.5\n");
}

int is_in_mandelbrot(double complex c, int n, double threshold) {
    double complex z = 0;
    
    for (int i = 0; i < n; i++) {
        z = z*z + c;
        
        // Check if the sequence is diverging
        if (cabs(z) > threshold) {
            return 0; // Not in the set
        }
    }
    
    return 1; // Likely in the set
}

int main(int argc, char *argv[]) {
    // Check if we have enough arguments
    if (argc < 3) {
        print_help();
        return 1;
    }
    
    // Parse the arguments
    double real_part = atof(argv[1]);
    double imag_part = atof(argv[2]);
    int iterations = (argc >= 4) ? atoi(argv[3]) : DEFAULT_N;
    
    // Create the complex number
    double complex c = real_part + imag_part * I;
    
    // Check if it's in the Mandelbrot set
    if (is_in_mandelbrot(c, iterations, M)) {
        printf("The complex number %.2f + %.2fi appears to be in the Mandelbrot set.\n", 
               real_part, imag_part);
    } else {
        printf("The complex number %.2f + %.2fi is NOT in the Mandelbrot set.\n", 
               real_part, imag_part);
    }
    
    return 0;
}