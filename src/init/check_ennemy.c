/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** check_ennemy.c
*/

#include "rpg.h"
#include "proto.h"

void check_enemy(enemy_t **enemies)
{
    for (int i = 0; i < 3; i++) {
        printf("Enemy %d :\nName : %s\nHP : %d\nAttack : %d\n", i, \
enemies[i]->name, enemies[i]->hp, enemies[i]->attack);
        printf("Giv xp : %d\n", enemies[i]->giv_xp);
    }
}