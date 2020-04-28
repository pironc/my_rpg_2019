/*
** EPITECH PROJECT, 2020
** move perso
** File description:
** moves perso
*/
#include "proto.h"
#include "rpg.h"

void perso_anim(perso_t *perso)
{
    move_rect(&(perso->rect), 64, 256);
    //sfSprite_setPosition(perso->spr, perso->pos);
    sfSprite_setTextureRect(perso->spr, perso->rect);
}

void enemy_anim_test(enemy_t **enemies, game_t game)
{
    for (int i = 0; i < game.scenes[1].enemy_left; i++) {
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
    int current_y = 0;

    char *map_tile[] = {
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWW*************************WWWWW************************WWW",
        "WWW*************************WWWWW************************WWW",
        "WWW*************W***********WWWWW************************WWW",
        "WWW*************************WWWWW************************WWW",
        "WWW***W*********************WWWWW****W*******************WWW",
        "WWW*********W***************WWWWW******************W*****WWW",
        "************************W***WWWWW***********W***************",
        "****************************WWWWW***************************",
        "************************WWWWWWWWW***************************",
        "WWW*********************WWWWWWWWW************************WWW",
        "WWW*****W***************WWWWWWWWW************************WWW",
        "WWW*********************WWWWWWWWW******W*****************WWW",
        "WWW*********************WWWWWWWWW***************W*****W**WWW",
        "WWW*********************WWWWW****************************WWW",
        "WWW*******************WWWWWWW****************************WWW",
        "WWW*******************WWWWWWW****************************WWW",
        "WWW*W**********W*****************************************WWW",
        "WWW*********W********WWWWWWW*****************************WWW",
        "WWW******************WWWWWWW*****************************WWW",
        "WWW***W***********WWWWWWWWWW*****W***********************WWW",
        "WWW***************WWWWWWWW**WW***************************WWW",
        "WWW********W***W**WWWWWWWW********WWWW*******************WWW",
        "WWW***************WWWWWW*******W*************************WWW",
        "WWW************WWWWWWWWW*WWW**************W**************WWW",
        "WWW***********WWWWWWWWWW***************W*****************WWW",
        "WWW**********WWWWWWWWWWW********W***W********************WWW",
        "WWW***W***W*WWWWWWWWW***W***W***********WWW***********W**WWW",
        "WWW*********WWWWWWW***********WW*************************WWW",
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
    };

    current_y = (perso->pos.y + 32) / 32;
    current_x = (perso->pos.x + 32) / 32;

    if (i == 1) {
        change_sprite(perso, "ressources/perso_up.png");
        /*if (perso->pos.x < 70 && perso->pos.y > 230 && perso->pos.y < 290)
            perso->pos.y -= 8;
        else if (perso->pos.x > 1750 && perso->pos.y > 230 && perso->pos.y < 290)
            perso->pos.y -= 8;
        else if (perso->pos.x > 69 && perso->pos.x < 1760 && perso->pos.y > 100)
            perso->pos.y -= 8;*/
        if (map_tile[current_y][current_x] == '*' && perso->pos.y > 70)
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
        if (map_tile[current_y + 1][current_x] == '*')
            perso->pos.y += 8;
        else
            perso->pos.y += 0;
    }
    if (i == 3) {
        change_sprite(perso, "ressources/perso_left.png");
        /*if (perso->pos.x > 75 || (perso->pos.y > 220 && perso->pos.y < 290))
            perso->pos.x -= 8;*/
        if (map_tile[current_y][current_x - 1] == '*')
            perso->pos.x -= 8;
        else
            perso->pos.x -= 0;
    }
    if (i == 4) {
        change_sprite(perso, "ressources/perso_right.png");
        /*if (perso->pos.x < 1750 || (perso->pos.y > 220 && perso->pos.y < 290))
            perso->pos.x += 8;*/
        if (map_tile[current_y][current_x + 1] == '*')
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