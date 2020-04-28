/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** text_in_button.c
*/
#include "proto.h"
#include "rpg.h"

void text_in_button(button_t *button)
{
    sfVector2f txt_pos = sfRectangleShape_getPosition(button->rect);
    txt_pos.x = txt_pos.x + sfRectangleShape_getSize(button->rect).x / 2 - \
    sfText_getGlobalBounds(button->text).width /2;
    txt_pos.y = txt_pos.y + sfRectangleShape_getSize(button->rect).y / 2 - \
    sfText_getGlobalBounds(button->text).height / 1.2;
    sfText_setPosition(button->text, txt_pos);
}