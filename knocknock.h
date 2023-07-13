#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>

void output_init();
void output_cleanup();
void output(const char *format, ...);

#endif
