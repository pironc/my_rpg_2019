/*
** EPITECH PROJECT, 2020
** move_up
** File description:
** function to move upwards
*/

#include "rpg.h"
#include "proto.h"

void move_up(game_t *game, perso_t *perso, int cur_x, int cur_y)
{
    int scene = game->cur_scn;
    int top_y = (perso->pos.y + 16) / 32;
    int btm_y = (perso->pos.y + 48) / 32;
    int left_x = (perso->pos.x + 16) / 32;
    int right_x = (perso->pos.x + 48) / 32;

    change_sprite(perso, "ressources/perso_up.png");
    if (game->scenes[scene].map[cur_y][cur_x] == '*' && \
game->scenes[scene].map[btm_y - 1][cur_x] == '*' &&
game->scenes[scene].map[btm_y - 1][left_x] == '*' && game->scenes[scene].map\
[btm_y - 1][right_x] == '*')
        perso->pos.y -= 8;
    else if (game->scenes[scene].map[cur_y - 1][cur_x] == 'H') {
        if (game->cur_scn == 5) {
            game->cur_scn = 7;
        } else {
            perso->pos.x = 500;
            perso->pos.y = 500;
        }
    } else
        perso->pos.y -= 0;
}