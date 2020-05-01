/*
** EPITECH PROJECT, 2020
** draw
** File description:
** draw
*/
#include "proto.h"
#include "rpg.h"

void draw_elements(sfRenderWindow *window, game_t game)
{
    /*if (game.fade.active == 1) {
        game.fade.transparent.a = fade_in(window, game);
        game.fade.active = 0;
    }*/
    for (int i = 0; i != game.scenes[game.cur_scn].obj_nbr; i++) {
        sfRenderWindow_drawSprite(window, \
game.scenes[game.cur_scn].gm_objcts[i].spr, NULL);
    }
    for (int i = 0; i != game.scenes[game.cur_scn].but_nbr; i++) {
        sfRenderWindow_drawSprite(window, \
game.scenes[game.cur_scn].buttons[i].spr, NULL);
    }
    /*if (game.fade.active = 0) {
        game.fade.transparent.a = fade_out(window, game);
    }*/
}

int menu_pause_is_open(sfRenderWindow *window, game_t game, int flag)
{
    if (game.scenes[2].but_nbr > 0) {
        for (int i = 1; flag == 0 && (i - 1) != game.scenes[2].but_nbr; i++) {
            flag = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    return (flag);
}

void draw_menu_pause(sfRenderWindow *window, game_t game)
{
    int flag = 0;
    while (1) {
        sfRenderWindow_drawSprite(window, game.scenes[2].gm_objcts[0].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[0].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[1].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[2].spr, NULL);
        sfRenderWindow_display(window);
        flag = menu_pause_is_open(window, game, flag);
        if (flag == 1) {
            break;
        }
        if (flag == 2) {
            game.cur_scn = 1;
            game.scenes[1].obj_nbr = 1;
            game.scenes[1].but_nbr = 2;
        }
        if (flag == 3) {
            close_window(window);
        }
    }
}

void draw_combat(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    for (int i = 0; i != game.scenes[3].obj_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[3].gm_objcts[i].spr, NULL);
    }
    for (int i = 0; i != game.scenes[3].but_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[3].buttons[i].spr, NULL);
    }
    sfRenderWindow_drawSprite(window, game.perso->spr, NULL);
    sfRenderWindow_drawSprite(window, enemy->spr, NULL);
    sfRenderWindow_drawSprite(window, game.perso->hp_bar.hp_bar_spr, NULL);
    sfRenderWindow_drawSprite(window, enemy->hp_bar.hp_bar_spr, NULL);
    sfRenderWindow_drawRectangleShape(window, game.perso->hp_bar.rect, NULL);
    sfRenderWindow_drawRectangleShape(window, enemy->hp_bar.rect, NULL);
}

int draw_window(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    game.enemies = malloc(sizeof(enemy_t*) * 4);
    init_enemies(game.enemies);
    //game.all_map = init_map();
    //check_map(game.all_map);
    //check_enemy(game.enemies);
    //check_perso(game.perso);
    while (sfRenderWindow_isOpen(window)) {
        game = analyse_events(window, event, game);
        sfRenderWindow_clear(window, sfBlack);
        draw_elements(window, game);
        gameplay(window, game, game.perso);
        sfRenderWindow_display(window);
    }
    destroy_perso(game.perso);
    //destroy_map(game.all_map);
    return (0);
}