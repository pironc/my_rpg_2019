/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int num = 0;
    while (str[num] != '\0') {
        my_putchar(str[num]);
        num++;
    }
}
