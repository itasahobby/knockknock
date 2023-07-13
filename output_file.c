#include "output.h"
#include <stdarg.h>
#include <stdlib.h>

#ifndef OUTPUT_FILE
#error OUTPUT_FILE must be set
#endif

static FILE *output_file = NULL;

void output_init() {
    output_file = fopen(OUTPUT_FILE, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(1);
    }
}

void output_cleanup() {
    fclose(output_file);
}

void output(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(output_file, format, args);
    va_end(args);
}
