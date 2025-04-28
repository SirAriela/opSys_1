#include "mandelbrot.h"

bool is_in_mandelbrot(double complex c, int N) {

    //temp
    double complex z = 0;

    //chek for Zn if in mendelsbrot set
    //Zn+1 = Zn^2 + c
    for (int n = 0; n < N; n++) {
        if (cabs(z) > 2.0) {
            return false;
        }
        z = z * z + c;
    }
    return true;
}



