/*
** EPITECH PROJECT, 2020
** init game 2
** File description:
** init others functions
*/

#include "proto.h"
#include "rpg.h"

void init_forest_map(game_t game)
{
    int scene_nb = 4;
    sfVector2f fight_but_pos = {100, 50};

    game.scenes[4].enemy = malloc(sizeof(enemy_t) * 1);
    game.scenes[4].enemy[0] = init_enemy_forest();
    game.scenes[4].enemy_left = 1;
    game.scenes[4].name = malloc(sizeof(char) * 11);
    game.scenes[4].name = "forest_map";
    game.scenes[4].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[4].gm_objcts[0] = init_game_obj(game.scenes[4].gm_objcts[0], \
    "ressources/map_forest.jpg");
    game.scenes[4].obj_nbr = 1;
    game.scenes[4].but_nbr = 0;
    game.scenes[4].map = init_map(game, "game_maps/forest", scene_nb);
}

void init_desert_map(game_t game)
{
    int scene_nb = 5;
    sfVector2f fight_but_pos = {100, 50};

    game.scenes[5].enemy = malloc(sizeof(enemy_t) * 1);
    game.scenes[5].enemy[0] = init_enemy_lac();
    game.scenes[5].enemy_left = 1;
    game.scenes[5].name = malloc(sizeof(char) * 11);
    game.scenes[5].name = "desert_map";
    game.scenes[5].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[5].gm_objcts[0] = init_game_obj(game.scenes[5].gm_objcts[0], \
    "ressources/map_desert.jpg");
    game.scenes[5].obj_nbr = 1;
    game.scenes[5].but_nbr = 0;
    game.scenes[5].map = init_map(game, "game_maps/desert", scene_nb);
}

void init_lava_map(game_t game)
{
    int scene_nb = 6;
    sfVector2f fight_but_pos = {100, 50};

    game.scenes[6].enemy = malloc(sizeof(enemy_t) * 1);
    game.scenes[6].enemy[0] = init_enemy_lava();
    game.scenes[6].enemy_left = 1;
    game.scenes[6].name = malloc(sizeof(char) * 9);
    game.scenes[6].name = "lava_map";
    game.scenes[6].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[6].gm_objcts[0] = init_game_obj(game.scenes[6].gm_objcts[0], \
    "ressources/map_lava.jpg");
    game.scenes[6].obj_nbr = 1;
    game.scenes[6].but_nbr = 0;
    game.scenes[6].map = init_map(game, "game_maps/lava", scene_nb);
}