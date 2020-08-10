#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char **alloc_map(int size)
{
    char **map;
    int i;

    map = malloc(sizeof(char *) * (size + 3));
    for (i = 0; i < (size + 2); i++) {
        map[i] = malloc(sizeof(char) * ((size * 2) + 2));
    }
    return map;
}

char **create_map(int size)
{
    char **map = alloc_map(size);
    int i;
    int j;
    for (i = 0; i < (size + 2); i++) {
        for (j = 0; j <= (size * 2); j++) {
            if (i == 0) {
                map[i][j] = '*';
            }
            else if (i > 0 && i < size + 2) {
                map[i][0] = '*';
                map[i][j] = ' ';
                map[i][(size * 2)] = '*';
            }
            if (i == size + 1) {
                map[i][j] = '*';
            }
        }
        map[i][j] = '\0';
    }
    map[i] = NULL;
    return map;
}

void free_map(int size, char **map)
{
    int i;

    for (i = 0; i < (size + 2); i++)
        free(map[i]);
    free(map);
}

void print_map(int size, char **map)
{
    int i;
    int j;

    for (i = 0; i < (size + 2); i++) {
        for (j = 0; j < (size * 2) + 1; j++) {
            my_putchar(map[i][j]);
        }
        my_putstr("\n");
    }
}

char **add_match(int size, char **map)
{
    int i; 
    int j;
    int k = 0;

    for (i = 1; i < (size + 1); i++) {
        j = size - k;
        for (j = (size - k); j < (size + k + 1); j++) {
            map[i][j] = '|';
        }
        k++;
    }
    return map;
}

char **remove_match(int size, char **map, int line, int nbmatch)
{
    int j = size * 2;
    int i = 0;
    
    while (nbmatch > 0) {
        if (map[line][j] == '|') {
             map[line][j] = ' ';
         nbmatch -= 1;
        }
        j--;
    }
    return (map);
}
