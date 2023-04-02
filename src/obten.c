/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** by nfoxx56
*/

#include <stdlib.h>
#include "foxx.h"
#include "aim.h"
#include <stdio.h>

void fonct(size_t *tab, char *new_ptr, char *old_ptr, size_t *i)
{
    if ((*i) < tab[0]) {
        new_ptr[*i] = old_ptr[*i];
    } else {
        *i = tab[1];
    }
}

void *my_realloc(void *ptr, size_t size)
{
    size_t *tab = (size_t*)malloc(sizeof(size_t) * 2);
    if (size == 0) {
        free(ptr);
        return NULL;
    } char *new_ptr = malloc(size);
    if (!new_ptr) {
        pastor("Error: failed to reallocate memory\n");
        return NULL;
    } if (ptr) {
        char *old_ptr = (char *) ptr;
        tab[0] = sizeof(ptr); tab[1] = size;
        for (size_t i = 0; i < size; i++) {
            fonct(tab, new_ptr, old_ptr, &i);
        } free(ptr);
    } return new_ptr;
}

int fill_command(foxx_t *foxx, char **tab, int i, int index)
{
    int nb_words = 0;
    if (!tab[i] || !my_strcmp(tab[i], ";")) return -1;
    for (; tab[i + nb_words] && my_strcmp(tab[i + nb_words], ";"); nb_words++);
    foxx->commands[index] = my_malloc(sizeof(char *) * (nb_words + 1));
    for (int j = 0; j < nb_words; j++) {
        foxx->commands[index][j] = my_strdup(tab[i + j]);
    } foxx->commands[index][nb_words] = NULL;
    return (i + nb_words + 1);
}

void get_commands(foxx_t *foxx)
{
    char *input = get_input();  int j = 0;
    char **command = input_to_command(input); int nb_commands = 1;
    foxx->commands = my_malloc(sizeof(char **) * 2);
    for (int i = 0; command[i]; i++) {
        if (!my_strcmp(command[i], ";")) {
            nb_commands++;
        }
    } foxx->commands = my_realloc(foxx->commands,
    sizeof(char **) * (nb_commands + 1));
    for (int i = 0; i < nb_commands; i++) {
        j = fill_command(foxx, command, j, i);
        if (j == -1) {
            nb_commands = i; break;
        }
    } foxx->commands[nb_commands] = NULL;
    free(input); free_tab(command);
}
