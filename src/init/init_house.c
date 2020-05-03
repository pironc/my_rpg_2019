/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_house.c
*/
#include "proto.h"
#include "rpg.h"

void init_desert_house(game_t game)
{
    int scene_nb = 7;

    game.scenes[7].enemy = malloc(sizeof(enemy_t) * 1);
    game.scenes[7].enemy[0] = init_enemy_desert();
    game.scenes[7].enemy_left = 1;
    game.scenes[7].name = malloc(sizeof(char) * 12);
    game.scenes[7].name = "desert_house";
    game.scenes[7].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[7].gm_objcts[0] = init_game_obj(game.scenes[7].gm_objcts[0], \
    "ressources/desert_house.jpg");
    game.scenes[7].obj_nbr = 1;
    game.scenes[7].but_nbr = 0;
    game.scenes[7].map = init_map(game, "game_maps/desert_house", scene_nb);
}


void init_forest_house(game_t game)
{
    int scene_nb = 8;

    game.scenes[8].npc = malloc(sizeof(npc_t) * 1);
    game.scenes[8].npc[0] = init_professor(game);
    game.scenes[8].enemy_left = 0;
    game.scenes[8].name = malloc(sizeof(char) * 12);
    game.scenes[8].name = "forest_house";
    game.scenes[8].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[8].gm_objcts[0] = init_game_obj(game.scenes[8].gm_objcts[0], \
"ressources/forest_house.jpg");
    game.scenes[8].obj_nbr = 1;
    game.scenes[8].but_nbr = 0;
    game.scenes[8].map = init_map(game, "game_maps/forest_house", scene_nb);
}