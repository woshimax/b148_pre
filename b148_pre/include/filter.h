#ifndef FILTER_H
#define FILTER_H

void apply_edge_filter(unsigned char* input, unsigned char* output, int width, int height);
void apply_invert_filter(unsigned char* input, unsigned char* output, int width, int height);
void apply_threshold_filter(unsigned char* input, unsigned char* output, int width, int height);

#endif
