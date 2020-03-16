/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr
*/

char my_putchar(char c);

int my_getnbr(char const *str)
{
    int i = 0;
    int res = 0;

    if (str[0] == '-')
        my_putchar('-');
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            res = res * 10 + (str[i] - 48);
            i++;
        } else {
            i++;
        }
    }
    return (res);
}
