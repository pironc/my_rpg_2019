/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** functions handling inventory management
*/

#include "proto.h"
#include "rpg.h"

void draw_inventory(sfRenderWindow *window, perso_t *perso)
{
    int i = 0;

    sfRenderWindow_drawSprite(window, perso->invent_spr, NULL);
    for (; i != perso->item_nbr; i++) {
        sfRenderWindow_drawSprite(window, perso->invent[i]->spr, NULL);
    }
    sfRenderWindow_display(window);
}

void open_inventory(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    while (1) {
        draw_inventory(window, game.perso);
    }
}