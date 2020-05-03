/*
** EPITECH PROJECT, 2020
** draw
** File description:
** draw
*/
#include "proto.h"
#include "rpg.h"

void draw_elements(sfRenderWindow *window, game_t game)
{
    for (int i = 0; i != game.scenes[game.cur_scn].obj_nbr; i++) {
        sfRenderWindow_drawSprite(window, \
game.scenes[game.cur_scn].gm_objcts[i].spr, NULL);
    }
    for (int i = 0; i != game.scenes[game.cur_scn].but_nbr; i++) {
        sfRenderWindow_drawSprite(window, \
game.scenes[game.cur_scn].buttons[i].spr, NULL);
    }
}

int pause_menu_ing(sfRenderWindow *window, sfEvent event, game_t game, \
int flag)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (position_of_back(window, game) && \
sfMouse_isButtonPressed(sfMouseLeft))
            flag = 1;
        if (position_of_exit(window, game) && \
sfMouse_isButtonPressed(sfMouseLeft))
            flag = 2;
        if (event.type == sfEvtClosed) {
            flag = 3;
        }
    }
    return (flag);
}

void draw_menu_pause(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    int flag = 0;

    while (1) {
        sfRenderWindow_drawSprite(window, game.scenes[2].gm_objcts[0].spr, \
NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[0].spr, NULL);
        sfRenderWindow_drawSprite(window, game.scenes[2].buttons[2].spr, NULL);
        sfRenderWindow_display(window);
        sfMusic_pause(game.am_music);
        flag = pause_menu_ing(window, event, game, flag);
        if (flag == 1) {
            sfMusic_play(game.am_music);
            break;
        }
        if (flag == 2) {
            sfMusic_destroy(game.cave_music);
            sfMusic_destroy(game.cbt_music);
            sfMusic_stop(game.am_music);
            sfMusic_destroy(game.am_music);
            sfMusic_destroy(game.menu_music);
            sfSound_destroy(game.door_sound);
            sfSoundBuffer_destroy(game.door);
            close_window(window);
            break;
        }
        if (flag == 3) {
            sfMusic_destroy(game.cave_music);
            sfMusic_destroy(game.cbt_music);
            sfMusic_stop(game.am_music);
            sfMusic_destroy(game.am_music);
            sfMusic_destroy(game.menu_music);
            sfSound_destroy(game.door_sound);
            sfSoundBuffer_destroy(game.door);
            close_window(window);
            break;
        }
    }
}

void draw_combat(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    for (int i = 0; i != game.scenes[3].obj_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[3].gm_objcts[i].spr, \
NULL);
    }
    for (int i = 0; i != game.scenes[3].but_nbr; i++) {
        sfRenderWindow_drawSprite(window, game.scenes[3].buttons[i].spr, NULL);
    }
    sfRenderWindow_drawSprite(window, game.perso->spr, NULL);
    sfRenderWindow_drawSprite(window, enemy->spr, NULL);
    sfRenderWindow_drawSprite(window, game.perso->hp_bar.hp_bar_spr, NULL);
    sfRenderWindow_drawSprite(window, enemy->hp_bar.hp_bar_spr, NULL);
    sfRenderWindow_drawRectangleShape(window, game.perso->hp_bar.rect, NULL);
    sfRenderWindow_drawRectangleShape(window, enemy->hp_bar.rect, NULL);
}

void draw_vertex(window)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertex vertex;
    sfVector2f apos = {1, 1};
    vertex.color = sfRed;
    vertex.position = apos;
    sfVertexArray_setPrimitiveType(array, sfPoints);
    sfRenderTexture_drawVertexArray(window, array, NULL);
    //sfVertexArray_append(array, a);

    //sfRenderWindow_drawVertexArray(window, array, 0);
}

int draw_window(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    //game.all_map = init_map();
    //check_map(game.all_map);
    //check_enemy(game.enemies);
    //check_perso(game.perso);
    sfMusic_setLoop(game.menu_music, sfTrue);
    sfMusic_play(game.menu_music);

    while (sfRenderWindow_isOpen(window)) {
        draw_vertex(window);
        game = analyse_events(window, event, game);
        sfRenderWindow_clear(window, sfBlack);
        draw_elements(window, game);
        gameplay(window, game, game.perso);
        sfRenderWindow_display(window);
    }
    destroy_perso(game.perso);
    //destroy_map(game.all_map);
    return (0);
}