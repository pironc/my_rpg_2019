/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_nbrlen.c
*/

#include "proto.h"
#include "rpg.h"

int my_nbrlen(int nb)
{
    int cpt = 1;
    while (nb > 9) {
        nb /= 10;
        cpt++;
    }
    return (cpt);
}