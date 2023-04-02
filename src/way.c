/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** by nfoxx56
*/

#include <stdlib.h>
#include <unistd.h>
#include "foxx.h"
#include "aim.h"

char *get_path(char *path, char *cmd)
{
    int len = my_strlen(path);
    char *str = my_malloc(sizeof(char) * (len + my_strlen(cmd) + 2));
    str = my_strcpy(str, path);
    if (str[len - 1] != '/') {
        str[len] = '/';
        str[len + 1] = '\0';
    } str = my_strcat(str, cmd);
    return (str);
}

int my_exec_path(foxx_t *foxx)
{
    char *path = get_from_env(foxx, "PATH");
    char **paths = my_str_to_word_array(path, ':');
    char *str = NULL;
    if (!access(foxx->cur_cmd[0], X_OK)) {
        my_execve(foxx, foxx->cur_cmd[0]);
        return (1);
    } for (int i = 0; paths[i]; i++) {
        str = get_path(paths[i], foxx->cur_cmd[0]);
        if (!access(str, X_OK)) {
            my_execve(foxx, str);
            free(str);
            return (1);
        } free(str);
    } pastor(foxx->cur_cmd[0]);
    pastor(": Command not found.\n");
    return (1);
}
