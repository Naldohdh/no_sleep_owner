/*
** EPITECH PROJECT, 2023
** aim
** File description:
** by nfoxx56
*/

#include <stdlib.h>
#include "foxx.h"

void *my_malloc(size_t size)
{
    void *data = malloc(size);
    if (!data) {
        pastor("Error! memory not allocated.\n");
        exit(84);
    } return (data);
}
