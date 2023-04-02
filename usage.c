/*
** EPITECH PROJECT, 2022
** usage.c
** File description:
** usage
*/

#include <stdlib.h>
#include <stdio.h>

int my_H()
{
    printf("USAGE\n"
           "\t./103cipher message key flag\n"
           "DESCRIPTION\n"
           "message\ta message, made of ASCII characters\n"
           "key\tthe encryption key, made of ASCII characters\n"
           "flag\t0 for the message to be encrypted, 1 to be decrypted\n");
    return 0;
}
