/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick game
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int main(int argc, char **argv)
{
    int size;
    char **map;
    int valid1;
    int valid2;
    int nbmatch;
    int gamestatus = 0;

    if (argc != 3) {
        write(2, "error\n", 7);
        return (84);
    }
    if ((valid1 = IsValidNumber(argv[1])) == 1) {
          write(2, "error size\n", 12);
          return (84);
    }
    if ((valid2 = IsValidNumber(argv[2])) == 1) {
          write(2, "error size\n", 12);
          return (84);
    }
    size = my_getnbr(argv[1]);
    nbmatch = my_getnbr(argv[2]);
    if (size < 1 || size > 99)
    {
        write(2, "error size\n", 12);
        return (84);
    }
    if (nbmatch < 1)
    {
        write(2, "error size\n", 12);
        return (84);
    }
    map = create_map(size);
    map = add_match(size, map);
    print_map(size, map);
    my_printf("\n");
    if ((gamestatus = game(size, map, nbmatch)) == 0){ 
        return (0);
    }
    free_map(size, map);
    return (game(size, map, nbmatch));
}

int IsValidNumber(char *string)
{
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] < '0' || string[i] > '9') {
            return (1);
        }
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return nb;   

}
