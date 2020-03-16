/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** File that displays a number
*/

char my_putchar(char c);

int my_putstr(char const *str);

int my_getnbr(char const *str);

int my_put_nbr(int nb)
{
    int result = 0;
    int num = nb;

    if (num < 0) {
        my_putchar('-');
        num = (nb * (-1));
    }
    if (num > 9) {
        my_put_nbr(num / 10);
        my_putchar(num % 10 + '0');
    } else {
        my_putchar(num + '0');
    }
}