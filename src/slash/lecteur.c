/*
** EPITECH PROJECT, 2023
** strnini
** File description:
** by nfoxx56
*/

#include <stddef.h>
#include "foxx.h"
#include "aim.h"

int my_strlen(char const *str)
{
    int i = 0;
    if (!str) return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}
