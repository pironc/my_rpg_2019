/*
** EPITECH PROJECT, 2020
** combat events
** File description:
** combat events
*/

#include "rpg.h"
#include "proto.h"

sfBool change_turn(sfBool player_turn)
{
    if (player_turn == sfTrue) {
        player_turn = sfFalse;
    } else {
        player_turn = sfTrue;
    }
    return (player_turn);
}

game_t enemy_attack(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    int total_damage = 0;

    enemy_charge_forward(window, game, enemy);
    total_damage = (enemy->attack) - (game.perso->armor / 2);
    game.perso->hp -= total_damage;
    if (game.perso->hp < 50) {
        game = refresh_hp_bar_player(window, game);
    }

    return (game);
}

void earn_loot(game_t game, enemy_t *enemy)
{
    game.perso->exp += enemy->giv_xp;
    if (game.perso->exp >= game.perso->max_exp) {
        game.perso->exp = 0;
        game.perso->max_exp = 15;
        game.perso->level++;
        game.perso->attack += 2;
        game.perso->armor += 1;
        game.perso->max_hp += 5;
    }
    if (game.perso->level == 3) {
        game.perso->hp = game.perso->max_hp;
    }
}

game_t back_to_gameplay(game_t game)
{
    sfVector2f scale_pers = {1, 1};
    sfMusic_stop(game.cbt_music);
    sfMusic_play(game.am_music);
    sfSprite_setScale(game.perso->spr, scale_pers);
}