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

void state_music(game_t game)
{
    int music_state = sfMusic_getStatus(game.menu_music);

    if (music_state == 2) {
        sfMusic_pause(game.menu_music);
    } else {
        sfMusic_play(game.menu_music);
    }
}

game_t button_is_clicked_options(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    if (game.scenes[1].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != \
game.scenes[1].but_nbr; i++) {
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
        state_music(game);
    }
    return (game);
}

game_t button_is_clicked_menu(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    if (game.scenes[0].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != \
game.scenes[0].but_nbr; i++) {
            but_clicked = check_which_button(game, i, \
sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        sfMusic_stop(game.menu_music);
        sfMusic_setVolume(game.am_music, 2.5);
        sfMusic_setLoop(game.am_music, sfTrue);
        sfMusic_play(game.am_music);
        game.cur_scn = 4;
        game.scenes[4].but_nbr = 0;
        game.scenes[4].obj_nbr = 1;
    }
    if (but_clicked == 2) {
        game.cur_scn = 1;
        game.scenes[1].obj_nbr = 1;
        game.scenes[1].but_nbr = 2;
    }
    if (but_clicked == 3) {
        sfMusic_destroy(game.cave_music);
        sfMusic_destroy(game.cbt_music);
        sfMusic_destroy(game.am_music);
        sfMusic_stop(game.menu_music);
        sfMusic_destroy(game.menu_music);
        close_window(window);
    }
    return (game);
}

game_t button_is_released_combat(sfRenderWindow *window, game_t game, \
enemy_t *enemy, sfEvent event)
{
    int but_clicked = 0;
    if (game.scenes[3].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != \
game.scenes[3].but_nbr; i++) {
            but_clicked = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        check_hvy_atk_cd(window, game.scenes[3].buttons[1]);
        base_atk_dmg(window, game, enemy);
        sfSprite_setTexture(game.scenes[3].buttons[0].spr, \
        game.scenes[3].buttons[0].text, sfTrue);
        draw_combat(window, game, enemy);
        perso_charge_forward(window, game, enemy);
        game.player_turn = sfFalse;
    }
    if (but_clicked == 2) {
        if (check_hvy_atk_cd(window, game.scenes[3].buttons[1]) == 0) {
            heavy_atk_dmg(window, game, enemy);
            draw_combat(window, game, enemy);
            perso_charge_forward(window, game, enemy);
            game.player_turn = sfFalse;
        } else {
            but_clicked = 0;
        }
    }
    return (game);
}

game_t button_is_clicked_combat(sfRenderWindow *window, game_t game, \
enemy_t *enemy, sfEvent event)
{
    int but_clicked = 0;
    if (game.scenes[3].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != \
game.scenes[3].but_nbr; i++) {
            but_clicked = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        base_atk_hover(game);
        sfRenderWindow_drawSprite(window, game.scenes[3].buttons[0].spr, NULL);
        sfRenderWindow_display(window);
    }
    if (but_clicked == 2) {
        heavy_atk_hover(game);
        sfRenderWindow_drawSprite(window, game.scenes[3].buttons[1].spr, NULL);
        sfRenderWindow_display(window);
    }
    return (game);
}

game_t button_is_clicked(sfRenderWindow *window, game_t game)
{
    if (game.cur_scn == 1) {
        game = button_is_clicked_options(window, game);
        return (game);
    }
    if (game.cur_scn == 0) {
        game = button_is_clicked_menu(window, game);
        return (game);
    }
    return (game);
}

game_t analyse_combat_event(sfRenderWindow *window, sfEvent event, \
game_t game, enemy_t *enemy)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            game.perso->hp = -1;
            sfMusic_destroy(game.cave_music);
            sfMusic_destroy(game.cbt_music);
            sfMusic_destroy(game.am_music);
            sfMusic_destroy(game.menu_music);
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

game_t analyse_events(sfRenderWindow *window, sfEvent event, game_t game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfMusic_destroy(game.cave_music);
            sfMusic_destroy(game.cbt_music);
            sfMusic_destroy(game.am_music);
            sfMusic_destroy(game.menu_music);
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
    }
    return (game);
}