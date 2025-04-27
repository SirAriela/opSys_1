#include <stdio.h>
#include <complex.h>
#include <stdbool.h>
#include <string.h>
#include "mandelbrot.h"

#define DEFAULT_N 200

int main() {
    double real, imag;
    int n;
    char buffer[100];


    while (1) {
        printf("Enter real and imaginary parts (and optionally N), 0 0 to quit:\n");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break; // end of input
        }

        // מנסים לקרוא שלושה מספרים מהשורה
        int input_count = sscanf(buffer, "%lf %lf %d", &real, &imag, &n);

        if (input_count == 2) {
            n = DEFAULT_N;
        } else if (input_count != 3) {
            fprintf(stderr, "Invalid input!\n");
            break;
        }

        if (real == 0 && imag == 0) {
            printf("Goodbye!\n");
            break;
        }

        double complex c = real + imag * I;

        if (mandelbrot(c, n)) {
            printf("%.3f + %.3fi is in the Mandelbrot set\n", real, imag);
        } else {
            printf("%.3f + %.3fi is NOT in the Mandelbrot set\n", real, imag);
        }
    }

    return 0;
}
