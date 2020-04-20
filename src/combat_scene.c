/*
** EPITECH PROJECT, 2020
** combat
** File description:
** handles combat scene events
*/

#include "../include/rpg.h"

void init_combat_scene(game_t game, sfRenderWindow *window)
{
    game.scenes[3].gm_objcts = malloc(sizeof(gm_obj_t) * 2);
    game.scenes[3].gm_objcts[0] = init_game_obj(game.scenes[3].gm_objcts[0], "ressources/combat_bg/grass_plain_3.jpg");
    //game.scenes[3].gm_objcts[1] = init_game_obj(game.scenes[3].gm_objcts[0], "ressources/combat_bg/combat_ui_board.png");
}