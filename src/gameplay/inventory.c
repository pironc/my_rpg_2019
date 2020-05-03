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
    for (i = 0; i != 7; i++) {
        sfRenderWindow_drawText(window, perso->invent.stats[i], NULL);
    }
    sfRenderWindow_display(window);
}

void set_inventory_text(perso_t *perso)
{
    sfFont *font = sfFont_createFromFile("ressources/Minecraft.ttf");
    sfVector2f hp_pos = {1090, 155};
    sfVector2f max_hp_pos = {1200, 155};
    sfVector2f atk_pos = {1100, 228};
    sfVector2f armor_pos = {1100, 300};
    sfVector2f exp_pos = {1100, 375};
    sfVector2f max_exp_pos = {1220, 375};
    sfVector2f lvl_pos = {1100, 455};

    sfText_setString(perso->invent.stats[0], nbr_str(perso->hp));
    sfText_setString(perso->invent.stats[1], nbr_str(perso->max_hp));
    sfText_setString(perso->invent.stats[2], nbr_str(perso->attack));
    sfText_setString(perso->invent.stats[3], nbr_str(perso->armor));
    sfText_setString(perso->invent.stats[4], nbr_str(perso->exp));
    sfText_setString(perso->invent.stats[5], nbr_str(perso->max_exp));
    sfText_setString(perso->invent.stats[6], nbr_str(perso->level));
    sfText_setPosition(perso->invent.stats[0], hp_pos);
    sfText_setPosition(perso->invent.stats[1], max_hp_pos);
    sfText_setPosition(perso->invent.stats[2], atk_pos);
    sfText_setPosition(perso->invent.stats[3], armor_pos);
    sfText_setPosition(perso->invent.stats[4], exp_pos);
    sfText_setPosition(perso->invent.stats[5], max_exp_pos);
    sfText_setPosition(perso->invent.stats[6], lvl_pos);
    for (int i = 0; i != 7; i++) {
        sfText_setFont(perso->invent.stats[i], font);
        sfText_setCharacterSize(perso->invent.stats[i], 40);
        sfText_setOutlineThickness(perso->invent.stats[i], 2);
    }
}

void set_inventory(perso_t *perso)
{
    sfVector2f hp_bar_pos = {580, 160};
    sfVector2f hp_bar_scale = {0.5, 0.8};
    float angle = 90;

    set_inventory_text(perso);
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