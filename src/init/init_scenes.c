/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_scenes.c
*/
#include "proto.h"
#include "rpg.h"

void init_game_scenes(game_t game)
{
    init_forest_map(game);
    init_desert_map(game);
    init_lava_map(game);
    init_desert_house(game);
    init_forest_house(game);
}