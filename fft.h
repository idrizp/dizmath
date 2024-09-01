#ifndef FFT_H
#define FFT_H

#include "cpx.h"

/**
 * Performs a radix N FFT in-place
 * @param in The input array
 * @param N the number of points
 */
void fft(struct complex* in, int N);

#endif