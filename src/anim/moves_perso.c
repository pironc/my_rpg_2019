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
    sfSprite_setPosition(perso->spr, perso->pos);
    sfSprite_setTextureRect(perso->spr, perso->rect);
}

void enemy_anim_test(enemy_t *enemy, game_t game)
{
    for (int i = 0; i < game.scenes[game.cur_scn].enemy_left; i++) {
        move_rect(&enemy[i].rect, 64, 256);
        sfSprite_setTextureRect(enemy[i].spr, enemy[i].rect);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}

void move_perso(game_t *game, perso_t *perso, int i)
{
    sfEvent event;
    int top_y = (perso->pos.y + 16) / 32;
    int cur_y = (perso->pos.y + 32) / 32;
    int btm_y = (perso->pos.y + 48) / 32;
    int left_x = (perso->pos.x + 16) / 32;
    int cur_x = (perso->pos.x + 32) / 32;
    int right_x = (perso->pos.x + 48) / 32;

    if (i == 1)
        move_up(game, perso, cur_x, cur_y);
    if (i == 2)
        move_down(game, perso, cur_x, cur_y);
    if (i == 3)
        move_left(game, perso, cur_x, cur_y);
    if (i == 4)
        move_right(game, perso, cur_x, cur_y);

    sfSprite_setPosition(perso->spr, perso->pos);
    //printf(" %c \n%c%c%c\n %c\n", game->scenes[scene].map[cur_y - 1][cur_x],game->scenes[scene].map[cur_y][cur_x - 1], game->scenes[scene].map[cur_y][cur_x], game->scenes[scene].map[cur_y][cur_x + 1], game->scenes[scene].map[cur_y + 1][cur_x]);
    //printf("pos.x : %f ; pos.y : %f\n", perso->pos.x, perso->pos.y);
}

void change_sprite(perso_t *perso, char *filepath)
{
    sfTexture_destroy(perso->text);
    perso->text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect);
}