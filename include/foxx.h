/*
** EPITECH PROJECT, 2019
** my_utils.h
** File description:
** my_utils.h
*/

#ifndef MY_FOXX_H_
    #define MY_FOXX_H_
    #include <stddef.h>

int my_strlen(char const *str);
void my_putchar(char c);
void mini_printf(const char *format, ...);
char **cpy_tab(char **tab);
void free_tab(char **tab);
int my_atoi(char const *str);
void *my_malloc(size_t size);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str, char c);
void pastor(char const *str);
char **realloc_tab(char **tab, int lines);
char **remove_str_from_tab(char **tab, int i);

#endif
