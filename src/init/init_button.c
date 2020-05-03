/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_button.c
*/
#include "proto.h"
#include "rpg.h"

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