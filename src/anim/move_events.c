/*
** EPITECH PROJECT, 2020
** move event
** File description:
** move event
*/
#include "proto.h"
#include "rpg.h"

void key_pressed(sfRenderWindow *window, sfEvent event, \
perso_t *perso, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue || \
    sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        move_perso(game, perso, 1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue || \
    sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        move_perso(game, perso, 2);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue || \
        sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        move_perso(game, perso, 3);
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue || \
        sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        move_perso(game, perso, 4);
}

void analyse_move_event(sfRenderWindow *window, game_t *game, \
sfEvent event, perso_t *perso)
{
    //if (event.type == sfEvtKeyPressed)
        key_pressed(window, event, perso, game);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            game->cur_scn = 0;
            close_window(window);
        }
        if (event.type == sfEvtKeyReleased) {
            change_sprite(perso, "ressources/perso_static_down.png");
        }
    }
}
