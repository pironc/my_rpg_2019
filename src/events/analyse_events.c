/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_events.c
*/

#include "proto.h"
#include "rpg.h"

game_t analyse_combat_event(sfRenderWindow *window, sfEvent event, \
game_t game, enemy_t *enemy)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            game.perso->hp = -1;
            destroy_all(game);
            close_window(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            game = button_is_clicked_combat(window, game, enemy, event);
        }
        if (event.type == sfEvtMouseButtonReleased) {
            game = button_is_released_combat(window, game, enemy, event);
        }
    }
    return (game);
}

int analyse_inventory_events(sfRenderWindow *window, sfEvent event, int flag)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI) {
            flag = 1;
        }
    }
    return (flag);
}

void analyse_house_events(sfRenderWindow *window, sfEvent event, game_t game)
{
    static int dialogues;
    if (check_collision_prf(game) == 1 && dialogues == 0) {
        trigger_dialogue(window, game);
        dialogues = 1;
    }
}

game_t analyse_events(sfRenderWindow *window, sfEvent event, game_t game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            destroy_all(game);
            close_window(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            game = button_is_clicked(window, game);
        }
        if (event.key.code == sfKeyEscape){
            draw_menu_pause(window, game);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI) {
            open_inventory(window, game);
        }
        if (game.cur_scn == 8) {
            analyse_house_events(window, event, game);
        }
    }
    return (game);
}