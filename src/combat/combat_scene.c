/*
** EPITECH PROJECT, 2020
** combat
** File description:
** handles combat scene events
*/
#include "proto.h"
#include "rpg.h"

game_t refresh_hp_bar_player(sfRenderWindow *window, game_t game)
{
    int player_percent = ((50 - game.perso->hp) * 100) / 50;
    int pixels_to_hide = (player_percent * 672) / 100;
    sfVector2f rect_size = {pixels_to_hide, 43};
    sfRectangleShape_setSize(game.perso->hp_bar.rect, rect_size);
    return (game);
}

enemy_t *refresh_hp_bar_enemy(sfRenderWindow *window, enemy_t *enemy)
{
    int enemy_percent = ((enemy->max_hp - enemy->hp) * 100) / enemy->max_hp;
    int pixels_to_hide = (enemy_percent * 672) / 100;
    sfVector2f rect_size = {pixels_to_hide, 43};
    sfRectangleShape_setSize(enemy->hp_bar.rect, rect_size);
    sfRenderWindow_drawRectangleShape(window, enemy->hp_bar.rect, NULL);
    sfRenderWindow_display(window);
    return (enemy);
}

void game_loop(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    sfEvent event;

    while (game.perso->hp > 0 && enemy->hp > 0) {
        draw_combat(window, game, enemy);
        sfRenderWindow_display(window);
        while (game.player_turn == sfTrue && sfRenderWindow_isOpen(window)) {
            game = analyse_combat_event(window, event, game, enemy);
        }
        if (game.player_turn == sfFalse) {
            enemy_attack(window, game, enemy);
        }
        game.player_turn = change_turn(game.player_turn);
    }
}

game_t combat(sfRenderWindow *window, game_t game, enemy_t *enemy, int gameplay_scene)
{
    game.player_turn = sfTrue;
    game_loop(window, game, enemy);
    if (enemy->hp <= 0) {
        earn_loot(game, enemy);
        destroy_enemy(enemy);
        game.scenes[gameplay_scene].enemy_left = 0;
    } else {
        game_over(window, game.perso, game, enemy);
    }
    back_to_gameplay(game);
    return (game);
}