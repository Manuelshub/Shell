#ifndef SHELL_H
#define SHELL_H

void print_prompt(char *s);
void read_input(char *s);
char **tokenize_line(char *s);
void free_tokens(char **tokens);
void execute_external(char **str);
char *handle_external_command(const char *command, const char *env);
/**
 * path_node - This structure store the each file path from my PATH environment
 * var in a singly linked list.
 *
 * s: The filepath
 * next: The pointer to the next node.
 */
typedef struct path_node {
    const char *filepath;
    struct path_node *next;
} path_node_t;

/* Linked list functions */
void print_list(path_node_t *head);
path_node_t *create_node(const char *filepath);
path_node_t *add_path(path_node_t **head, const char *filepath);

/* Helper functions */
int _strlen(const char *s);
int file_exists(const char *filename);
char *_getenv(const char *name);

/*
 * Standard library headers
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#endif /* shell.h */
