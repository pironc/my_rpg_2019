/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy elemnts when changing scenes
*/
#include "proto.h"
#include "rpg.h"

void destroy_menu(game_t game)
{
    sfSprite_destroy(game.scenes[0].gm_objcts[0].spr);
    sfTexture_destroy(game.scenes[0].gm_objcts[0].text);
    for (int i = 0; i != 3; i++) {
        sfSprite_destroy(game.scenes[0].buttons[i].spr);
        sfTexture_destroy(game.scenes[0].buttons[i].text);
    }
}

void destroy_perso(perso_t *perso)
{
    sfSprite_destroy(perso->spr);
    sfTexture_destroy(perso->text);
    for (int i = 0; perso->invent.objcts[i]; i++) {
        sfSprite_destroy(perso->invent.objcts[i]->spr);
        sfTexture_destroy(perso->invent.objcts[i]->text);
        free(perso->invent.objcts[i]);
    }
    for (int i = 0; perso->all_abili[i]; i++) {
        free(perso->all_abili[i]);
    }
}

void destroy_enemy(enemy_t *enemy)
{
    sfRectangleShape_destroy(enemy->hp_bar.rect);
    sfTexture_destroy(enemy->hp_bar.hp_bar_text);
    sfSprite_destroy(enemy->hp_bar.hp_bar_spr);
    sfTexture_destroy(enemy->text);
    sfSprite_destroy(enemy->spr);
}

void destroy_map(maps_t *map)
{
    for (int i = 0; map->maps[i]; i++) {
        for (int j = 0; map->maps[i][j]; j++)
            free(map->maps[i][j]);
    }
}