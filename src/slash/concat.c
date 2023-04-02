/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** by nfoxx56
*/

#include "foxx.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    for (; dest[i]; i++);
    if (src) {
        for (int j = 0; src[j]; j++) {
            dest[i] = src[j];
            i++;
        }
    } dest[i] = '\0';
    return (dest);
}
