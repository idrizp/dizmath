#ifndef CIRC_BUFF_H
#define CIRC_BUFF_H

/**
 * The circular buffer struct.
 */
struct circ_buff {
    float* values;
    int N;
    int read_idx;
    int write_idx;
};

/**
 * Creates a circular buffer.
 * @param buff The circular buffer.
 * @param N The number of points in the circular buffer.
 * @param read_idx The read index.
 * @param write_idx The write index.
 */
void circ_buff_create(struct circ_buff* buff, int N, int read_idx, int write_idx);

/**
 * Writes to the write pointer of the circular buffer. 
 * @param buff The circular buffer.
 * @param value The value of the circular buffer we want to write.
 */
void circ_buff_write(struct circ_buff* buff, float value);

/**
 * Reads from the read pointer of the circular buffer.
 * @param buff The circular buffer.
 * @param value The value we want to populate.
 */
void circ_buff_read(struct circ_buff* buff, float * value);

/**
 * Removes the circular buffer.
 * @param buff The circular buffer.
 */
void circ_buff_remove(struct circ_buff* buff);

/**
 * Returns if the circular buffer is full.
 * @param buff The buffer.
 */
int circ_buff_full(struct circ_buff* buff);

#endif