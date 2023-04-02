/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** by nfoxx56
*/

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "foxx.h"
#include "aim.h"

int my_waitpid(pid_t pid)
{
    int status = 0;
    waitpid(pid, &status, 0);
    if (!WIFEXITED(status)) {
        if (WTERMSIG(status) != 8) pastor(strsignal(WTERMSIG(status)));
        if (WTERMSIG(status) == 8) pastor("Floating exception");
        if (WCOREDUMP(status) == 128) pastor(" (core dumped)");
        pastor("\n");
    } return (0);
}

void gen(foxx_t *foxx, char *path)
{
    if (execve(path, foxx->cur_cmd, foxx->env) == -1) {
        pastor(foxx->cur_cmd[0]);
        exit(1);
    }
}

int my_execve(foxx_t *foxx, char *path)
{
    pid_t pid;
    pid = fork();
    if (pid == -1) {
        pastor("error with fork\n");
    } else if (!pid) {
        gen(foxx, path);
    } else {
        my_waitpid(pid);
    } return (1);
}
