
/**
 * @file filter.h
 * @brief Header file for filter implementation.
 */
#ifndef FILTER_H
#define FILTER_H

#include "circ_buff.h"

/**
 * @struct filter_fir
 * @brief First-order IIR (Infinite Impulse Response) filter structure.
 */
struct filter_fir {
  /**
     * @brief Circular buffer used to store input samples.
     */
    struct circ_buff *buff;

    /**
     * @brief Coefficients for the FIR filter.
     */
    float *coefficients;

    /**
     * @brief Length of the coefficients array.
     */
    int N; // coefficients length
};

/**
 * @struct filter_iir
 * @brief Second-order IIR (Infinite Impulse Response) filter structure.
 */
struct filter_iir {
    /**
     * @brief Circular buffer used to store input samples.
     */
    struct circ_buff *in_buff;

    /**
     * @brief Circular buffer used to store previous output samples.
     */
    struct circ_buff *out_buff;

    /**
     * @brief Forward coefficients for the IIR filter.
     */
    float *a;

    /**
     * @brief Backward coefficients for the IIR filter.
     */
    float *b;

    /**
     * @brief Length of the forward coefficients array.
     */
    int N; // forward coefficients length

    /**
     * @brief Length of the backward coefficients array.
     */
    int M; // backward coefficients length
};

/**
 * @brief Creates a new FIR filter.
 * @param filter The filter.
 * @param coefficients The coefficients.
 * @param N The length of the coefficients.
 * @return The created filter.
 */
void filter_create_fir(struct filter_fir* filter, float *coefficients, int N);

/**
 * @brief Creates a new IIR filter.
 * @param filter The filter.
 * @param a Forward coefficients.
 * @param b Backward coefficients.
 * @param N Length of forward coefficients.
 * @param M Length of backward coefficients.
 */
void filter_create_iir(struct filter_iir* filter, float *a, float *b, int N, int M);

/**
 * @brief Performs an IIR filter operation.
 * @param filter The filter.
 * @param value Input sample to process.
 */
void filter_perform_iir(struct filter_iir* filter, float* value);

/**
 * @brief Performs a FIR filter operation.
 * @param filter The filter.
 * @param value Input sample to process.
 */
void filter_perform_fir(struct filter_fir* filter, float* value);

#endif
