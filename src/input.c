#include "my.h"

int line_input(int nbline, int size, char *line)
{   
    if(IsValidNumber(line) == 1) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (1);
    }
    else if(nbline > size || nbline <= 0 ) {
        write(1,"Error: this line is out of range\n", 34);
        return (1);
    }
   
    return (0);
}

int matche_input(char **map, int nbmatch, int nbline, int nbmaxmatch, char *line) 
{
    
    int count = 0;

    if(IsValidNumber(line) == 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (nbmatch == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (1);
    }
    if (nbmatch > nbmaxmatch) {
        my_printf("Error: you cannot remove more than %d matches per turn\n", nbmaxmatch);
        my_put_nbr(nbmaxmatch);
        return (1);
    }
    for(int j = 0; map[nbline][j] != '\0'; j++) {
        if (map[nbline][j] == '|') {
            count++;
        }
    }
    if (nbmatch > count) {
        my_printf("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}