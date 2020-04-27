/*
** EPITECH PROJECT, 2020
** move perso
** File description:
** moves perso
*/

#include "../../include/rpg.h"

void perso_anim(perso_t *perso)
{
    move_rect(&(perso->rect), 64, 256);
    //sfSprite_setPosition(perso->spr, perso->pos);
    sfSprite_setTextureRect(perso->spr, perso->rect);
}

void enemy_anim_test(enemy_t **enemies)
{
    for (int i = 0; i < 3; i++) {
        move_rect(&enemies[i]->rect, 64, 256);
        sfSprite_setTextureRect(enemies[i]->spr, enemies[i]->rect);
    }
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
    if (i == 1) {
        change_sprite(perso, "ressources/perso_up.png");
        if (perso->pos.x < 70 && perso->pos.y > 230 && perso->pos.y < 290)
            perso->pos.y -= 10;
        else if (perso->pos.x > 1750 && perso->pos.y > 230 && perso->pos.y < 290)
            perso->pos.y -= 10;
        else if (perso->pos.x > 69 && perso->pos.x < 1760 && perso->pos.y > 100)
            perso->pos.y -= 10;
    }
    if (i == 2) {
        change_sprite(perso, "ressources/perso_down.png");
        if (perso->pos.x < 70 && perso->pos.y > 220 && perso->pos.y < 280)
            perso->pos.y += 10;
        else if (perso->pos.x > 1750 && perso->pos.y > 220 && perso->pos.y < 280)
            perso->pos.y += 10;
        else if (perso->pos.x > 69 && perso->pos.x < 1760 && perso->pos.y < 890)
            perso->pos.y += 10;
    }
    if (i == 3) {
        change_sprite(perso, "ressources/perso_left.png");
        if (perso->pos.x > 75 || (perso->pos.y > 220 && perso->pos.y < 290))
            perso->pos.x -= 10;
    }
    if (i == 4) {
        change_sprite(perso, "ressources/perso_right.png");
        if (perso->pos.x < 1750 || (perso->pos.y > 220 && perso->pos.y < 290))
            perso->pos.x += 10;
    }
    sfSprite_setPosition(perso->spr, perso->pos);
    printf("pos.x : %f ; pos.y : %f\n", perso->pos.x, perso->pos.y);
}

void change_sprite(perso_t *perso, char *filepath)
{
    sfTexture_destroy(perso->text);
    perso->text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect);
    //sfSprite_setPosition(perso->spr, perso->pos);
}