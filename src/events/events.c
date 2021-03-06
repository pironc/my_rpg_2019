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
    if (game.cur_scn == 9) {
        game = button_is_clicked_htp(window, game);
        return (game);
    }
    return (game);
}