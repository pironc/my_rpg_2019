/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** my_print_revalpha
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (char c = 'z'; c >= 'a'; --c){
        my_putchar(c);
    }
}
