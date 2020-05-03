/*
** EPITECH PROJECT, 2020
** init game
** File description:
** initialize functions in different scenes
*/
#include "proto.h"
#include "rpg.h"

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
    "ressources/menu_background.jpg");
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

void init_game_scenes(game_t game)
{
    init_forest_map(game);
    init_desert_map(game);
    init_lava_map(game);
    init_desert_house(game);
    init_forest_house(game);
}

void init_pause_menu(game_t game)
{
    button_t button;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f play_pos = {650, 100};
    button.pos_play = play_pos;
    sfVector2f pos_exit = {650, 550};
    button.pos_exit = pos_exit;

    game.scenes[2].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[2].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[2].gm_objcts[0] = init_game_obj(game.scenes[2].gm_objcts[0], \
    "ressources/menu_background.jpg");
    game.scenes[2].buttons[0] = init_button(game.scenes[2].buttons[0], \
    button.pos_play, "ressources/BUTTONS/Return.png");
    sfSprite_setScale(game.scenes[2].buttons[0].spr, scale);
    game.scenes[2].buttons[2] = init_button(game.scenes[1].buttons[2], \
    button.pos_exit, "ressources/BUTTONS/Exit.png");
    sfSprite_setScale(game.scenes[2].buttons[2].spr, scale);
}

void init_options_menu(game_t game)
{
    button_t button;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f pos_play = {650, 50};
    sfVector2f pos_sound = {700, 350};
    sfVector2f pos_htp = {650, 650};

    game.scenes[1].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[1].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[1].gm_objcts[0] = init_game_obj(game.scenes[1].gm_objcts[0], \
    "ressources/menu_background.jpg");
    game.scenes[1].buttons[0] = init_button(game.scenes[1].buttons[0], \
    pos_play, "ressources/BUTTONS/Return.png");
    sfSprite_setScale(game.scenes[1].buttons[0].spr, scale);
    game.scenes[1].buttons[1] = init_button(game.scenes[1].buttons[1], \
    pos_sound, "ressources/BUTTONS/Sound.png");
    sfSprite_setScale(game.scenes[1].buttons[1].spr, scale);
    game.scenes[1].buttons[2] = init_button(game.scenes[1].buttons[2], \
    pos_htp, "ressources/BUTTONS/howtoplay.png");
    sfSprite_setScale(game.scenes[1].buttons[2].spr, scale);
}

void init_how_to_play(game_t game)
{
    button_t button;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f pos_back = {650, 100};

    game.scenes[9].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[9].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[9].gm_objcts[0] = init_game_obj(game.scenes[9].gm_objcts[0], \
    "ressources/howtoplay.jpg");
    game.scenes[9].buttons[0] = init_button(game.scenes[9].buttons[0], \
    pos_back, "ressources/BUTTONS/Return.png");
    sfSprite_setScale(game.scenes[9].buttons[0].spr, scale);
}

game_t initialize_game(game_t game)
{
    perso_t *perso = malloc(sizeof(perso_t) * 1);

    game.cur_scn = 0;
    game.scenes[0].obj_nbr = 1;
    game.scenes[0].but_nbr = 3;
    game.menu_music = sfMusic_createFromFile("ressources/Audio/menu.ogg");
    game.am_music = sfMusic_createFromFile("ressources/Audio/ambiance.ogg");
    game.cbt_music = sfMusic_createFromFile("ressources/Audio/combat.ogg");
    game.cave_music = sfMusic_createFromFile("ressources/Audio/cave.ogg");
    game.door_sound = sfSoundBuffer_createFromFile("ressources/Audio/door.ogg");
    game.door = sfSoundBuffer_createFromFile("ressources/Audio/door.ogg");
    game.door_sound = sfSound_create();
    init_perso(perso);
    //check_perso(perso);
    game.perso = perso;
    init_menu(game);
    init_options_menu(game);
    init_pause_menu(game);
    init_how_to_play(game);
    init_game_scenes(game);
    return (game);
}