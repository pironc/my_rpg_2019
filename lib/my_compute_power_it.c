/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** my_compute_power_it
*/

int my_compute_power_it(int nb, int p)
{
    int i;
    int result = 1;

    if (p == 0) {
        return (1);
    }
    else if (p < 0) {
        return (0);
    }
    for (i = 0; i < p; i++) {
        result = result * nb;
    }
    return result;
}
