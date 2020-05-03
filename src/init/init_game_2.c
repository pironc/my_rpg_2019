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

    game.scenes[6].enemy_left = 0;
    game.scenes[6].name = malloc(sizeof(char) * 9);
    game.scenes[6].name = "lava_map";
    game.scenes[6].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[6].gm_objcts[0] = init_game_obj(game.scenes[6].gm_objcts[0], \
    "ressources/map_lava.jpg");
    game.scenes[6].obj_nbr = 1;
    game.scenes[6].but_nbr = 0;
    game.scenes[6].map = init_map(game, "game_maps/lava", scene_nb);
}

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

button_t init_button(button_t button, sfVector2f position, char *filepath)
{
    button_t new_but;

    new_but.spr = sfSprite_create();
    new_but.text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(new_but.spr, new_but.text, sfTrue);
    sfSprite_setPosition(new_but.spr, position);
    return (new_but);
}

gm_obj_t init_game_obj(gm_obj_t game_obj, char *filepath)
{
    gm_obj_t new_gm_obj;

    new_gm_obj.spr = sfSprite_create();
    new_gm_obj.text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(new_gm_obj.spr, new_gm_obj.text, sfTrue);
    return (new_gm_obj);
}
