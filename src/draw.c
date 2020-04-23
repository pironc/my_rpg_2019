/*
** EPITECH PROJECT, 2020
** draw
** File description:
** draw
*/

#include "../include/rpg.h"

void draw_elements(sfRenderWindow *window, game_t game)
{
    /*if (game.fade.active == 1) {
        game.fade.transparent.a = fade_in(window, game);
        game.fade.active = 0;
    }*/
    for (int i = 0; i != game.scenes[game.cur_scn].obj_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[game.cur_scn].gm_objcts[i].spr, NULL);
    }
    for (int i = 0; i != game.scenes[game.cur_scn].but_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[game.cur_scn].buttons[i].spr, NULL);
    }
    /*if (game.fade.active = 0) {
        game.fade.transparent.a = fade_out(window, game);
    }*/
}

void draw_combat(sfRenderWindow *window, game_t game)
{
    for (int i = 0; i != game.scenes[3].obj_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[3].gm_objcts[i].spr, NULL);
    }
    for (int i = 0; i != game.scenes[3].but_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[3].buttons[i].spr, NULL);
    }
}

int draw_window(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        game = analyse_events(window, event, game);
        draw_elements(window, game);
        if (game.cur_scn != 0) {
            sfRenderWindow_drawSprite(window, game.perso->spr, NULL);
        }
        gameplay(window, game, game.perso);
        sfRenderWindow_display(window);
    }
    return (0);
}