/*
** EPITECH PROJECT, 2020
** deal dmg to monsters
** File description:
** functions that handles dmg dealing to monsters through atacks
*/

#include "proto.h"
#include "rpg.h"

void hvy_atk_unavailable(game_t game)
{
    ;
}

int check_hvy_atk_cd(sfRenderWindow *window, button_t hvy_atk_but)
{
    sfTexture *text = sfTexture_createFromFile("ressources/combat_bg/but/unavailable_hvy_atk.png", NULL);
    static int turn_before_available;

    if (turn_before_available == 0) {
        turn_before_available = 2;
        sfSprite_setTexture(hvy_atk_but.spr, text, sfTrue);
        sfRenderWindow_drawSprite(window, hvy_atk_but.spr, NULL);
        return (0);
    } else {
        turn_before_available--;
        if (turn_before_available == 0) {
            sfSprite_setTexture(hvy_atk_but.spr, hvy_atk_but.text, sfTrue);
            sfRenderWindow_drawSprite(window, hvy_atk_but.spr, NULL);
        }
        return (turn_before_available + 1);
    }
}

void heavy_atk_dmg(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    enemy->hp -= (game.perso->attack * 2);
    game.player_turn = sfFalse;
    enemy = refresh_hp_bar_enemy(window, enemy);
}

void base_atk_dmg(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    enemy->hp -= game.perso->attack;
    game.player_turn = sfFalse;
    enemy = refresh_hp_bar_enemy(window, enemy);
}