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
    if (game->cur_scn == 8 && (perso->pos.y > \
sfSprite_getPosition(game->scenes[8].npc[0].spr).y)) {
        sfRenderWindow_drawSprite(window, game->scenes[8].npc[0].spr, NULL);
    }
    sfRenderWindow_drawSprite(window, perso->spr, NULL);
    if (game->cur_scn == 8 && (perso->pos.y <= \
sfSprite_getPosition(game->scenes[8].npc[0].spr).y)) {
        sfRenderWindow_drawSprite(window, game->scenes[8].npc[0].spr, NULL);
    }
    for (int i = 0; i != game->scenes[game->cur_scn].enemy_left; i++) {
        sfRenderWindow_drawSprite(window, \
game->scenes[game->cur_scn].enemy[i].spr, NULL);
    }
    sfRenderWindow_display(window);
}

int check_which_enemy(game_t game, int nmy_tested, sfVector2f perso_pos)
{
    sfFloatRect g_bnd = \
    sfSprite_getGlobalBounds(game.scenes[game.cur_scn].\
enemy[nmy_tested - 1].spr);
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
    int gameplay_scene = game.cur_scn;
    int enemys_nbr = 0;
    for (int i = 1; enemys_nbr == 0 && (i - 1) != \
game.scenes[game.cur_scn].enemy_left; i++)
        enemys_nbr = check_which_enemy(game, i, game.perso->pos);
    if (enemys_nbr > 0) {
        sfMusic_setVolume(game.am_music, 0);
        sfMusic_setVolume(game.cbt_music, 3.5);
        sfMusic_setLoop(game.cbt_music, sfTrue);
        sfMusic_play(game.cbt_music);
        game.cur_scn = 3;
        game.scenes[3].but_nbr = 2;
        game.scenes[3].obj_nbr = 2;
        init_combat_scene(game, window, \
&game.scenes[gameplay_scene].enemy[enemys_nbr - 1]);
        game = combat(window, game, \
&game.scenes[gameplay_scene].enemy[enemys_nbr - 1], gameplay_scene);
        game.scenes[game.cur_scn].enemy = NULL;
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

    while ((game.cur_scn >= 4 && game.cur_scn <= 8) && \
    sfRenderWindow_isOpen(window)) {
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
            enemy_anim_test(game.scenes[game.cur_scn].enemy, game);
            sfClock_restart(clock);
        }
    }
}