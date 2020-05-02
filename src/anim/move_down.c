/*
** EPITECH PROJECT, 2020
** move_down
** File description:
** function to move downwards
*/

#include "rpg.h"
#include "proto.h"

void move_down(game_t *game, perso_t *perso, int cur_x, int cur_y)
{
    int scene = game->cur_scn;
    int left_x = (perso->pos.x + 16) / 32;
    int right_x = (perso->pos.x + 48) / 32;

    change_sprite(perso, "ressources/perso_down.png");
    if (game->scenes[scene].map[cur_y][cur_x] == '*' && \
game->scenes[scene].map[cur_y + 1][cur_x] == '*' && \
game->scenes[scene].map[cur_y + 1][left_x] == '*' && game->scenes[scene].map\
[cur_y + 1][right_x] == '*')
        perso->pos.y += 8;
    else
        perso->pos.y += 0;
}