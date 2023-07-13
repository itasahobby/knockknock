#include "output.h"
#include <stdarg.h>

void output_init() {
}

void output_cleanup() {
}

void output(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}
