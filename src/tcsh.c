/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** by nfoxx56
*/

#include <signal.h>
#include <stdlib.h>
#include "foxx.h"
#include "aim.h"


void check_commands(foxx_t *foxx)
{
    if (check_manipulations(foxx)) return;
    if (my_commands(foxx) == false) {
        if (my_exec_binary(foxx) == false) my_exec_path(foxx);
    }
}

int check_manipulations(foxx_t *foxx)
{
    int i = 0;
    for (; foxx->cur_cmd[i]; i++);
    for (i -= 1; i >= 0; i--) {
        if (!my_strcmp(foxx->cur_cmd[i], ">")) {
            return (redirect_out(foxx, foxx->cur_cmd[i + 1], i));
        } if (!my_strcmp(foxx->cur_cmd[i], "<")) {
            return (redirect_in(foxx, foxx->cur_cmd[i + 1], i));
        } if (!my_strcmp(foxx->cur_cmd[i], "|")) {
            return (my_pipe(foxx, i));
        }
    } return (0);
}

void minishell(foxx_t *foxx)
{
    while (1) {
        mini_printf("$> ");
        signal(SIGINT, SIG_IGN);
        get_commands(foxx);
        for (int i = 0; foxx->commands[i]; i++) {
            foxx->pipe = 0;
            foxx->parse_cmd = foxx->commands[i];
            foxx->cur_cmd = foxx->commands[i];
            check_commands(foxx);
            free_tab(foxx->cur_cmd);
        } free(foxx->commands);
    }
}
