/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** my_compute_factorial_rec
*/

int my_compute_factorial_rec(int nb)
{
    int fact;

    if (nb < 0 || nb > 12) {
        return 0;
    }

    else if (nb == 0) {
        return 1;
    }

    fact = (my_compute_factorial_rec(nb - 1) * nb);
    return fact;
}
