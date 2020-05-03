/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** events_menu.c
*/

#include "proto.h"
#include "rpg.h"

void state_music(game_t game)
{
    int music_state = sfMusic_getStatus(game.menu_music);

    if (music_state == 2) {
        sfMusic_pause(game.menu_music);
    } else {
        sfMusic_play(game.menu_music);
    }
}

game_t button_is_clicked_htp(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    if (game.scenes[9].but_nbr > 0) {
        for (int i = 1; but_clicked == 0 && (i - 1) != \
game.scenes[9].but_nbr; i++) {
            but_clicked = check_which_button(\
game, i, sfMouse_getPosition(window));
        }
    }
    if (but_clicked == 1) {
        game.cur_scn = 1;
        game.scenes[1].but_nbr = 3;
        game.scenes[1].obj_nbr = 1;
    }
    return (game);
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
    if (but_clicked == 2)
        state_music(game);
    if (but_clicked == 3) {
        game.cur_scn = 9;
        game.scenes[9].but_nbr = 1;
        game.scenes[9].obj_nbr = 1;
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
        game.scenes[1].but_nbr = 3;
    }
    if (but_clicked == 3) {
        destroy_all(game);
        close_window(window);
    }
    return (game);
}