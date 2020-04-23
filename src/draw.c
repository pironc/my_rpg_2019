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

int draw_window(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    game.perso = malloc(sizeof(perso_t) * 1);
    game.enemies = mallo(sizeof(enemy_t*) * 4);
    init_perso(game.perso);
    init_enemies(game.enemies);
    //check_enemy(enemies);
    check_perso(game.perso);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        game = analyse_events(window, event, game);
        draw_elements(window, game);
        gameplay(window, &game, game.perso);
        sfRenderWindow_display(window);
    }
    destroy_perso(game.perso);
    return (0);
}