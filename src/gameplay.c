/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** gameplay
*/

#include "../include/rpg.h"

void gameplay(sfRenderWindow *window, game_t game, perso_t *perso)
{
    sfClock *clock = sfClock_create();
    float seconds;
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.000;
    if (game.cur_scn == 1) {
        sfRenderWindow_drawSprite(window, perso->spr, NULL);
    }
}