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
            sfMusic_setVolume(game->cave_music, 4.5);
            sfMusic_pause(game->am_music);
            sfMusic_play(game->cave_music);
            game->cur_scn = 7;
            perso->pos.x = 928;
            perso->pos.y = 812;
        } else if (game->cur_scn == 4) {
            sfMusic_play(game->door);
            sfMusic_setVolume(game->door, 70);
            game->cur_scn = 8;
            perso->pos.x = 926;
            perso->pos.y = 632;
        }
    } else
        perso->pos.y -= 0;
}