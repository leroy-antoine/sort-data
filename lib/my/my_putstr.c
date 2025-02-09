/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** zzz
*/
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    unsigned long len = 0;

    if (str == NULL)
        return 84;
    len = my_strlen(str);
    write(1, str, len);
    return 0;
}
