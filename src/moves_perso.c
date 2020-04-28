/*
** EPITECH PROJECT, 2020
** move perso
** File description:
** moves perso
*/

#include "../include/rpg.h"

void perso_anim(perso_t *perso)
{
    move_rect(&(perso->rect), 32, 320);
    sfSprite_setPosition(perso->spr, perso->pos);
    sfSprite_setTextureRect(perso->spr, perso->rect);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}

void move_perso(perso_t *perso, int i)
{
    change_sprite(perso, "ressources/perso_mouv.png");
    if (i == 1)
        perso->pos.y -= 4;
    if (i == 2)
        perso->pos.y += 4;
    if (i == 3)
        perso->pos.x -= 4;
    if (i == 4)
        perso->pos.x += 4;
}

void change_sprite(perso_t *perso, char *filepath) {
    sfTexture_destroy(perso->text);
    perso->text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect); 
    sfSprite_setPosition(perso->spr, perso->pos);
}