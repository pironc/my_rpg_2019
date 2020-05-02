/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** gameplay
*/
#include "proto.h"
#include "rpg.h"

void draw_leaves(sfRenderWindow *window, game_t *game, perso_t *perso)
{
    sfSprite *leavesSprite = sfSprite_create();
    sfTexture *leavesTexture = sfTexture_createFromFile("\
    ressources/leaves.png", NULL);
    sfSprite_setTexture(leavesSprite, leavesTexture, sfTrue);
    if (game->cur_scn == 4)
        sfRenderWindow_drawSprite(window, leavesSprite, NULL);
}

void reset_window(sfRenderWindow *window, game_t *game, perso_t *perso)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_elements(window, *game);
    sfRenderWindow_drawSprite(window, perso->spr, NULL);
    for (int i = 0; i != game->scenes[game->cur_scn].enemy_left; i++) {
        sfRenderWindow_drawSprite(window, game->enemies[i]->spr, NULL);
    }
    //draw_leaves(window, game, perso);
    sfRenderWindow_display(window);
}

int check_which_enemy(game_t game, int nmy_tested, sfVector2f perso_pos)
{
    sfFloatRect g_bnd = \
    sfSprite_getGlobalBounds(game.enemies[nmy_tested - 1]->spr);
    if (perso_pos.x >= g_bnd.left && perso_pos.x <= \
    (g_bnd.left + g_bnd.width)) {
        if (perso_pos.y <= (g_bnd.top + g_bnd.height) && \
perso_pos.y >= g_bnd.top) {
            return (nmy_tested);
        }
    }
    return (0);
}

game_t check_collision_enemy(sfRenderWindow *window, game_t game)
{
    int enemys_nbr = 0;
    for (int i = 1; enemys_nbr == 0 && (i - 1) != \
game.scenes[game.cur_scn].enemy_left; i++)
        enemys_nbr = check_which_enemy(game, i, game.perso->pos);
    if (enemys_nbr > 0) {
        game.cur_scn = 3;
        game.scenes[3].but_nbr = 2;
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
    sfClock *clock2 = sfClock_create();
    float seconds;
    sfTime time;
    sfEvent event;

    while (game.cur_scn >= 4 && sfRenderWindow_isOpen(window)) {
        reset_window(window, &game, perso);
        time = sfClock_getElapsedTime(clock2);
        seconds = time.microseconds / 1000000.000;
        check_collision_enemy(window, game);
        if (seconds > 0.020 && sfRenderWindow_isOpen(window)) {
            analyse_events(window, event, game);
            analyse_move_event(window, &game, event, perso);
            sfClock_restart(clock2);
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.000;
        if (seconds > 0.2 && sfRenderWindow_isOpen(window)) {
            perso_anim(perso);
            enemy_anim_test(game.enemies, game);
            sfClock_restart(clock);
        }
    }
}