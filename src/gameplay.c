/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** gameplay
*/

#include "../include/rpg.h"

void gameplay(sfRenderWindow *window, game_t *game, perso_t *perso)
{
    sfClock *clock = sfClock_create();
    float seconds;
    sfEvent event;
    sfTime time;

    while (game->cur_scn == 1) {
        sfRenderWindow_clear(window, sfBlack);
        draw_elements(window, *game);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.000;
        //*game = analyse_events(window, event, *game);
        analyse_move_event(window, game, event, perso);
        if (seconds > 0.1) {
            perso_anim(perso);
            sfClock_restart(clock);
        }
        sfRenderWindow_drawSprite(window, perso->spr, NULL);
        sfRenderWindow_display(window);
    }
}