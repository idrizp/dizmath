#include "circ_buff.h"
#include "stdlib.h"

void circ_buff_create(struct circ_buff* buff, int N, int read_idx, int write_idx) {
    buff->N = N;
    buff->values = (float *) calloc(N, sizeof(float));
    buff->read_idx = read_idx;
    buff->write_idx = write_idx;
}

void circ_buff_write(struct circ_buff* buff, float value) {
    buff->values[buff->write_idx] = value;
    buff->write_idx = (buff->write_idx + 1) % buff->N; // Wrap around
}

void circ_buff_read(struct circ_buff* buff, float * value) {
    *value = buff->values[buff->read_idx];
    buff->read_idx = (buff->read_idx + 1) % buff->N; // Wrap around
}

void circ_buff_remove(struct circ_buff* buff) {
    free(buff->values);
}

int circ_buff_full(struct circ_buff* buff) {
    return buff->read_idx == buff->write_idx;
}
