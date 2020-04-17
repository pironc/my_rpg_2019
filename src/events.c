/*
** EPITECH PROJECT, 2020
** events
** File description:
** handle events
*/

#include "../include/rpg.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

int check_which_button(game_t game, int but_tested, sfVector2i c_pos)
{
    sfFloatRect g_bnd = sfSprite_getGlobalBounds(game.scenes[game.cur_scn].buttons[but_tested - 1].spr);
    if (c_pos.x >= g_bnd.left && c_pos.x <= (g_bnd.left + g_bnd.width)) {
        if (c_pos.y <= (g_bnd.top + g_bnd.height) && c_pos.y >= g_bnd.top) {
            return (but_tested);
        }
    }
    return (0);
}

game_t button_is_clicked_menu(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    if (game.scenes[0].but_nbr > 0) {
        for (int i = 1; but_clicked == 0; i++) {
            but_clicked = check_which_button(game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        destroy_menu(game);
        game.cur_scn = 1;
        game.scenes[1].but_nbr = 1;
        game.scenes[1].obj_nbr = 1;
    }
    if (but_clicked == 2) {
        destroy_menu(game);
        game.cur_scn = 2;
        game.scenes[1].but_nbr = 3;
        game.scenes[1].obj_nbr = 1;
    }
    return (game);
}

game_t button_is_clicked_game(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    if (game.scenes[1].but_nbr > 0) {
        for (int i = 1; but_clicked == 0; i++) {
            but_clicked = check_which_button(game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        init_combat_scene(game, window);
        game.cur_scn = 3;
        game.scenes[3].but_nbr = 0;
        game.scenes[3].obj_nbr = 1;
    }
    return (game);
}

game_t button_is_clicked(sfRenderWindow *window, game_t game)
{
    if (game.cur_scn == 1) {
        game = button_is_clicked_game(window, game);
    }
    if (game.cur_scn == 0) {
        game = button_is_clicked_menu(window, game);
    }
    return (game);
}

game_t analyse_events(sfRenderWindow *window, sfEvent event, game_t game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            game = button_is_clicked(window, game);
        }
    }
    return (game);
}