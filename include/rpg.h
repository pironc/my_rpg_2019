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

#define MENU 0
#define OPTION 1
#define PAUSE 2
#define HOW_TO_PLAY 9

#ifndef RPG_
#define RPG_

typedef struct map_s {
    char **forest;
    char **desert;
    char **lava;
    char ***maps;
} maps_t;

typedef struct button_s {
    int state; //(idle, hover, clicked);
    sfSprite *spr;
    sfTexture *text;
    sfFont *font;
    sfRectangleShape *rect;
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

typedef struct hp_bar_s {
    sfRectangleShape *rect;
    sfSprite *hp_bar_spr;
    sfTexture *hp_bar_text;
} hp_bar_t;

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
    int max_hp;
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
    hp_bar_t hp_bar;
} perso_t;

typedef struct enemy_s {
    char *name;
    int hp;
    int max_hp;
    int attack;
    int armor;
    int giv_xp;
    //int giv_gold;
    hp_bar_t hp_bar;
    sfSprite *spr;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} enemy_t;

typedef struct scene_s {
    int but_nbr;
    int obj_nbr;
    int enemy_left;
    char *name;
    enemy_t *enemys;
    button_t *buttons;
    gm_obj_t *gm_objcts;
} scene_t;

typedef struct game_s {
    int cur_scn;
    filter_t *fade;
    scene_t *scenes;
    perso_t *perso;
    enemy_t **enemies;
    maps_t **all_map;
    sfBool player_turn;
} game_t;

#endif /* RPG_ */
