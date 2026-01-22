#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

void read_pgm(const char* filename, unsigned char** data, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) { perror("fopen"); exit(1); }

    char header[3];
    fscanf(fp, "%2s", header);
    if (header[0] != 'P' || header[1] != '5') {
        fprintf(stderr, "Only binary P5 PGM format supported.\n");
        exit(1);
    }

    fscanf(fp, "%d %d", width, height);
    int maxval;
    fscanf(fp, "%d", &maxval);
    fgetc(fp); // skip newline

    int size = (*width) * (*height);
    *data = malloc(size);
    fread(*data, 1, size, fp);
    fclose(fp);
}

void write_pgm(const char* filename, unsigned char* data, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    fwrite(data, 1, width * height, fp);
    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.pgm output.pgm\n", argv[0]);
        return 1;
    }

    unsigned char *input, *output;
    int width, height;

    read_pgm(argv[1], &input, &width, &height);
    output = malloc(width * height);

    apply_edge_filter(input, output, width, height);

    write_pgm(argv[2], output, width, height);

    free(input);
    free(output);
    return 0;
}
