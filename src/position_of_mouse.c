/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** position_of_mouse.c
*/
#include "proto.h"
#include "rpg.h"

int position_of_back(sfRenderWindow *window, game_t game)
{
    button_t button;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    button.pos_play = sfSprite_getPosition(game.scenes[2].buttons[0].spr);
    int verif_height = 0;
    int verif_width = 0;
    if (mouse.x >= button.pos_play.x && mouse.x <= (button.pos_play.x + 372))
        verif_width = 1;
    if (mouse.y >= button.pos_play.y && mouse.y <= (button.pos_play.y + 803))
        verif_height = 1;
    return (verif_height * verif_width);
}

int position_of_exit(sfRenderWindow *window, game_t game)
{
    button_t button;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    button.pos_exit = sfSprite_getPosition(game.scenes[2].buttons[2].spr);
    int verif_height = 0;
    int verif_width = 0;
    if (mouse.x >= button.pos_exit.x && mouse.x <= (button.pos_exit.x + 305))
        verif_width = 1;
    if (mouse.y >= button.pos_exit.y && mouse.y <= (button.pos_exit.y + 803))
        verif_height = 1;
    return (verif_height * verif_width);
}