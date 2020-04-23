/*
** EPITECH PROJECT, 2020
** move perso
** File description:
** moves perso
*/

#include "../../include/rpg.h"

void perso_anim(perso_t *perso)
{
    move_rect(&(perso->rect), 32, 320);
    //sfSprite_setPosition(perso->spr, perso->pos);
    sfSprite_setTextureRect(perso->spr, perso->rect);
}

void enemy_anim_test(enemy_t **enemies)
{
    for (int i = 0; i < 3; i++) {
        move_rect(&enemies[i]->rect, 64, 256);
        sfSprite_setTextureRect(enemies[i]->spr, enemies[i]->rect);
    }
    // move_rect(&enemies[0]->rect, 64, 256);
    // move_rect(&enemies[1]->rect, 64, 256);
    // move_rect(&enemies[2]->rect, 64, 256);
    // sfSprite_setTextureRect(enemies[0]->spr, enemies[0]->rect);
    // sfSprite_setTextureRect(enemies[1]->spr, enemies[1]->rect);
    // sfSprite_setTextureRect(enemies[2]->spr, enemies[2]->rect);
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
    if (i == 1) {
        if (perso->pos.y > 100)
            perso->pos.y -= 10;
    }
    if (i == 2) {
        if (perso->pos.y < 915)
            perso->pos.y += 10;
    }
    if (i == 3) {
        if (perso->pos.x > 75)
            perso->pos.x -= 10;
    }
    if (i == 4) {
        if (perso->pos.x < 1785)
            perso->pos.x += 10;
    }
    sfSprite_setPosition(perso->spr, perso->pos);
}

void change_sprite(perso_t *perso, char *filepath) {
    sfTexture_destroy(perso->text);
    perso->text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect); 
    //sfSprite_setPosition(perso->spr, perso->pos);
}