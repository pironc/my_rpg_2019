/*
** EPITECH PROJECT, 2020
** dialogue anim
** File description:
** dialogue anim
*/

#include "rpg.h"
#include "proto.h"

void zoom(sfView *view, sfRenderWindow *window, game_t game)
{
    sfVector2f offset = {0, 0};
    sfVector2f view_size = {1920, 1080};
    sfVector2f view_center = {960, 540};
    sfView_setSize(view, view_size);
    sfView_setCenter(view, view_center);
    for (int i = 0; i != 5; i++) {
        sfView_zoom(view, 0.9);
        sfRenderWindow_setView(window, view);
        reset_window(window, &game, game.perso);
        sfRenderWindow_display(window);
    }
    for (int i = 0; i != 7; offset.y -= 10) {
        sfView_move(view, offset);
        sfRenderWindow_setView(window, view);
        reset_window(window, &game, game.perso);
        sfRenderWindow_display(window);
        i++;
    }
}

void dezoom(sfView *view, sfRenderWindow *window, game_t game, sfVector2f last_center)
{
    sfVector2f view_size = {1920, 1080};
    sfVector2f view_center = {960, 540};
    sfVector2f offset = {0, 0};

    for (int i = 0; i != 5; i++) {
        sfView_zoom(view, 1.1);
        sfRenderWindow_setView(window, view);
        reset_window(window, &game, game.perso);
        sfRenderWindow_display(window);
    }
    for (int i = 0; i != 7; offset.y += 9) {
        sfView_move(view, offset);
        sfRenderWindow_setView(window, view);
        reset_window(window, &game, game.perso);
        sfRenderWindow_display(window);
        i++;
    }
}

void dialogue_cutscene(sfRenderWindow *window, game_t game, sfText *dilg)
{
    int i = 0;
    sfView *view = sfView_create();
    sfVector2f last_center = sfView_getCenter(view);

    zoom(view, window, game);
    my_putchar('a');
    while (i < 100) {
        sfRenderWindow_drawText(window, dilg, NULL);
        sfRenderWindow_display(window);
        i++;
    }
    dezoom(view, window, game, last_center);
    sfView_destroy(view);
}