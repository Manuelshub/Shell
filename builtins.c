#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int builtin_exit(char **args, int *exit_stat) {
    char *endptr;
    long status;

    if (args[1]) {
        status = strtol(args[1], &endptr, 10);

        if (*endptr != '\0' || status < 0 || status > 255) {
            fprintf(stderr, "exit: Illegal number: %s\n", args[1]);
            *exit_stat = 2;
        }
        else
            *exit_stat = (int)status;
    }
    else
        *exit_stat = 0;
    
    return (-1);
}

int builtin_env(char **args, int *exit_stat) {
    int i;
    (void)args, (void)exit_stat;

    for (i = 0; __environ[i]; i++)
        puts(__environ[i]);

    return (1);
}

int builtin_setenv(char **args, int *exit_stat) {
    int set_ret;
    (void)exit_stat;

    if (!args[1] || !args[2]) {
        fprintf(stderr, "Usage: setenv <VARIABLE> <VALUE>\n");
        return (1);
    }
    set_ret = setenv(args[1], args[2], 1);
    if (set_ret == -1) {
        perror("setenv");
        return (-1);
    }

    return (1);
}

int builtin_unsetenv(char **args, int *exit_stat) {
    int unset_ret;
    (void)exit_stat;

    if (!args[1]) {
        fprintf(stderr, "Usage: unsetenv <VARIABLE>\n");
        return (1);
    }
    unset_ret = unsetenv(args[1]);
    if (unset_ret == -1) {
        perror("unsetenv");
        return (-1);
    }
    return (1);
}

int builtin_cd(char **args, int *exit_stat) {
    char *home, buffer[BUFFER_SIZE], old[BUFFER_SIZE];
    int ch_ret;
    (void)exit_stat;

    getcwd(old, BUFFER_SIZE);
    if (!args[1] || strcmp(args[1], "~") == 0) {
        home = _getenv("HOME");
        if (chdir(home) == 0) {
            getcwd(buffer, BUFFER_SIZE);
            setenv("PWD", buffer, 1);
            setenv("OLDPWD", old, 1);
            return (1);
        }
    }
    ch_ret = chdir(args[1]);
    if (ch_ret == -1) {
        perror("cd");
        return (1);
    }
    getcwd(buffer, BUFFER_SIZE);
    setenv("PWD", buffer, 1);
    setenv("OLDPWD", old, 1);
    return (1);
}
