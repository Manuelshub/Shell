#include "shell.h"

char **tokenize_line(char *s) {
    char **token;
    char *delim = " ", *s_dup, *recv;
    int i = 0, num_tokens = 0;

    s_dup = strdup(s);
    recv = strtok(s_dup, delim);
    while (recv != NULL) {
        num_tokens++;
        recv = strtok(NULL, delim);
    }
    free(s_dup);

    s_dup = strdup(s);
    token = malloc(sizeof(char *) * (num_tokens + 1));
    recv = strtok(s_dup, delim);
    while (recv != NULL) {
        token[i++] = strdup(recv);
        recv = strtok(NULL, delim);
    }
    token[i] = NULL;

    free(s_dup);
    return (token);
}
