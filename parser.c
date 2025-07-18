#include "shell.h"
#include <stdlib.h>

void print_prompt(char *s) {
    printf("%s ", s);
}

void read_input(char *s) {
    char *lineptr = NULL, **str = NULL;
    size_t n = 0;
    ssize_t n_read;
    int builtin_result, exit_stat = 0;

    while (1) {
        print_prompt(s);

        n_read = getline(&lineptr, &n, stdin);
        if (n_read == -1) {
            break;
        }
        lineptr[strcspn(lineptr, "\n")] = '\0';
        str = tokenize_line(lineptr);
        if (str == NULL || str[0] == NULL) {
            free_tokens(str);
            continue;
        }
        builtin_result = handle_builtins(str, &exit_stat);
        if (builtin_result == 1) {
            free_tokens(str);
            continue;
        }
        else if (builtin_result == -1) {
            free_tokens(str);
            break;
        }
        execute_external(str);

        free_tokens(str);
    }
    free(lineptr);
    exit(exit_stat);
}

int handle_builtins(char **args, int *stat) {
    builtin_t builtins[] = {
        {"exit", builtin_exit},
        {"env", builtin_env},
        {"setenv", builtin_setenv},
        {"unsetenv", builtin_unsetenv},
        {"cd", builtin_cd},
    };
    int num_builtins, i;

    if (args == NULL || args[0] == NULL)
        return (0);
    
    num_builtins = sizeof(builtins) / sizeof(builtin_t);
    for (i = 0; i < num_builtins; i++) {
        if (strcmp(args[0], builtins[i].name) == 0) {
            return (builtins[i].func(args, stat));
        }
    }
    return (0);
}
