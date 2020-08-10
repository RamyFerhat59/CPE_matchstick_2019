#include "my.h"

int my_put_nbr_base(long long nb, char *base)
{
    int a;
    int len_str;

    if (nb == -2147483648)
        return (nb);
    if (nb < 0)
    {
        my_putchar('-');
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
