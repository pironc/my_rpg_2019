/*
** EPITECH PROJECT, 2020
** attack animations
** File description:
** functions hanling attack animations
*/

#include "proto.h"
#include "rpg.h"

void base_atk_anim(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    sfVector2f anim_pos = {1500, 320};
    sfSprite *spr = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile\
    ("ressources/combat_bg/anim/base_atk_anim.png", NULL);
    sfSprite_setTexture(spr, text, sfTrue);
    sfSprite_setPosition(spr, anim_pos);
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 256;
    rect.height = 256;

    while (rect.top != 2048 && rect.left != 2048) {
        for (int i = 0; i != 8; i++) {
            move_rect(&rect, 256, 2048);
            sfSprite_setTextureRect(spr, rect);
            sfRenderWindow_drawSprite(window, spr, NULL);
            sfRenderWindow_display(window);
        }
        rect.top += 256;
    }
}