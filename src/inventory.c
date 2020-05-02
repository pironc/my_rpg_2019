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

    sfRenderWindow_drawSprite(window, perso->invent.invent_spr, NULL);
    sfRenderWindow_drawSprite(window, perso->invent.perso_spr, NULL);
    sfRenderWindow_drawSprite(window, perso->hp_bar.hp_bar_spr, NULL);
    sfRenderWindow_drawRectangleShape(window, perso->hp_bar.rect, NULL);
    for (; i != perso->item_nbr; i++) {
        sfRenderWindow_drawSprite(window, perso->invent.objcts[i]->spr, NULL);
    }
    sfRenderWindow_display(window);
}

void set_inventory(perso_t *perso)
{
    sfVector2f hp_bar_pos = {580, 160};
    sfVector2f hp_bar_scale = {0.5, 0.8};
    float angle = 90;
    sfText *hp = sfText_create();
    sfText_setString(hp, nbr_str(perso->hp));

    sfSprite_setPosition(perso->hp_bar.hp_bar_spr, hp_bar_pos);
    sfRectangleShape_setPosition(perso->hp_bar.rect, hp_bar_pos);
    sfSprite_setRotation(perso->hp_bar.hp_bar_spr, angle);
    sfRectangleShape_setRotation(perso->hp_bar.rect, angle);
    sfSprite_setScale(perso->hp_bar.hp_bar_spr, hp_bar_scale);
    sfRectangleShape_setScale(perso->hp_bar.rect, hp_bar_scale);
}

void open_inventory(sfRenderWindow *window, game_t game)
{
    int flag = 0;
    sfEvent close_event;
    set_inventory(game.perso);
    while (1) {
        draw_inventory(window, game.perso);
        flag = analyse_inventory_events(window, close_event, flag);
        if (flag == 1) {
            break;
        }
    }
}