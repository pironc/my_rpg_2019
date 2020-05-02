/*
** EPITECH PROJECT, 2020
** game over
** File description:
** game over game
*/

#include "proto.h"
#include "rpg.h"

void anim_game_over(sfRenderWindow *window, sfSprite *gm_ovr_spr, sfRectangleShape *bg, sfColor color)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    for (int i = 0; i != 300; i++) {
        if (i >= 200)
            sfRenderWindow_drawSprite(window, gm_ovr_spr, NULL);
    }
    sfRenderWindow_drawRectangleShape(window, bg, NULL);
    while (color.a < 255) {
        sfRenderWindow_display(window);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.000;
        if (seconds > 1) {
            color.a += 1;
            sfRectangleShape_setFillColor(bg ,color);
            sfRenderWindow_drawRectangleShape(window, bg, NULL);
        }
    }
}

void game_over(sfRenderWindow *window, perso_t *perso, game_t game, enemy_t *enemy)
{
    sfVector2f bg_size = {1920, 1080};
    sfVector2f gm_ovr_pos = {350, 400};
    sfVector2f perso_pos = {210, 335};
    sfSprite *gm_ovr_spr = sfSprite_create();
    sfTexture *gm_ovr_text = sfTexture_createFromFile("ressources/game_over.png", NULL);
    sfTexture *perso_text = sfTexture_createFromFile("ressources/perso_dead.png", NULL);
    sfColor color = sfColor_fromRGBA(0, 0, 0, 0);
    sfRectangleShape *bg = sfRectangleShape_create();

    sfSprite_setTexture(gm_ovr_spr, gm_ovr_text, sfTrue);
    sfSprite_setPosition(gm_ovr_spr, gm_ovr_pos);
    sfSprite_setRotation(perso->spr, 90);
    sfSprite_setPosition(perso->spr, perso_pos);
    sfRectangleShape_setSize(bg, bg_size);
    sfRectangleShape_setFillColor(bg, color);
    draw_combat(window, game, enemy);
    anim_game_over(window, gm_ovr_spr, bg, color);
    close_window(window);
}