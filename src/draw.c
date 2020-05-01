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

int position_of_mouse(sfRenderWindow *window, game_t game)
{
    button_t button;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    button.pos_play = sfSprite_getPosition(button.spr);
    int verif_height = 0;
    int verif_width = 0;
    if (mouse.x >= button.pos_play.x && mouse.x <= (button.pos_play.x + 110))
        verif_width = 1;
    if (mouse.y >= button.pos_play.y && mouse.y <= (button.pos_play.y + 100))
        verif_height = 1;
    return (verif_height * verif_width);
}

void draw_menu_pause(sfRenderWindow *window, game_t game)
{
    int but_clicked = 0;
    while (1) {
        sfRenderWindow_drawSprite(window, game.scenes[2].gm_objcts[0].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[0].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[1].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[2].spr, NULL);
        sfRenderWindow_display(window);
        if (position_of_mouse(window, game) \
&& sfMouse_isButtonPressed(sfMouseLeft)) {
            break;
        }
        /*if (but_clicked == 2) {
            game.cur_scn = 1;
            game.scenes[1].obj_nbr = 1;
            game.scenes[1].but_nbr = 2;
        }
        if (but_clicked == 3) {
            close_window(window);
        }*/
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