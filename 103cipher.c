/*
** EPITECH PROJECT, 2022
** 103cipher
** File description:
** 103cipher
*/

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char my_H();

char *mat(char *str0, char *str)
{
    int i = 0 , t = 0 , g = 0;
    int a , b = 0, d = 0;
    int x = 0, y = 0, z = 0;
    while (str[a] != '\0') {
        a++; b++;
    }
    char *key = malloc(sizeof(char) * 16); 
    while (str[x] != '\0') {
        key[y] = str[x];
        x++; y++;
    }
    printf("Key matrix:\n");
    if (b == 1)
        printf("%d\n", key[0]);
    if (b == 2 || b == 3 || b == 4)
        printf("%d\t%d\n%d\t%d\n",key[0], key[1],key[2],key[3]);
    if(b >= 5 && b <= 9)
        printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",
               key[0],key[1],key[2],key[3],key[4],key[5],key[6],key[7],key[8]);

    if(b >=10)
        printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n",
               key[0],key[1],key[2],key[3],key[4],key[5],key[6],key[7],
               key[8],key[9],key[10],key[11],key[12],key[13],key[14],key[15]);
    printf("\n");

    printf("Encrypted message:\n");
    for(; str0[i] != '\0';i++) {
        d++;
    } 

    char *tab = malloc(sizeof(char) * d);
    while (str0[z] != '\0') {
        tab[t] = str0[z];
        t++; z++;
    }
   
    while(g < d) {
        printf("%d ", ((tab[g] * key[0]) + (tab[g + 1] * key[3]) + (tab[g + 2] * key[6])));
        printf("%d ", ((tab[g] * key[1]) + (tab[g + 1] * key[4]) + (tab[g + 2] * key[7])));
        printf("%d ", ((tab[g] * key[2]) + (tab[g + 1] * key[5]) + (tab[g + 2]*key[8])));
        g += 3;
    }
    printf ("\n");
     return key;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            return my_H();
        }
    }
    if (ac == 4 && atof(av[3]) == 0) {
        char *cipher = mat(av[1], av[2]);
        free(cipher);
    }     
    else
        return 84;
    return 0;
}
