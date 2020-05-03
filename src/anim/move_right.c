/*
** EPITECH PROJECT, 2020
** move_right
** File description:
** function to move to the right
*/

#include "rpg.h"
#include "proto.h"

void move_right(game_t *game, perso_t *perso, int cur_x, int cur_y)
{
    int scene = game->cur_scn;
    int btm_y = (perso->pos.y + 48) / 32;

    change_sprite(perso, "ressources/perso_right.png");
    if (game->scenes[scene].map[cur_y][cur_x] == '*' && \
game->scenes[scene].map[cur_y][cur_x + 1] == '*' && \
game->scenes[scene].map[btm_y][cur_x + 1] == '*')
        perso->pos.x += 8;
    else if (game->scenes[scene].map[cur_y][cur_x + 1] == 'L' ||\
game->scenes[scene].map[cur_y][cur_x + 1] == 'F') {
        if (game->cur_scn == 4 && game->scenes[4].enemy_left == 0 && \
        game->scenes[5].enemy_left == 0 && game->scenes[7].enemy_left == 0) {
            game->cur_scn = 6;
            perso->pos.y = 300;
            perso->pos.x = 70;
        } else if (game->cur_scn == 5) {
            game->cur_scn = 4;
            perso->pos.y = 300;
            perso->pos.x = 70;
        }
    } else
        perso->pos.x += 0;
}