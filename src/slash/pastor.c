/*
** EPITECH PROJECT, 2023
** foxxx
** File description:
** by nfoxx56
*/

#include <unistd.h>
#include "foxx.h"

void pastor(char const *str)
{
    write(2, str, my_strlen(str));
}
