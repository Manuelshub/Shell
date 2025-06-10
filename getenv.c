#include "shell.h"

extern char **environ;

char *_getenv(const char *name) {
    int i, len;
    
    if (!name)
        return (NULL);
    i = 0;
    len = _strlen(name);
    while (environ[i]) {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=') {
            return (environ[i] + len + 1);
        }
        i++;
    }

    return (NULL);
}
