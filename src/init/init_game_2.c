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
    sfVector2f fight_but_pos = {100, 50};

    game.scenes[4].enemy_left = 3;
    game.scenes[4].name = malloc(sizeof(char) * 11);
    game.scenes[4].name = "forest_map";
    game.scenes[4].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[4].gm_objcts[0] = init_game_obj(game.scenes[4].gm_objcts[0], \
    "ressources/map_forest.jpg");
    game.scenes[4].obj_nbr = 1;
    game.scenes[4].but_nbr = 0;
}

void init_desert_map(game_t game)
{
    sfVector2f fight_but_pos = {100, 50};

    game.scenes[5].enemy_left = 0;
    game.scenes[5].name = malloc(sizeof(char) * 11);
    game.scenes[5].name = "desert_map";
    game.scenes[5].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[5].gm_objcts[0] = init_game_obj(game.scenes[5].gm_objcts[0], \
    "ressources/map_desert.jpg");
    game.scenes[5].obj_nbr = 1;
    game.scenes[5].but_nbr = 0;
}

void init_lava_map(game_t game)
{
    sfVector2f fight_but_pos = {100, 50};

    game.scenes[6].enemy_left = 0;
    game.scenes[6].name = malloc(sizeof(char) * 9);
    game.scenes[6].name = "lava_map";
    game.scenes[6].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[6].gm_objcts[0] = init_game_obj(game.scenes[6].gm_objcts[0], \
    "ressources/map_lava.jpg");
    game.scenes[6].obj_nbr = 1;
    game.scenes[6].but_nbr = 0;
}

button_t init_button(button_t button, \
sfVector2f position, char *filepath)
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
