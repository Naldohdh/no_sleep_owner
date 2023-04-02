/*
** EPITECH PROJECT, 2023
** foxxnni
** File description:
** by nfoxx56
*/

#include "foxx.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i]; i++) {
        dest[i] = src[i];
    } dest[i] = '\0';
    return (dest);
}
