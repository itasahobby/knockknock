#include <stdio.h>
#include <string.h>
#include "output.h"

extern char **environ;

#ifdef OUTPUT_STDOUT
#include "output_stdout.c"
#elif defined(OUTPUT_FILE)
#include "output_file.c"
#elif defined(OUTPUT_SOCKET)
#include "output_socket.c"
#endif

int main(int argc, char *argv[]) {
    output_init();

    for (int i = 0; i < argc; i++) {
        output("argv[%d]: %s\n", i, argv[i]);
    }

    for (char **env = environ; *env != NULL; env++) {
        char *separator = strchr(*env, '=');
        if (separator != NULL) {
            output("env[");
            output("%.*s", (int)(separator - *env), *env);
            output("]: %s\n", separator + 1);
        }
    }

    output_cleanup();
    return 0;
}
