/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int fact = 1;
    int i;

    if (nb < 0 || nb > 12) {
        return (0);
    }
    else if (nb == 0) {
        return (1);
    }
    for (i = 1; i <= nb; i++) {
        fact = fact * i;
    }
    return fact;
}
