/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my cd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "foxx.h"
#include "aim.h"

void change_pwd(foxx_t *foxx, int i)
{
    char *str = my_malloc(sizeof(char) * 1024);
    if (!getcwd(str, 1024)) return;
    if (foxx->env[i]) {
        free(foxx->env[i]);
    } else {
        foxx->env = realloc_tab(foxx->env, 1);
    } foxx->env[i] = my_malloc(sizeof(char) * (my_strlen(str) + 5));
    foxx->env[i] = my_strcpy(foxx->env[i], "PWD=");
    foxx->env[i] = my_strcat(foxx->env[i], str); free(str);
}

void change_oldpwd(foxx_t *foxx)
{
    int i = 0; int j = 0;
    for (; foxx->env[i] && my_strncmp(foxx->env[i], "PWD", 3); i++);
    for (; foxx->env[j] && my_strncmp(foxx->env[j], "OLDPWD", 6); j++);
    if (!foxx->env[i]) {
        change_pwd(foxx, i);
        return;
    } if (foxx->env[j]) {
        free(foxx->env[j]);
    } else {
        foxx->env = realloc_tab(foxx->env, 1);
    } foxx->env[j] = my_malloc(sizeof(char) * (my_strlen(foxx->env[i]) + 4));
    foxx->env[j] = my_strcpy(foxx->env[j], "OLD");
    foxx->env[j] = my_strcat(foxx->env[j], foxx->env[i]); change_pwd(foxx, i);
}

void check_dir(foxx_t *foxx)
{
    struct stat st;
    if (chdir(foxx->cur_cmd[1]) != -1) return;
    pastor(foxx->cur_cmd[1]);
    if (lstat(foxx->cur_cmd[1], &st) != -1
        && (st.st_mode & S_IFMT) != S_IFDIR) {
        pastor(": Not a directory.\n");
    } else {
        pastor(": No such file or directory.\n");
    }
}

void con(foxx_t *foxx)
{
    if (chdir(get_from_env(foxx, "OLDPWD")) == -1) {
        pastor(": No such file or directory.\n");
    }
}

bool my_cd(foxx_t *foxx)
{
    if (foxx->cur_cmd[2]) {
        pastor("cd: Too many arguments.\n");
        return (true);
    } if (!foxx->cur_cmd[1] || !my_strcmp(foxx->cur_cmd[1], "~")) {
        if (chdir(get_from_env(foxx, "HOME")) == -1) {
            pastor("cd: No HOME in env.\n");
        }
    } else if (!my_strcmp(foxx->cur_cmd[1], "-")) {
        con(foxx);
    } else {
        check_dir(foxx);
    } change_oldpwd(foxx);
    return (true);
}
