#include "shell.h"

char *_getenv(const char *name) {
    int i, len;
    
    if (!name)
        return (NULL);
    i = 0;
    len = _strlen(name);
    while (__environ[i]) {
        if (strncmp(__environ[i], name, len) == 0 && __environ[i][len] == '=') {
            return (__environ[i] + len + 1);
        }
        i++;
    }

    return (NULL);
}
