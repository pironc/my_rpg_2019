/*
** EPITECH PROJECT, 2020
** setrectpos
** File description:
** set rect pos
*/
#include "proto.h"
#include "rpg.h"

sfVector2f set_pos(int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

sfIntRect set_rect(int width, int height)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return (rect);
}