/*
** EPITECH PROJECT, 2020
** init game
** File description:
** initialize functions in different scenes
*/
#include "proto.h"
#include "rpg.h"

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

void init_menu(game_t game)
{
    button_t button;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f pos_play = {650, 100};
    sfVector2f pos_menu = {720, 420};
    sfVector2f pos_exit = {650, 700};

    game.scenes[0].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[0].gm_objcts = malloc(sizeof(gm_obj_t) * 1);
    game.scenes[0].gm_objcts[0] = init_game_obj(game.scenes[0].gm_objcts[0], \
    "ressources/main_menu_bg.png");
    game.scenes[0].buttons[0] = init_button(game.scenes[0].buttons[0], \
    pos_play, "ressources/BUTTONS/Play.png");
    sfSprite_setScale(game.scenes[0].buttons[0].spr, scale);
    game.scenes[0].buttons[1] = init_button(game.scenes[0].buttons[1], \
    pos_menu, "ressources/BUTTONS/Options.png");
    sfSprite_setScale(game.scenes[0].buttons[1].spr, scale);
    game.scenes[0].buttons[2] = init_button(game.scenes[0].buttons[2], \
    pos_exit, "ressources/BUTTONS/Exit.png");
    sfSprite_setScale(game.scenes[0].buttons[2].spr, scale);
}

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

void init_game_scenes(game_t game)
{
    init_forest_map(game);
    init_desert_map(game);
    init_lava_map(game);
}

void init_pause_menu(game_t game)
{
    button_t button;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f pos_play = {650, 100};
    sfVector2f pos_options = {710, 400};
    sfVector2f pos_exit = {650, 700};

    game.scenes[2].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[2].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[2].gm_objcts[0] = init_game_obj(game.scenes[2].gm_objcts[0], \
    "ressources/main_menu_bg.png");
    game.scenes[2].buttons[0] = init_button(game.scenes[2].buttons[0], \
    pos_play, "ressources/BUTTONS/Return.png");
    sfSprite_setScale(game.scenes[2].buttons[0].spr, scale);
    game.scenes[2].buttons[1] = init_button(game.scenes[1].buttons[1], \
    pos_options, "ressources/BUTTONS/Options.png");
    sfSprite_setScale(game.scenes[2].buttons[1].spr, scale);
    game.scenes[2].buttons[2] = init_button(game.scenes[1].buttons[2], \
    pos_exit, "ressources/BUTTONS/Exit.png");
    sfSprite_setScale(game.scenes[2].buttons[2].spr, scale);
}

void init_options_menu(game_t game)
{
    button_t button;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f pos_play = {650, 100};
    sfVector2f pos_options = {710, 400};
    sfVector2f pos_exit = {650, 700};

    game.scenes[1].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[1].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[1].gm_objcts[0] = init_game_obj(game.scenes[1].gm_objcts[0], \
    "ressources/main_menu_bg.png");
    game.scenes[1].buttons[0] = init_button(game.scenes[1].buttons[0], \
    pos_play, "ressources/BUTTONS/Return.png");
    sfSprite_setScale(game.scenes[1].buttons[0].spr, scale);
    game.scenes[1].buttons[1] = init_button(game.scenes[1].buttons[1], \
    pos_options, "ressources/BUTTONS/Sound.png");
    sfSprite_setScale(game.scenes[1].buttons[1].spr, scale);
}

void init_transition(game_t game)
{
    sfVector2f size = {1920, 1080};

    game.fade.fade_clock = sfClock_create();
    game.fade.active = 0;
    game.fade.rect = sfRectangleShape_create();
    sfRectangleShape_setSize(game.fade.rect, size);
    game.fade.transparent = sfColor_fromRGBA(0, 0, 0, 0);
}

game_t initialize_game(game_t game)
{
    perso_t *perso = malloc(sizeof(perso_t) * 1);

    game.cur_scn = 0;
    game.scenes[0].obj_nbr = 1;
    game.scenes[0].but_nbr = 3;
    init_perso(perso);
    //check_perso(perso);
    game.perso = perso;
    init_menu(game);
    init_options_menu(game);
    init_pause_menu(game);
    init_game_scenes(game);
    return (game);
}