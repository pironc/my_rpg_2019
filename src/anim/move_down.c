/*
** EPITECH PROJECT, 2020
** move_down
** File description:
** function to move downwards
*/

#include "rpg.h"
#include "proto.h"

void move_down(game_t *game, perso_t *perso, int cx, int cy)
{
    int scene = game->cur_scn;
    int lx = (perso->pos.x + 16) / 32;
    int rx = (perso->pos.x + 48) / 32;

    change_sprite(perso, "ressources/perso_down.png");
    if (game->scenes[scene].map[cy][cx] == '*' && \
game->scenes[scene].map[cy + 1][cx] == '*' && \
game->scenes[scene].map[cy + 1][lx] == '*' && game->scenes[scene].map\
[cy + 1][rx] == '*')
        perso->pos.y += 8;
    else if (game->scenes[scene].map[cy + 1][lx] == 'D'&& game->cur_scn == 7) {
        game->cur_scn = 5;
        perso->pos.x = 960;
        perso->pos.y = 420;
    } else if (game->scenes[scene].map[cy + 1][lx] == 'F'\
&& game->cur_scn == 8) {
        game->cur_scn = 4;
        perso->pos.x = 512;
        perso->pos.y = 386;
    } else
        perso->pos.y += 0;
}