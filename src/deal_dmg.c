/*
** EPITECH PROJECT, 2020
** deal dmg to monsters
** File description:
** functions that handles dmg dealing to monsters through atacks
*/

#include "proto.h"
#include "rpg.h"

void base_atk_dmg(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    enemy->hp -= game.perso->attack;
    game.player_turn = sfFalse;
    enemy = refresh_hp_bar_enemy(window, enemy);
}