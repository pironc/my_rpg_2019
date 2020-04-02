/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** function where everything will be called in order to make the rpg work
*/

#include "../include/my.h"

int my_rpg(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My_Defender", \
    sfResize | sfClose, NULL);
    game_t game;
    game.scenes = malloc(sizeof(scene_t) * 3);
    sfTime time;
    float seconds;
    sfClock *clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(window, 60);
    if (!window) {
        return (EXIT_FAILURE);
    }
    game = initialize_game(game);
    draw_window(window, game);
    return (0);
}