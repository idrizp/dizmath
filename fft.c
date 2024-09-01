#include "fft.h"
#include "stdlib.h"
#include "math.h"

#define TWO_PI 2 * M_PI

void fft(struct complex* in, int N, int ifft) {
    if (N == 1) {
        return in[0];
    }
    
    struct complex* ev = malloc(sizeof(struct complex) * N/2);
    struct complex* od = malloc(sizeof(struct complex) * N/2);
    
    for (int i = 0; i < N; i++) {
        ev[i] = in[2*i];
        od[i] = in[2*i + 1];
    }

    fft(ev, N/2, ifft);
    fft(od, N/2, ifft);

    for (int k = 0; k < N/2; k++) {
        struct complex t = complex_exp((TWO_PI * (ifft ? 1 : -1)) * k / N);
        complex_mul(&t, od[k]);
        
        in[k] = ev[k];
        complex_add(&in[k], t);
        
        in[k + N/2] = ev[k];
        complex_sub(&in[k + N/2], t);

        // Normalization/scaling factor
        if (ifft) {
            struct complex complex_factor = complex_create(1.0 / N, 0);
            complex_mul(&in[k], complex_factor);
            complex_mul(&in[k + N/2], complex_factor);
        }
    }
    
    free(ev);
    free(od);
}