#include <stdlib.h>
#include "filter.h"

void apply_edge_filter(unsigned char* input, unsigned char* output, int width, int height) {
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int idx = y * width + x;
            int gx = -input[(y - 1) * width + (x - 1)] - 2 * input[y * width + (x - 1)] - input[(y + 1) * width + (x - 1)]
                     + input[(y - 1) * width + (x + 1)] + 2 * input[y * width + (x + 1)] + input[(y + 1) * width + (x + 1)];
            output[idx] = gx > 255 ? 255 : (gx < 0 ? 0 : gx);
        }
    }
}
