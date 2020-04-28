/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** proto.h
*/
#include "rpg.h"

/*----------Basic functions-----------*/

void my_putstr(char*);

/*----------RPG functions-------------*/

int my_rpg(void);
void check_perso(perso_t *perso);
void check_enemy(enemy_t **enemies);
void gameplay(sfRenderWindow *window, game_t *game, perso_t *perso);
void reset_window(sfRenderWindow *window, game_t *game, perso_t *perso);
void change_sprite(perso_t *perso, char *filepath);
void close_window(sfRenderWindow *window);

/*---------Draw RPG--------------*/

int draw_window(sfRenderWindow* window, game_t game);
void draw_elements(sfRenderWindow *window, game_t game);

/*---------Events RPG------------*/

game_t analyse_events(sfRenderWindow*window, sfEvent event, game_t game);
void analyse_move_event(sfRenderWindow *window, game_t *game, \
sfEvent event, perso_t *perso);
void perso_anim(perso_t *perso);
void enemy_anim_test(enemy_t **enemies);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_perso(perso_t *perso, int i);

/*----------Init RPG-------------*/

game_t initialize_game(game_t game);
void init_perso(perso_t *perso);
void init_enemies(enemy_t **enemies);
gm_obj_t init_game_obj(gm_obj_t game_obj, char *filepath);
button_t init_button(button_t button, sfVector2f position, char *filepath);
sfVector2f set_pos(int x, int y);
sfIntRect set_rect(int width, int height);

/*---------Destroy RPG-----------*/

void destroy_menu(game_t game);
void destroy_perso(perso_t *perso);