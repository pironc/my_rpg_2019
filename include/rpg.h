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

typedef struct button_s {
    int state; //(idle, hover, clicked);
    sfSprite *spr;
    sfTexture *text;
    sfFont *font;
    sfRectangleShape *rect;
    sfVector2f pos_play;
    sfVector2f pos_options;
    sfVector2f pos_exit;
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

typedef struct inventory_s {
    obj_t **objcts;
    sfText **stats;
    sfSprite *perso_spr;
    sfTexture *perso_text;
    sfSprite *invent_spr;
    sfTexture *invent_text;
} invnt_t;

typedef struct perso_s {
    char *name;
    int hp;
    int max_hp;
    int attack;
    int armor;
    int level;
    int exp;
    int max_exp;
    int gold;
    int item_nbr;
    invnt_t invent;
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
    char **map;
    npc_t *npc;
    enemy_t *enemy;
    button_t *buttons;
    gm_obj_t *gm_objcts;
} scene_t;

typedef struct game_s {
    int cur_scn;
    filter_t *fade;
    scene_t *scenes;
    perso_t *perso;
    sfBool player_turn;
    sfMusic *am_music;
    sfMusic *menu_music;
    sfMusic *cbt_music;
    sfMusic *cave_music;
    sfMusic *lava;
    sfSound *door_sound;
    sfSoundBuffer *door;
    sfSound *oof_sound;
    sfSoundBuffer *oof;
    sfSoundBuffer *slash;
    sfSound *slash_sound;
} game_t;

#endif /* RPG_ */
