/*
** EPITECH PROJECT, 2020
** update buttons spr
** File description:
** changes the sprite of a button when hovered
*/

#include "rpg.h"
#include "proto.h"

void heavy_atk_idle(game_t game)
{
    sfTexture *text_hvr = sfTexture_createFromFile\
    ("ressources/combat_bg/but/heavy_atk_idle.png", NULL);
    sfSprite_setTexture(game.scenes[3].buttons[1].spr, text_hvr, sfTrue);
}

void heavy_atk_hover(game_t game)
{
    sfTexture *text_hvr = sfTexture_createFromFile\
    ("ressources/combat_bg/but/heavy_atk_hover.png", NULL);
    sfSprite_setTexture(game.scenes[3].buttons[1].spr, text_hvr, sfTrue);
}

void base_atk_hover(game_t game)
{
    sfTexture *text_hvr = sfTexture_createFromFile\
    ("ressources/combat_bg/but/base_atk_hover.png", NULL);
    sfSprite_setTexture(game.scenes[3].buttons[0].spr, text_hvr, sfTrue);
}

void base_atk_idle(game_t game)
{
    sfTexture *text_hvr = sfTexture_createFromFile\
    ("ressources/combat_bg/but/base_atk_idle.png", NULL);
    sfSprite_setTexture(game.scenes[3].buttons[0].spr, text_hvr, sfTrue);
}