/*
** EPITECH PROJECT, 2020
** attack animations
** File description:
** functions hanling attack animations
*/

#include "proto.h"
#include "rpg.h"

void perso_charge_forward(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    sfVector2f char_pos = {50, 320};

    while (char_pos.x < 200) {
        char_pos.x += 20;
        sfSprite_setPosition(game.perso->spr, char_pos);
        draw_combat(window, game, enemy);
        sfRenderWindow_display(window);
    }
    dmg_anim(window, game, enemy, char_pos);
}

void dmg_anim(sfRenderWindow *window, game_t game, \
enemy_t *enemy, sfVector2f char_pos)
{
    sfVector2f anim_pos = {1490, 310};
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

    while (char_pos.x > 50 || rect.top != 2048 && rect.left != 2048) {
        for (int i = 0; i != 8; i++) {
            if (char_pos.x > 50) {
                char_pos.x -= 5;
                sfSprite_setPosition(game.perso->spr, char_pos);
                draw_combat(window, game, enemy);
            }
            move_rect(&rect, 256, 2048);
            sfSprite_setTextureRect(spr, rect);
            sfRenderWindow_drawSprite(window, spr, NULL);
            sfRenderWindow_display(window);
        }
        rect.top += 256;
    }
}