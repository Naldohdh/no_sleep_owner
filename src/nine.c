/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my commands
*/

#include <stdlib.h>
#include "foxx.h"
#include "aim.h"

void my_exit(foxx_t *foxx)
{
    mini_printf("exit\n");
    free_tab(foxx->env);
    if (!foxx->cur_cmd[1]) exit(0);
    exit(my_atoi(foxx->cur_cmd[1]));
}

bool my_print_env(foxx_t *foxx)
{
    for (int i = 0; foxx->env[i]; i++) {
        mini_printf("%s\n", foxx->env[i]);
    } return (true);
}

bool my_commands(foxx_t *foxx)
{
    if (!my_strcmp(foxx->cur_cmd[0], "exit")) my_exit(foxx);
    if (!my_strcmp(foxx->cur_cmd[0], "env")) return (my_print_env(foxx));
    if (!my_strcmp(foxx->cur_cmd[0], "unsetenv")) return (my_unsetenv(foxx));
    if (!my_strcmp(foxx->cur_cmd[0], "setenv")) return (hub_setenv(foxx));
    if (!my_strcmp(foxx->cur_cmd[0], "cd")) return (my_cd(foxx));
    return (false);
}
