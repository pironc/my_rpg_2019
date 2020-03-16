/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** my_print_digits
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (char c = '0'; c <= '9'; ++c) {
        my_putchar(c);
    }
}
