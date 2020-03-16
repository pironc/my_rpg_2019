/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/

char my_putchar(char c);

char *my_revstr(char *str)
{
    int len = 11;
    char *tmp = 0;

    while (len != 0) {
        tmp[len] = str[len];
        len--;
    }
    str = tmp;
    return (str);
}

void main(void)
{
    my_revstr("hello world");
}