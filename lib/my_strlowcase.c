/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** my_strlowcase
*/

char my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
            my_putchar(str[i]);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return (str);
}

void main(void)
{
    my_putchar(my_strlowcase("a raNDom StRIng -Fzundq \\ ejznQJFN. fsF"));
}