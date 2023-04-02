/*
** EPITECH PROJECT, 2023
** remove_on
** File description:
** by nfoxx56
*/

#include <stdlib.h>

char **remove_str_from_tab(char **tab, int i)
{
    int j = 0;
    for (; tab[j]; j++);
    if (j < i) {
        return (tab);
    } else {
        free(tab[i]);
    } for (; i < j; i++) {
        tab[i] = tab[i + 1];
    } tab[i] = NULL;
    return (tab);
}
