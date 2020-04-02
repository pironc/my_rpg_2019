/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/
#include <stddef.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#ifndef MYDEF_
#define MYDEF_

typedef struct button_s {
    int state; //(idle, hover, clicked);
    sfSprite *spr;
    sfTexture *text;
} button_t;

typedef struct npc_s {
    int hp;
    char *name;
    sfSprite *spr;
    sfTexture *text;
} npc_t;

typedef struct gm_obj_s {
    sfSprite *spr;
    sfTexture *text;
} gm_obj_t;

typedef struct filter_s {
    int active;
    float seconds;
    sfClock *fade_clock;
    sfTime timer;
    sfColor transparent;
    sfRectangleShape *rect;
} filter_t;

typedef struct scene_s {
    int but_nbr;
    int obj_nbr;
    button_t *buttons;
    gm_obj_t *gm_objcts;
} scene_t;

typedef struct game_s {
    int cur_scn;
    filter_t fade;
    scene_t *scenes;
} game_t;

void my_putstr(char*);
void destroy_menu(game_t game);
int my_rpg(void);
int draw_window(sfRenderWindow* window, game_t game);
game_t analyse_events(sfRenderWindow*window, sfEvent event, game_t game);
void close_window(sfRenderWindow *window);
game_t initialize_game(game_t game);

#endif /* MYDEF_ */
