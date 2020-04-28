/*
** EPITECH PROJECT, 2020
** transition
** File description:
** fade in and out between scenes and other transitions
*/
#include "proto.h"
#include "rpg.h"

/*sfUint8 fade_in(sfRenderWindow *window, game_t game)
{
    game.fade.active = 0;
    game.fade.timer = sfClock_getElapsedTime(game.fade.fade_clock);
    game.fade.seconds = game.fade.timer.microseconds / 1000000.000;
    if (game.fade.seconds > 0.8){
        if (game.fade.transparent.a < 255) {
            game.fade.transparent.a += 0.1;
            sfRectangleShape_setFillColor(game.fade.rect, game.fade.transparent);
            sfRenderWindow_drawRectangleShape(window, game.fade.rect, NULL);
            sfRenderWindow_display(window);
        }
        sfClock_restart(game.fade.fade_clock);
    }
    return(game.fade.transparent.a);
}*/

/*sfUint8 fade_out(sfRenderWindow *window, game_t game)
{
    game.fade.timer = sfClock_getElapsedTime(game.fade.fade_clock);
    game.fade.seconds = game.fade.timer.microseconds / 1000000.000;
    if (game.fade.seconds > 0.8) {
        if (game.fade.transparent.r > 0) {
            game.fade.transparent.a -= 0.1;
            sfRectangleShape_setFillColor(game.fade.rect, game.fade.transparent);
            sfRenderWindow_drawRectangleShape(window, game.fade.rect, NULL);
            sfRenderWindow_display(window);
        }
        sfClock_restart(game.fade.fade_clock);
    }
    return(game.fade.transparent.a);
}*/