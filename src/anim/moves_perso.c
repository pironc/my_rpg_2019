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
    int current_x = 0;
    int current_ytop = 0;
    int current_ybottom = 0;

    char *map_tile[] = {
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWW*************************WW",
        "WWW*************************WW",
        "WWW*************T***********WW",
        "WWW***T*********************WW",
        "WWW***T*********************WW",
        "WWW*********T***********T***WW",
        "************************T***WW",
        "****************************WW",
        "************************WWWWWW",
        "********T***************WWWWWW",
        "********T***************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
        "************************WWWWWW",
    };

    current_ytop = (perso->pos.y) / 32;
    current_ybottom = (perso->pos.y + 48) / 32;
    current_x = (perso->pos.x + 32) / 32;

    if (i == 1) {
        change_sprite(perso, "ressources/perso_up.png");
        /*if (perso->pos.x < 70 && perso->pos.y > 230 && perso->pos.y < 290)
            perso->pos.y -= 8;
        else if (perso->pos.x > 1750 && perso->pos.y > 230 && perso->pos.y < 290)
            perso->pos.y -= 8;
        else if (perso->pos.x > 69 && perso->pos.x < 1760 && perso->pos.y > 100)
            perso->pos.y -= 8;*/
        if (map_tile[current_ytop][current_x] == '*' && map_tile[current_ybottom][current_x] == '*')
            perso->pos.y -= 8;
        else
            perso->pos.y -= 0;
    }
    if (i == 2) {
        change_sprite(perso, "ressources/perso_down.png");
        /*if (perso->pos.x < 70 && perso->pos.y > 220 && perso->pos.y < 280)
            perso->pos.y += 8;
        else if (perso->pos.x > 1750 && perso->pos.y > 220 && perso->pos.y < 280)
            perso->pos.y += 8;
        else if (perso->pos.x > 69 && perso->pos.x < 1760 && perso->pos.y < 890)
            perso->pos.y += 8;*/
        if (map_tile[current_ytop + 1][current_x] == '*' && map_tile[current_ybottom + 1][current_x] == '*')
            perso->pos.y += 8;
        else
            perso->pos.y += 0;
    }
    if (i == 3) {
        change_sprite(perso, "ressources/perso_left.png");
        /*if (perso->pos.x > 75 || (perso->pos.y > 220 && perso->pos.y < 290))
            perso->pos.x -= 8;*/
        if (map_tile[current_ytop][current_x - 1] == '*' && map_tile[current_ybottom][current_x - 1] == '*')
            perso->pos.x -= 8;
        else
            perso->pos.x -= 0;
    }
    if (i == 4) {
        change_sprite(perso, "ressources/perso_right.png");
        /*if (perso->pos.x < 1750 || (perso->pos.y > 220 && perso->pos.y < 290))
            perso->pos.x += 8;*/
        if (map_tile[current_ytop][current_x + 1] == '*' && map_tile[current_ybottom][current_x + 1] == '*')
            perso->pos.x += 8;
        else
            perso->pos.x += 0;
    }
    sfSprite_setPosition(perso->spr, perso->pos);
    //printf("pos.x : %f ; pos.y : %f\n", perso->pos.x, perso->pos.y);
}

void change_sprite(perso_t *perso, char *filepath)
{
    sfTexture_destroy(perso->text);
    perso->text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect);
    //sfSprite_setPosition(perso->spr, perso->pos);

    //TODO print les feuilles par dessus tout le reste (ressources/leaves.png)
    // et voir si ça rend bien
}