# C Image Filter

This project applies a simple edge-detection filter to PGM images in the Portable GrayMap format.

## Build Instructions

To compile:
```
make
```

## Run Instructions

To apply the filter to an image:
```
./bin/image_filter input.pgm output.pgm
```

## Notes

- Only binary P5 PGM files are supported.
- Example test images are located in the tests/ directory.
