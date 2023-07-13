#include <stdio.h>
#include <string.h>

extern char **environ;

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    for (char **env = environ; *env != NULL; env++) {
        char *separator = strchr(*env, '=');
        if (separator != NULL) {
            printf("env[");
            fwrite(*env, 1, separator - *env, stdout);
            printf("]: %s\n", separator + 1);
        }
    }
    return 0;
}
