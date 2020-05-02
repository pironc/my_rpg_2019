/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** nbr_str.c
*/
#include "proto.h"
#include "rpg.h"

char *nbr_str(int nb)
{
    int i = 0;
    int cpt = 1;
    char *number = malloc(sizeof(char) * (my_nbrlen(nb) + 1));

    if (!number) {
        return (NULL);
    }
    while (nb / cpt > 9) {
        cpt *= 10;
    }
    while (cpt != 1) {
        number[i] = nb / cpt + '0';
        nb %= cpt;
        cpt /= 10;
        i++;
    }
    number[i] = nb + '0';
    number[i + 1] = '\0';
    return (number);
}