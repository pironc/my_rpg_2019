/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** gameplay
*/

#include "../include/rpg.h"

void reset_window(sfRenderWindow *window, game_t *game, perso_t *perso) 
{
    sfRenderWindow_clear(window, sfBlack);
    draw_elements(window, *game);
    sfRenderWindow_drawSprite(window, perso->spr, NULL);
    sfRenderWindow_display(window);
}

void gameplay(sfRenderWindow *window, game_t *game, perso_t *perso)
{
    sfClock *clock = sfClock_create();
    float seconds;
    sfEvent event;
    sfTime time;

    while (game->cur_scn == 1) {
        reset_window(window, game, perso);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.000;
        analyse_move_event(window, game, event, perso);
        if (seconds > 0.1) {
            perso_anim(perso);
            sfClock_restart(clock);
        }
    }
}