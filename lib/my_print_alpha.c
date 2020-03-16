/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** File that writes the lowercase alphabet
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (char c = 'a'; c <= 'z'; c++) {
        my_putchar(c);
    }
}
