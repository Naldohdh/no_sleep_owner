/*
** EPITECH PROJECT, 2023
** strdunn
** File description:
** by nfoxx56
*/

#include "foxx.h"

char *my_strdup(char const *src)
{
    char *dest = my_malloc(sizeof(char) * (my_strlen(src) + 1));
    return (my_strcpy(dest, src));
}
