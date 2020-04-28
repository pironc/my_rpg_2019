/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** gameplay
*/
#include "proto.h"
#include "rpg.h"

void reset_window(sfRenderWindow *window, game_t *game, perso_t *perso)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_elements(window, *game);
    sfRenderWindow_drawSprite(window, perso->spr, NULL);
    for (int i = 0; i != game->scenes[game->cur_scn].enemy_left; i++) {
        sfRenderWindow_drawSprite(window, game->enemies[i]->spr, NULL);
    }
    sfRenderWindow_display(window);
}

int check_which_enemy(game_t game, int nmy_tested, sfVector2f perso_pos)
{
    sfFloatRect g_bnd = sfSprite_getGlobalBounds(game.enemies[nmy_tested - 1]->spr);
    if (perso_pos.x >= g_bnd.left && perso_pos.x <= (g_bnd.left + g_bnd.width)) {
        if (perso_pos.y <= (g_bnd.top + g_bnd.height) && perso_pos.y >= g_bnd.top) {
            return (nmy_tested);
        }
    }
    return (0);
}

game_t check_collision_enemy(sfRenderWindow *window, game_t game)
{
    int enemys_nbr = 0;
    for (int i = 1; enemys_nbr == 0 && (i - 1) != game.scenes[1].enemy_left; i++)
        enemys_nbr = check_which_enemy(game, i, game.perso->pos);
    if (enemys_nbr > 0) {
        game.cur_scn = 3;
        game.scenes[3].but_nbr = 1;
        game.scenes[3].obj_nbr = 2;
        init_combat_scene(game, window, game.enemies[enemys_nbr - 1]);
        game = combat(window, game, game.enemies[enemys_nbr - 1]);
        game.enemies[enemys_nbr - 1] = NULL;
    }
    return (game);
}

void gameplay(sfRenderWindow *window, game_t game, perso_t *perso)
{
    sfClock *clock = sfClock_create();
    float seconds;
    sfEvent event;
    sfTime time;

    while (game.cur_scn == 1) {
        reset_window(window, &game, perso);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.000;
        check_collision_enemy(window, game);
        analyse_move_event(window, &game, event, perso);
        if (seconds > 0.2) {
            perso_anim(perso);
            enemy_anim_test(game.enemies, game);
            sfClock_restart(clock);
        }
    }
}