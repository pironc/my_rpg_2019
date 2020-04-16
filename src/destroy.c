/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy elemnts when changing scenes
*/

#include "../include/rpg.h"

void destroy_menu(game_t game)
{
    sfSprite_destroy(game.scenes[0].gm_objcts[0].spr);
    sfTexture_destroy(game.scenes[0].gm_objcts[0].text);
    for (int i = 0; i != 3; i++) {
        sfSprite_destroy(game.scenes[0].buttons[i].spr);
        sfTexture_destroy(game.scenes[0].buttons[i].text);
    }
}