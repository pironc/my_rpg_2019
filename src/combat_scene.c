/*
** EPITECH PROJECT, 2020
** combat
** File description:
** handles combat scene events
*/
#include "proto.h"
#include "rpg.h"

void combat_scene_intro(sfRenderWindow *window, game_t game, sfVector2f board_pos, sfVector2f but_pos)
{
    sfTime time;
    sfClock *clock = sfClock_create();
    float seconds;

    while (board_pos.y != 0) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0) {
            board_pos.y -= 5;
            but_pos.y -= 5;
            sfRenderWindow_drawSprite(window, game.scenes[3].gm_objcts[0].spr, NULL);
            sfRenderWindow_drawSprite(window, game.scenes[3].gm_objcts[1].spr, NULL);
            sfRenderWindow_drawSprite(window, game.scenes[3].buttons[0].spr, NULL);
            sfRenderWindow_drawSprite(window, game.perso->spr, NULL);
            sfRenderWindow_display(window);
            sfSprite_setPosition(game.scenes[3].gm_objcts[1].spr, board_pos);
            sfSprite_setPosition(game.scenes[3].buttons[0].spr, but_pos);
            sfClock_restart(clock);
        }
    }
}

void init_combat_scene(game_t game, sfRenderWindow *window)
{
    int test = 0;
    sfVector2f pos_char = {50, 320};
    sfVector2f board_pos = {0, 500};
    sfVector2f but_pos = {75, 1275};
    sfVector2f scale_char = {2, 2};

    game.scenes[3].gm_objcts = malloc(sizeof(gm_obj_t) * 2);
    game.scenes[3].buttons = malloc(sizeof(button_t) * 1);
    game.scenes[3].gm_objcts[0] = init_game_obj(game.scenes[3].gm_objcts[0], "ressources/combat_bg/grass_plain_3.jpg");
    game.scenes[3].gm_objcts[1] = init_game_obj(game.scenes[3].gm_objcts[1], "ressources/combat_bg/combat_ui_board.png");
    game.scenes[3].buttons[0] = init_button(game.scenes[3].buttons[0], but_pos, "ressources/combat_bg/but/base_atk_idle.png");
    sfSprite_setPosition(game.perso->spr, pos_char);
    sfSprite_setScale(game.perso->spr, scale_char);
    sfSprite_setPosition(game.scenes[3].gm_objcts[1].spr, board_pos);
    sfSprite_setPosition(game.scenes[3].buttons[0].spr, but_pos);
    combat_scene_intro(window, game, board_pos, but_pos);
}

void combat(sfRenderWindow *window, game_t game)
{
    int combat_over = 0;
    while(combat_over == 1) {
        ;
    }
}