/*
** EPITECH PROJECT, 2020
** transition
** File description:
** fade in and out between scenes and other transitions
*/
#include "proto.h"
#include "rpg.h"

void fade_in(sfRenderWindow *window, filter_t *transition)
{
    sfColor color = sfColor_fromRGBA(0, 0, 0, 150);
    while (color.a < 255) {
        my_putchar('b');
        color.a++;
        my_putchar('c');
        sfRectangleShape_setFillColor(transition->rect, color);
        my_putchar('d');
        sfRenderWindow_drawRectangleShape(window, transition->rect, NULL);
        my_putchar('d');
        sfRenderWindow_display(window);
        my_putchar('e');
    }
    my_put_nbr(color.a);
}

void fade_out(sfRenderWindow *window, filter_t *transition)
{
    while (transition->transparent.a != 0) {
        transition->transparent.a--;
        sfRectangleShape_setFillColor(transition->rect, transition->transparent);
        sfRenderWindow_drawRectangleShape(window, transition->rect, NULL);
        sfRenderWindow_display(window);
    }
}