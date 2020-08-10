#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stddef.h>


void free_map(int size, char **map);
char **alloc_map(int size);
char **create_map(int size);
void print_map(int size, char **map);
int my_getnbr(char const *str);
void my_putchar(char c);
int IsValidNumber(char *string);
int my_strlen(char const *str);
char **add_match(int size, char **map);
char **remove_match(int size, char **map, int line, int nbmatch);
int check_remove(int maxmatch, char **map, int size, int nbmatch, int line);
int game(int size, char **map, int maxmatch);
int myAtoi(char *str);
int handle_line(char **map, int size, int line);
char *remove_space(char *str);
void count_stick_per_line(char **map, int size);
int line_input (int nbline, int size, char *line);
int matche_input(char **map, int nbmatch, int nbline, int nbmaxmatch, char *line);
int check_win(char **tab);
int game2(char **tab, int size);
int player_turn(char **map, int size, int nbmaxmatch);
int my_put_nbr(int nb);
int my_put_nbr_base(long long nb, char *base);
int my_put_nbrbi_base(long long nb, char *base);
void my_printf(char *str, ...);
int binarybase(va_list print);
void traitement(int arg, va_list print);
void my_putstr(char const *str);
char *remove_space(char *str);
int IA(char **map, int size);
int check_line(int line, char **map, int nbmatch);



#endif /* !MY_H_ */
