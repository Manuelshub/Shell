#include "shell.h"

void execute_external(char **str) {
    pid_t pr;
    int status;
    char *resolved_path = NULL, *main_command = str[0];
    
    resolved_path = handle_external_command(str[0], "PATH");
    if (resolved_path != NULL) {
        /* Double check if the filepath exists */
        if (file_exists(resolved_path) != 0) {
            fprintf(stderr, "%s: command not found\n", main_command);
            free(resolved_path);
            return;
        }
        pr = fork();
        if (pr < 0) {
            perror("fork");
            free(resolved_path);
            return;
        }
        if (pr == 0) {
            /* Child process */
            if (execve(resolved_path, str, NULL) == -1) {
                perror(resolved_path);
                _exit(1);
            }
        }
        else
            wait(&status);

        free(resolved_path);
    }
    else
        fprintf(stderr, "%s: command not found\n", main_command);
}

char *handle_external_command(const char *command, const char *env) {
    char *path_env, *dup_s, *token, *delim = ":";
    char *full_path = NULL;
    int path_len, cmd_len;

    if (!env || !command)
        return (NULL);
    
    path_env = _getenv(env);
    if (!path_env)
        return (NULL);

    dup_s = strdup(path_env);

    /* Check if the command is a path to an executable */
    if (file_exists(command) == 0) {
        free(dup_s);
        return (strdup(command));
    }
    token = strtok(dup_s, delim);
    while (token) {
        path_len = _strlen(token);
        cmd_len = _strlen(command);

        full_path = malloc(sizeof(char) * (path_len + cmd_len + 2));
        if (!full_path) {
            free(dup_s);
            return (NULL);
        }

        strcpy(full_path, token);
        full_path[path_len] = '/';
        strcpy(full_path + path_len + 1, command);
        full_path[path_len + cmd_len + 1] = '\0';

        /* Check if the file exists and is executable */
        if (file_exists(full_path) == 0) {
            break;
        }
        /* Not this path */
        free(full_path);
        full_path = NULL;
        token = strtok(NULL, delim);
    }
    
    free(dup_s);
    return (full_path);
}
