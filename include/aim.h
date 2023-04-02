/*
** EPITECH PROJECT, 2019
** mysh.h
** File description:
** mysh.h
*/

#ifndef AIM_H_
    #define AIM_H_
    #define nine __attribute__((unused))
    #include <stdbool.h>

typedef struct foxx {
    char **env;
    char ***commands;
    char **parse_cmd;
    char **cur_cmd;
    int pipe;
} foxx_t;

int my_strlen(char const *str);
void my_putchar(char c);
void mini_printf(const char *format, ...);
void change_pwd(foxx_t *foxx, int i);
void get_commands(foxx_t *foxx);
char *get_from_env(foxx_t *foxx, char *str);
char *get_input(void);
bool hub_setenv(foxx_t *foxx);
char **input_to_command(char *str);
void minishell(foxx_t *foxx);
bool my_cd(foxx_t *foxx);
bool my_commands(foxx_t *foxx);
int my_execve(foxx_t *foxx, char *path);
int my_exec_binary(foxx_t *foxx);
int my_exec_path(foxx_t *foxx);
bool my_print_env(foxx_t *foxx);
bool my_unsetenv(foxx_t *foxx);
void check_commands(foxx_t *mysh);
int check_manipulations(foxx_t *foxx);
int redirect_out(foxx_t *foxx, char *file, int i);
int redirect_in(foxx_t *foxx, char *file, int i);
int my_pipe(foxx_t *foxx, int i);

#endif
