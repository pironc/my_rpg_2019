/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_menu.c
*/
#include "proto.h"
#include "rpg.h"

void display_menu(game_t *game, sfRenderWindow *window)
{
    button_t button;

    int i = 0;
    sfRenderWindow_drawSprite(window, button.spr, NULL);
    while (&game->scenes[0].buttons[i] != NULL) {
        sfRenderTexture_drawRectangleShape(window, &game->scenes->buttons[i].rect, NULL);
        i++;
    }
}