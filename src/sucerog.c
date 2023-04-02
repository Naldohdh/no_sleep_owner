/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** pipe
*/

#include "aim.h"
#include "foxx.h"
#include <unistd.h>
#include <stdlib.h>

int suce(foxx_t *foxx, int fd[2], int save[2], int i)
{
    int j = 0;
    for (i += 1; foxx->cur_cmd[i]; i++) {
        foxx->cur_cmd[j] = foxx->cur_cmd[i];
        j++;
    } foxx->cur_cmd[j] = NULL;
    dup2(fd[0], STDIN_FILENO);
    check_commands(foxx);
    close(fd[0]);
    dup2(save[0], STDIN_FILENO);
    close(save[0]); return (1);
}

int my_pipe(foxx_t *foxx, int i)
{
    int save[2]; int fd[2];
    save[1] = dup(STDOUT_FILENO);
    save[0] = dup(STDIN_FILENO);
    if (foxx->cur_cmd[i + 1] == NULL) {
        pastor("Invalid null command.\n");
        return (84);
    } pipe(fd); dup2(fd[1], STDOUT_FILENO);
    foxx->cur_cmd[i] = NULL;
    check_commands(foxx);
    close(fd[1]);
    dup2(save[1], STDOUT_FILENO);
    close(save[1]);
    if (suce(foxx, fd, save, i) == -1) {
        return (84);
    } return (1);
}
