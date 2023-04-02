/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** setenv
*/

#include <stdlib.h>
#include "foxx.h"
#include "aim.h"

char *get_line_env(foxx_t *foxx)
{
    char *line = my_malloc(sizeof(char)*(my_strlen(foxx->cur_cmd[1])
    + my_strlen(foxx->cur_cmd[2]) + 3));
    line = my_strcpy(line, foxx->cur_cmd[1]);
    line[my_strlen(foxx->cur_cmd[1])] = '=';
    line[my_strlen(foxx->cur_cmd[1]) + 1] = '\0';
    line = my_strcat(line, foxx->cur_cmd[2]);
    return (line);
}

bool my_setenv(foxx_t *foxx)
{
    int i = 0;
    char *line = get_line_env(foxx);
    for (; foxx->env[i]; i++) {
        if (!my_strncmp(
    foxx->env[i], foxx->cur_cmd[1], my_strlen(foxx->cur_cmd[1]))
            && foxx->env[i][my_strlen(foxx->cur_cmd[1])] == '=') {
            free(foxx->env[i]);
            foxx->env[i] = line;
            return (true);
        }
    } foxx->env = realloc_tab(foxx->env, 1);
    foxx->env[i] = line;
    return (true);
}

int check_setenv(foxx_t *foxx, int i)
{
    if ((foxx->cur_cmd[1][i] > '9' && foxx->cur_cmd[1][i] < 'A')
        || (foxx->cur_cmd[1][i] > 'Z' && foxx->cur_cmd[1][i] < 'a')
        || (foxx->cur_cmd[1][i] > 'z' && foxx->cur_cmd[1][i] < '0')) {
        if (i == 0) {
            pastor("add a letter.\n");
            return (1);
        } else {
            pastor("add alphanumeric char.\n");
            return (1);
        }
    } return (0);
}

bool hub_setenv(foxx_t *foxx)
{
    if (!foxx->cur_cmd[1]) return (my_print_env(foxx));
    if (foxx->cur_cmd[2] && foxx->cur_cmd[3]) {
        pastor("setenv: Too many arguments.\n");
        return (true);
    } for (int i = 0; foxx->cur_cmd[1][i]; i++) {
        if (check_setenv(foxx, i) == 1) return (true);
    } return (my_setenv(foxx));
}
