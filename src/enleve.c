/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** unsetenv
*/

#include <stdlib.h>
#include "foxx.h"
#include "aim.h"

bool my_unsetenv(foxx_t *foxx)
{
    bool status = false;
    if (!foxx->cur_cmd[1]) {
        pastor("unsetenv: Too few arguments.\n");
        return (true);
    } for (int i = 0; foxx->env[i]; i++) {
        if (!my_strncmp(
    foxx->env[i], foxx->cur_cmd[1], my_strlen(foxx->cur_cmd[1]))
            && foxx->env[i][my_strlen(foxx->cur_cmd[1])] == '=') {
            free(foxx->env[i]);
            status = true;
        } if (status == true) foxx->env[i] = foxx->env[i + 1];
    } return (true);
}
