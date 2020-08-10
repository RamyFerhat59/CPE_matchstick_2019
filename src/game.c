#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int game(int size, char **map, int nbmaxmatch)
{
    int win = 0;
    int loose = 0;
    while (check_win(map) == 0) {
        my_printf("Your turn:\n");
        if (player_turn(map, size, nbmaxmatch) == 1) {
            return (0);
        }
        print_map(size, map);
        if (check_win(map) == 1) {
            my_printf("You lost, too bad...\n");
            return (2);
        }
        my_printf("\n");
        my_printf("AI's turn...\n");
        IA(map, size);
        print_map(size, map);
         if (check_win(map) == 1) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
           return (1);
        }
        my_printf("\n");
    }
    return (check_win(map));
}

int check_win(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        j = 0;
        for(; map[i][j] != '\0'; j++)
        if (map[i][j] == '|') {
            return (0);
        }
        i++;
    }
    return (1);
}

int IA(char **map, int size)
{
    int i = 1;

    for (; i <= size; i++) {
        if(check_line(i, map, 1) == 0) {
            remove_match(size, map, i, 1);
            my_printf("AI removed %d match(es) from line %d\n", 1, i);
            return (0);
        }
    }
    return (1);

} 

int check_line(int line, char **map, int nbmatch)
{
    int i = 0;
    int count = 0;

    for (; map[line][i] != '\0'; i++) {
        if (map[line][i] == '|')
            count++;
        
    }
    if (nbmatch <= count) {
        return (0);
    }
    return (1);
}

char *remove_space(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
         i += 1;
    }
    i -= 1;
    str[i] = '\0';
    return (str);

}

int player_turn(char **map, int size, int nbmaxmatch)
{
    size_t characters = 0;
    size_t characters2 = 0;
    ssize_t charead = 0;
    ssize_t charead2 = 0;
    char *line_index = NULL;
    char *nbmatch = NULL;

    my_putstr("Line: ");
    charead = getline(&line_index, &characters, stdin);
    line_index = remove_space(line_index);
    if (charead == -1){
        return (1);
    }
    while (line_input(my_getnbr(line_index), size, line_index) == 1) {
        my_putstr("Line: ");
        charead = getline(&line_index, &characters, stdin);
        line_index = remove_space(line_index);
        if (charead == -1) {
            return (1);
        }
    }
    my_putstr("Matches: ");
    charead2 = getline(&nbmatch, &characters2, stdin);
    nbmatch = remove_space(nbmatch);
    if (charead2 == -1) {
        return (1);
    }
    while (matche_input(map, my_getnbr(nbmatch), my_getnbr(line_index), nbmaxmatch, nbmatch) == 1) {
        player_turn(map, size, nbmaxmatch);
    }
    remove_match(size, map, my_getnbr(line_index), my_getnbr(nbmatch));
    printf("Player removed %d match(es) from line %s\n", my_getnbr(nbmatch), line_index);
    return (0);
}