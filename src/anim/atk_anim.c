/*
** EPITECH PROJECT, 2020
** attack animations
** File description:
** functions hanling attack animations
*/

#include "proto.h"
#include "rpg.h"

void enemy_charge_forward(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    game.oof =\
sfSoundBuffer_createFromFile("ressources/Audio/attacks/Roblox.wav");
    game.oof_sound = sfSound_create();
    sfVector2f enemy_pos = {1500, 320};

    while (enemy_pos.x > 1350) {
        enemy_pos.x -= 20;
        sfSprite_setPosition(enemy->spr, enemy_pos);
        draw_combat(window, game, enemy);
        sfRenderWindow_display(window);
    }
    sfSound_setBuffer(game.oof_sound, game.oof);
    sfSound_setVolume(game.oof_sound, 5);
    sfSound_play(game.oof_sound);
    while (enemy_pos.x < 1500) {
        enemy_pos.x += 5;
        sfSprite_setPosition(enemy->spr, enemy_pos);
        draw_combat(window, game, enemy);
        sfRenderWindow_display(window);
    }
}

void perso_charge_forward(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    game.slash =\
sfSoundBuffer_createFromFile("ressources/Audio/attacks/sword.ogg");
    game.slash_sound = sfSound_create();
    sfVector2f char_pos = {50, 320};

    while (char_pos.x < 200) {
        char_pos.x += 20;
        sfSprite_setPosition(game.perso->spr, char_pos);
        draw_combat(window, game, enemy);
        sfRenderWindow_display(window);
    }
    sfSound_setBuffer(game.slash_sound, game.slash);
    sfSound_setVolume(game.slash_sound, 40);
    sfSound_play(game.slash_sound);
    dmg_anim(window, game, enemy, char_pos);
}

void animation_atk(sfRenderWindow *window, game_t game, \
enemy_t *enemy, sfSprite *spr)
{
    sfVector2f char_pos = {200, 320};
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

void dmg_anim(sfRenderWindow *window, game_t game, \
enemy_t *enemy, sfVector2f char_pos)
{
    sfVector2f anim_pos = {1490, 310};
    sfSprite *spr = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile\
    ("ressources/combat_bg/anim/base_atk_anim.png", NULL);
    sfSprite_setTexture(spr, text, sfTrue);
    sfSprite_setPosition(spr, anim_pos);

    animation_atk(window, game, enemy, spr);
}