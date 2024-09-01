#include "filter.h"
#include "circ_buff.h"

void filter_create_fir(struct filter_fir* filter, float *coefficients, int N) {
    filter->buff = (struct circ_buff*)malloc(sizeof(struct circ_buff));
    circ_buff_create(filter->buff, N, 0, 0);
    filter->coefficients = coefficients;
    filter->N = N;
}

void filter_create_iir(struct filter_iir* filter, float *a, float *b, int N, int M) {
    filter->in_buff = (struct circ_buff*)malloc(sizeof(struct circ_buff));
    circ_buff_create(filter->in_buff, N + M - 1, 0, 0);
    filter->a = a;
    filter->b = b;
    filter->N = N;
    filter->M = M;
}


void filter_perform_fir(struct filter_fir* filter, float* value) {
    struct circ_buff* buff = filter->buff;
    if (circ_buff_full(buff)) {
        // Handle buffer full condition
        return;
    }
    for (int i = 0; i < filter->N - 1; i++) {
        float val;
        circ_buff_read(buff, &val);
        *value += val * filter->coefficients[i];
    }
    float input_val = *value;
    circ_buff_write(buff, input_val);
}

void filter_perform_iir(struct filter_iir* filter, float* input) {
  struct circ_buff* input_buff = filter->in_buff;
    struct circ_buff* output_buff = filter->out_buff; // Added a new buffer for output

    if (circ_buff_full(input_buff)) {
        // Handle full input buffer condition
        return;
    }

    float output = 0;
    int N = filter->N;
    int M = filter->M;
    float* a = filter->a;
    float* b = filter->b;

    // Initialize output buffer
    if (circ_buff_empty(output_buff)) {
        for (int i = 0; i < M - 1; i++) {
            if (circ_buff_full(output_buff)) {
                break;
            }
            circ_buff_write(output_buff, 0);
        }
    }

    for (int i = 0; i < M - 1; i++) {
        float val;
        circ_buff_write(output_buff, 0); // Clear old values from output buffer
        circ_buff_read(input_buff, &val);
        output = val * b[i]; // First y-term

        for (int j = 0; j < M - 2; j++) {
            float prev_val;
            circ_buff_read(input_buff, &prev_val);
            output = a[i] * output + b[i + 1] * prev_val;
            // Use x[j+1] value
        }
        circ_buff_write(output_buff, output);
    }

    *input = 0;
    for (int i = M - 2; i > 0; i--) {
        if (circ_buff_full(output_buff)) {
            break;
        }
        float prev_val;
        circ_buff_read(output_buff, &prev_val);
        *input += a[i + 1] * prev_val;
    }
}
