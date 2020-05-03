/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_stats.c
*/

#include "proto.h"
#include "rpg.h"

abili_t *init_abi(float ratio, char *name)
{
    abili_t *abiliti = malloc(sizeof(abili_t) * 1);

    abiliti->ratio = ratio;
    abiliti->name = name;
}

void init_abilites(perso_t *perso)
{
    perso->all_abili[0] = init_abi(1.5, "abilitie1");
    perso->all_abili[1] = init_abi(2, "abilitie2");
    perso->all_abili[2] = NULL;
}

void init_perso_hp_bar(perso_t *perso)
{
    sfVector2f size = {0, 43};
    sfColor fill_color = sfColor_fromRGBA(0, 0, 0, 255);

    perso->hp_bar.rect = sfRectangleShape_create();
    perso->hp_bar.hp_bar_spr = sfSprite_create();
    perso->hp_bar.hp_bar_text = sfTexture_createFromFile\
    ("ressources/health_bar.png", NULL);
    sfSprite_setTexture(perso->hp_bar.hp_bar_spr, \
    perso->hp_bar.hp_bar_text, sfTrue);
    sfRectangleShape_setSize(perso->hp_bar.rect, size);
    sfRectangleShape_setFillColor(perso->hp_bar.rect, fill_color);
}