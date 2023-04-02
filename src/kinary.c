/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** by nfoxx56
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "foxx.h"
#include "aim.h"

int my_exec_binary(foxx_t *foxx)
{
    if (!access(foxx->cur_cmd[0], X_OK) && !opendir(foxx->cur_cmd[0])
        && foxx->cur_cmd[0][0] == '.' && foxx->cur_cmd[0][1] == '/') {
        return (my_execve(foxx, foxx->cur_cmd[0]));
    } else if (
        (foxx->cur_cmd[0][0] == '.' && foxx->cur_cmd[0][1] == '/')
        || (opendir(foxx->cur_cmd[0]) != 0)) {
        pastor(foxx->cur_cmd[0]);
        pastor(": Permission denied.\n");
        return (true);
    } return (false);
}
