/*
** EPITECH PROJECT, 2020
** events
** File description:
** handle events
*/
#include "proto.h"
#include "rpg.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

int check_which_button(game_t game, int but_tested, sfVector2i c_pos)
{
    sfFloatRect g_bnd = sfSprite_getGlobalBounds(\
game.scenes[game.cur_scn].buttons[but_tested - 1].spr);
    if (c_pos.x >= g_bnd.left && c_pos.x <= (g_bnd.left + g_bnd.width)) {
        if (c_pos.y <= (g_bnd.top + g_bnd.height) && c_pos.y >= g_bnd.top) {
            return (but_tested);
        }
    }
    return (0);
}

game_t button_is_clicked_options(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    if (game.scenes[2].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != game.scenes[2].but_nbr; i++) {
            but_clicked = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        game.cur_scn = 0;
        game.scenes[0].but_nbr = 3;
        game.scenes[0].obj_nbr = 1;
    }
    if (but_clicked == 2) {
        my_putstr("eh");
    }
    return (game);
}

game_t button_is_clicked_menu(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    if (game.scenes[0].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != game.scenes[0].but_nbr; i++) {
            but_clicked = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        destroy_menu(game);
        game.cur_scn = 4;
        game.scenes[4].but_nbr = 0;
        game.scenes[4].obj_nbr = 1;
    }
    if (but_clicked == 2) {
        destroy_menu(game);
        game.cur_scn = 2;
        game.scenes[2].obj_nbr = 1;
        game.scenes[2].but_nbr = 2;
    }
    if (but_clicked == 3) {
        close_window(window);
    }
    return (game);
}

game_t button_is_released_combat(sfRenderWindow *window, game_t game, enemy_t *enemy, sfEvent event)
{
    int but_clicked = 0;
    if (game.scenes[3].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != game.scenes[3].but_nbr; i++) {
            but_clicked = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        base_atk_dmg(window, game, enemy);
        sfSprite_setTexture(game.scenes[3].buttons[0].spr, \
        game.scenes[3].buttons[0].text, sfTrue);
        draw_combat(window, game, enemy);
        base_atk_anim(window, game, enemy);
        game.player_turn = sfFalse;
    }
    return (game);
}

game_t button_is_clicked_combat(sfRenderWindow *window, game_t game, enemy_t *enemy, sfEvent event)
{
    int but_clicked = 0;
    if (game.scenes[3].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != game.scenes[3].but_nbr; i++) {
            but_clicked = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        base_atk_hover(game);
        sfRenderWindow_drawSprite(window, game.scenes[3].buttons[0].spr, NULL);
        sfRenderWindow_display(window);
    }
    return (game);
}

game_t button_is_clicked(sfRenderWindow *window, game_t game)
{
    if (game.cur_scn == 2) {
        game = button_is_clicked_options(window, game);
    }
    if (game.cur_scn == 0) {
        game = button_is_clicked_menu(window, game);
    }
    return (game);
}

game_t key_is_pressed(sfRenderWindow *window, sfEvent event, game_t game)
{
    if (game.cur_scn == 1) {
        analyse_move_event(window, &game, event, game.perso);
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

game_t analyse_combat_event(sfRenderWindow *window, sfEvent event, game_t game, enemy_t *enemy)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            game.perso->hp = -1;
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