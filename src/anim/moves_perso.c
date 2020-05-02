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
    for (int i = 0; i < game.scenes[game.cur_scn].enemy_left; i++) {
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

void move_perso(game_t *game, perso_t *perso, int i)
{
    sfEvent event;
    int top_y = 0;
    int cur_y = 0;
    int btm_y = 0;
    int left_x = 0;
    int cur_x = 0;
    int right_x = 0;

    int scene = game->cur_scn;

    top_y = (perso->pos.y + 16) / 32;
    cur_y = (perso->pos.y + 32) / 32;
    btm_y = (perso->pos.y + 48) / 32;

    left_x = (perso->pos.x + 16) / 32;
    cur_x = (perso->pos.x + 32) / 32;
    right_x = (perso->pos.x + 48) / 32;

    if (i == 1) {
        change_sprite(perso, "ressources/perso_up.png");
        if (game->scenes[scene].map[cur_y][cur_x] == '*' && \
game->scenes[scene].map[btm_y - 1][cur_x] == '*' &&
game->scenes[scene].map[btm_y - 1][left_x] == '*' && game->scenes[scene].map\
[btm_y - 1][right_x] == '*')
            perso->pos.y -= 8;
        else if (game->scenes[scene].map[cur_y - 1][cur_x] == 'H') {
            perso->pos.y = 500;
            perso->pos.x = 1000;
        } else
            perso->pos.y -= 0;
    }
    if (i == 2) {
        change_sprite(perso, "ressources/perso_down.png");
        if (game->scenes[scene].map[cur_y][cur_x] == '*' && \
game->scenes[scene].map[cur_y + 1][cur_x] == '*' && \
game->scenes[scene].map[cur_y + 1][left_x] == '*' && game->scenes[scene].map\
[cur_y + 1][right_x] == '*')
            perso->pos.y += 8;
        else
            perso->pos.y += 0;
    }
    if (i == 3) {
        change_sprite(perso, "ressources/perso_left.png");
        if (game->scenes[scene].map[cur_y][cur_x] == '*' && \
game->scenes[scene].map[cur_y][cur_x - 1] == '*' && \
game->scenes[scene].map[btm_y][cur_x - 1] == '*')
            perso->pos.x -= 8;
        else if (game->scenes[scene].map[cur_y][cur_x - 1] == 'D') {
            if (game->cur_scn == 4) {
                game->cur_scn = 5;
            }
            if (game->cur_scn == 6) {
                game->cur_scn = 4;
            }
            perso->pos.y = 300;
            perso->pos.x = 1800;
        } else
            perso->pos.x -= 0;
    }
    if (i == 4) {
        change_sprite(perso, "ressources/perso_right.png");
        if (game->scenes[scene].map[cur_y][cur_x] == '*' && \
game->scenes[scene].map[cur_y][cur_x + 1] == '*' && \
game->scenes[scene].map[btm_y][cur_x + 1] == '*')
            perso->pos.x += 8;
        else if (game->scenes[scene].map[cur_y][cur_x + 1] == 'L' ||\
game->scenes[scene].map[cur_y][cur_x + 1] == 'F') {
            if (game->cur_scn == 4) {
                game->cur_scn = 6;
            } else if (game->cur_scn == 5) {
                game->cur_scn = 4;
            }
            perso->pos.y = 300;
            perso->pos.x = 70;
        } else
            perso->pos.x += 0;
    }
    sfSprite_setPosition(perso->spr, perso->pos);

    /* Debug mode (positions - nearby tiles) */

    //printf(" %c \n%c%c%c\n %c\n", game->scenes[scene].map[cur_y - 1][cur_x], game->scenes[scene].map[cur_y][cur_x - 1], game->scenes[scene].map[cur_y][cur_x], game->scenes[scene].map[cur_y][cur_x + 1], game->scenes[scene].map[cur_y + 1][cur_x]);
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