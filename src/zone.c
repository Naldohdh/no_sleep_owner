/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** by nfoxx56
*/

#include "foxx.h"
#include "aim.h"

char *get_from_env(foxx_t *foxx, char *str)
{
    char *dest = NULL; int i = 0;
    for (; foxx->env[i]; i++) {
        if (!my_strncmp(foxx->env[i], str, my_strlen(str))) break;
    } if (!foxx->env[i]) return (NULL);
    dest = my_malloc(sizeof(char) * (my_strlen(foxx->env[i]) + 1));
    dest = my_strcpy(dest, foxx->env[i]);
    for (; *dest != '='; dest++);
    return (dest + 1);
}
