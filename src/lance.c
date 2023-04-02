/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** by nfoxx56
*/

#include "foxx.h"
#include "aim.h"

void create_env(foxx_t *foxx)
{
    foxx->env = my_malloc(sizeof(char *) * 12);
    foxx->env[0] = my_strdup("HOSTTYPE=x86_64-linux");
    foxx->env[1] = my_strdup("VENDOR=unknow");
    foxx->env[2] = my_strdup("OSTYPE=linux");
    foxx->env[3] = my_strdup("MATCHTYPE=x86_64");
    foxx->env[4] = my_strdup("SHLVL=1");
    foxx->env[5] = my_strdup("LOGNAME=nfoxx56");
    foxx->env[6] = my_strdup("USER=nfoxx56");
    foxx->env[7] = my_strdup("GROUP=nfoxx56");
    foxx->env[8] = my_strdup("HOST=localdomain");
    foxx->env[9] = my_strdup("HOME=/home/nfoxx56");
    foxx->env[10] =
        my_strdup("PATH=/home/nfoxx56/bin:/usr/local/bin:/usr/bin:/bin");
    foxx->env[11] = NULL;
    change_pwd(foxx, 11);
}

int main(int ac, char nine **av, char **env)
{
    foxx_t foxx;
    if (ac != 1) return (84);
    if (!env[0]) {
        create_env(&foxx);
    } else {
        foxx.env = cpy_tab(env);
    }
    minishell(&foxx);
    return (0);
}
