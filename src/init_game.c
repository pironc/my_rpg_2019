/*
** EPITECH PROJECT, 2020
** init game
** File description:
** initialize functions in different scenes
*/

#include "../include/rpg.h"

button_t init_button(button_t button, sfVector2f position, char *filepath)
{
    button_t new_but;

    new_but.spr = sfSprite_create();
    new_but.text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(new_but.spr, new_but.text, sfTrue);
    sfSprite_setPosition(new_but.spr, position);
    return(new_but);
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
    sfVector2f pos_play = {650, 100};
    sfVector2f pos_menu = {580, 400};
    sfVector2f pos_exit = {650, 700};

    game.scenes[0].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[0].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[0].gm_objcts[0] = init_game_obj(game.scenes[0].gm_objcts[0], "ressources/main_menu_bg.png");
    game.scenes[0].buttons[0] = init_button(game.scenes[0].buttons[0], pos_play, "ressources/BUTTONS/PlayButton.png");
    game.scenes[0].buttons[1] = init_button(game.scenes[0].buttons[1], pos_menu, "ressources/BUTTONS/MenuButton.png");
    game.scenes[0].buttons[2] = init_button(game.scenes[0].buttons[2], pos_exit, "ressources/BUTTONS/ExitButton.png");
}

void init_game_scene(game_t game)
{
    game.scenes[1].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[1].gm_objcts[0] = init_game_obj(game.scenes[1].gm_objcts[0], "ressources/game_temp.jpg");
}

void init_options(game_t game)
{
    sfVector2f pos_exit = {1800, 100};

    game.scenes[2].buttons = malloc(sizeof(button_t) * 3);
    game.scenes[2].gm_objcts = malloc(sizeof(gm_obj_t));
    game.scenes[2].gm_objcts[0] = init_game_obj(game.scenes[2].gm_objcts[0], "ressources/main_menu_bg.png");
    game.scenes[2].buttons[0] = init_button(game.scenes[2].buttons[0], pos_exit, "ressources/BUTTONS/ExitButton.png");
}

game_t initialize_game(game_t game)
{
    sfVector2f size = {1920, 1080};
    game.cur_scn = 0;
    game.scenes[0].obj_nbr = 1;
    game.scenes[0].but_nbr = 3;
    /*game.fade.fade_clock = sfClock_create();
    game.fade.active = 0;
    game.fade.rect = sfRectangleShape_create();
    sfRectangleShape_setSize(game.fade.rect, size);
    game.fade.transparent = sfColor_fromRGBA(0, 0, 0, 0);*/
    init_menu(game);
    init_options(game);
    init_game_scene(game);
    return (game);
}