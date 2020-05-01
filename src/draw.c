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
    for (int i = 0; i != game.scenes[game.cur_scn].obj_nbr; i++) {
        sfRenderWindow_drawSprite(window, \
game.scenes[game.cur_scn].gm_objcts[i].spr, NULL);
    }
    for (int i = 0; i != game.scenes[game.cur_scn].but_nbr; i++) {
        sfRenderWindow_drawSprite(window, \
game.scenes[game.cur_scn].buttons[i].spr, NULL);
    }
}

int menu_pause_is_open(sfRenderWindow *window, game_t game, sfEvent event, int flag)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(window);
        }
        if (event.key.code == sfKeyP) {
            flag = 1;
        }
    }
    return (flag);
}

void draw_menu_pause(sfRenderWindow *window, game_t game)
{
    int flag = 0;
    sfEvent event;

    while (1) {
        sfRenderWindow_drawSprite(window, game.scenes[2].gm_objcts[0].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[0].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[1].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[2].spr, NULL);
        sfRenderWindow_display(window);
        flag = menu_pause_is_open(window, game, event, flag);
        if (flag == 1) {
            break;
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