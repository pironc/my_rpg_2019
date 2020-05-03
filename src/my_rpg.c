/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** function where everything will be called in order to make the rpg work
*/
#include "proto.h"
#include "rpg.h"

int my_rpg(void)
{
    game_t game;
    sfTime time;
    sfClock *clock = sfClock_create();
    float seconds;

    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My_RPG", \
    sfResize | sfClose, NULL);
    game.scenes = malloc(sizeof(scene_t) * 10);
    sfRenderWindow_setFramerateLimit(window, 60);
    if (!window) {
        return (EXIT_FAILURE);
    }
    game = initialize_game(game);
    draw_window(window, game);
    return (0);
}