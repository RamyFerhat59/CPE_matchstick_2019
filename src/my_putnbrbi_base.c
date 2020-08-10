/*
** EPITECH PROJECT, 2019
** my_put
** File description:
** my_put
*/

#include "my.h"

int my_put_nbrbi_base(long long nb, char *base)
{
    int a;
    int len_str;

    if (nb < 0) {
        nb = nb * -1;
    }
    len_str = my_strlen(base);
    a = nb % len_str;
    nb = nb / len_str;
    if (nb > 0)
        my_put_nbr_base(nb, base);
    my_putchar(base[a]);
    return (nb);
}
