/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** proto.h
*/
#include "rpg.h"

/*----------Basic functions-----------*/

void my_putstr(char*);
char *nbr_str(int nb);
char **my_str_to_word_array_space(char *str);

/*----------RPG functions-------------*/

int my_rpg(void);
void check_perso(perso_t *perso);
void check_enemy(enemy_t **enemies);
void gameplay(sfRenderWindow *window, game_t game, perso_t *perso);
game_t back_to_gameplay(game_t game);
void rearrange_enemy_arr(game_t game);
void swap_enemy_places(game_t game, int i);
game_t check_collision_enemy(sfRenderWindow *window, game_t game);
void reset_window(sfRenderWindow *window, game_t *game, perso_t *perso);
void change_sprite(perso_t *perso, char *filepath);
void close_window(sfRenderWindow *window);

/*---------Draw RPG--------------*/

int draw_window(sfRenderWindow* window, game_t game);
void draw_elements(sfRenderWindow *window, game_t game);
void draw_menu_pause(sfRenderWindow *window, game_t game);
void draw_combat(sfRenderWindow *window, game_t game, enemy_t *enemy);
int position_of_back(sfRenderWindow *window, game_t game);
int position_of_options(sfRenderWindow *window, game_t game);
int position_of_exit(sfRenderWindow *window, game_t game);

/*---------Events RPG------------*/

game_t analyse_events(sfRenderWindow *window, sfEvent event, game_t game);
void analyse_move_event(sfRenderWindow *window, game_t *game, \
sfEvent event, perso_t *perso);
game_t analyse_combat_event(sfRenderWindow *window, sfEvent event, \
game_t game, enemy_t *enemy);
game_t button_is_clicked(sfRenderWindow *window, game_t game);
void perso_anim(perso_t *perso);
void enemy_anim_test(enemy_t **enemies, game_t game);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_perso(game_t *game, perso_t *perso, int i);

/*----------Init RPG-------------*/

game_t initialize_game(game_t game);
void init_perso(perso_t *perso);
void init_enemies(enemy_t **enemies);
gm_obj_t init_game_obj(gm_obj_t game_obj, char *filepath);
button_t init_button(button_t button, sfVector2f position, char *filepath);
void init_options_menu(game_t game);
void init_pause_menu(game_t game);
sfVector2f set_pos(int x, int y);
sfIntRect set_rect(int width, int height);
void init_game_scenes(game_t game);
void init_forest_map(game_t game);
maps_t *init_map(void);
void check_map(maps_t *map);
void init_combat_scene(game_t game, sfRenderWindow *window, enemy_t *enemy);
game_t button_is_clicked_menu(sfRenderWindow *window, game_t game);
char **open_map(char **tileset);

/*---------Combat RPG------------*/

game_t combat(sfRenderWindow *window, game_t game, enemy_t *enemy);
game_t init_intro(game_t game, sfVector2f board_pos, enemy_t *enemy);
enemy_t *refresh_hp_bar_enemy(sfRenderWindow *window, enemy_t *enemy);
game_t button_is_clicked_combat(sfRenderWindow *window, game_t game, \
enemy_t *enemy, sfEvent event);
game_t button_is_released_combat(sfRenderWindow *window, game_t game, \
enemy_t *enemy, sfEvent event);
void perso_charge_forward(sfRenderWindow *window, game_t game, enemy_t *enemy);
void earn_loot(game_t game, enemy_t *enemy);
void base_atk_hover(game_t game);
void base_atk_idle(game_t game);
void base_atk_dmg(sfRenderWindow *window, game_t game, enemy_t *enemy);
void base_atk_anim(sfRenderWindow *window, game_t game, enemy_t *enemy);
void dmg_anim(sfRenderWindow *window, game_t game, enemy_t *enemy, \
sfVector2f char_pos);
void heavy_atk_hover(game_t game);
void heavy_atk_idle(game_t game);
int check_hvy_atk_cd(sfRenderWindow *window, button_t hvy_atk_but);
void heavy_atk_dmg(sfRenderWindow *window, game_t game, enemy_t *enemy);

/*---------Destroy RPG-----------*/

void destroy_menu(game_t game);
void destroy_perso(perso_t *perso);
void destroy_enemy(enemy_t *enemy);
void destroy_map(maps_t *map);
