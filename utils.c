#include "shell.h"

void free_tokens(char **tokens) {
    int i;
        
    if (!tokens)
        return;
    i = 0;
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

void print_list(path_node_t *head) {
    path_node_t *tmp;

    tmp = head;
    while (tmp) {
        printf("%s\n", tmp->filepath);
        tmp = tmp->next;
    }
}

int file_exists(const char *filename) {
    return (access(filename, X_OK));
}

int _strlen(const char *s) {
    int i;

    i = 0;
    while (s[i])
        i++;

    return (i);
}
