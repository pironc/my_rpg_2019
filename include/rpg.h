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

#ifndef RPG_
#define RPG_

typedef struct button_s {
    int state; //(idle, hover, clicked);
    sfSprite *spr;
    sfTexture *text;
    sfFont *font;
    sfRectangleShape *rect;
    void (*callback)();
} button_t;

typedef struct npc_s {
    //int hp;
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

typedef struct object_s {
    char *name;
    int quantity;
    sfSprite *spr;
    sfTexture *text;
} obj_t;

typedef struct abilities_s {
    float ratio;
    char *name;
} abili_t;

typedef struct perso_s {
    char *name;
    int hp;
    int attack;
    int armor;
    int level;
    int exp;
    int gold;
    obj_t **invent;
    sfSprite *spr;
    sfTexture *text;
    abili_t **all_abili;
    sfVector2f pos;
    sfIntRect rect;
} perso_t;

typedef struct enemy_s {
    char *name;
    int hp;
    int attack;
    int armor;
    int giv_xp;
    //int giv_gold;
    sfSprite *spr;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} enemy_t;

typedef struct game_s {
    int cur_scn;
    filter_t fade;
    scene_t *scenes;
    perso_t *perso;
    enemy_t **enemies;
} game_t;



void my_putstr(char*);
void destroy_menu(game_t game);
int my_rpg(void);
int draw_window(sfRenderWindow* window, game_t game);
game_t analyse_events(sfRenderWindow*window, sfEvent event, game_t game);
void close_window(sfRenderWindow *window);
game_t initialize_game(game_t game);
void init_perso(perso_t *perso);
gm_obj_t init_game_obj(gm_obj_t game_obj, char *filepath);
button_t init_button(button_t button, sfVector2f position, char *filepath);
void check_perso(perso_t *perso);
void gameplay(sfRenderWindow *window, game_t *game, perso_t *perso);
sfVector2f set_pos(int x, int y);
sfIntRect set_rect(int width, int height);
void perso_anim(perso_t *perso);
void move_rect(sfIntRect *rect, int offset, int max_value);
void draw_elements(sfRenderWindow *window, game_t game);
void analyse_move_event(sfRenderWindow *window, game_t *game, \
sfEvent event, perso_t *perso);
void move_perso(perso_t *perso, int i);
void change_sprite(perso_t *perso, char *filepath);
void destroy_perso(perso_t *perso);
void reset_window(sfRenderWindow *window, game_t *game, perso_t *perso);
void init_enemies(enemy_t **enemies);
void check_enemy(enemy_t **enemies);
void enemy_anim_test(enemy_t **enemies);

#endif /* RPG_ */
