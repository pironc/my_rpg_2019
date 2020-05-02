/*
** EPITECH PROJECT, 2020
** intro combat
** File description:
** intro combat
*/

#include "rpg.h"
#include "proto.h"

enemy_t *init_health_bar_combat(enemy_t *enemy)
{
    sfVector2f hp_bar_pos = sfSprite_getPosition(enemy->spr);
    sfVector2f size = {0, 43};
    sfColor fill_color = sfColor_fromRGBA(0, 0, 0, 255);

    hp_bar_pos.x -= 250;
    hp_bar_pos.y += 175;
    enemy->hp_bar.rect = sfRectangleShape_create();
    enemy->hp_bar.hp_bar_spr = sfSprite_create();
    enemy->hp_bar.hp_bar_text = sfTexture_createFromFile\
    ("ressources/health_bar.png", NULL);
    sfSprite_setTexture(enemy->hp_bar.hp_bar_spr, \
    enemy->hp_bar.hp_bar_text, sfTrue);
    sfSprite_setPosition(enemy->hp_bar.hp_bar_spr, hp_bar_pos);
    sfRectangleShape_setSize(enemy->hp_bar.rect, size);
    sfRectangleShape_setPosition(enemy->hp_bar.rect, hp_bar_pos);
    sfRectangleShape_setFillColor(enemy->hp_bar.rect, fill_color);
    return (enemy);
}

game_t init_intro(game_t game, sfVector2f board_pos, enemy_t *enemy)
{
    sfVector2f base_atk_pos = {75, 800};
    sfVector2f hvy_atk_pos = {75, 900};
    sfVector2f nmy_pos = {1500, 320};
    sfVector2f nmy_scale = {3, 3};

    game.scenes[3].buttons[0] = init_button(game.scenes[3].buttons[0], \
    base_atk_pos, "ressources/combat_bg/but/base_atk_idle.png");
    game.scenes[3].buttons[1] = init_button(game.scenes[3].buttons[1], \
    hvy_atk_pos, "ressources/combat_bg/but/heavy_atk_idle.png");
    sfSprite_setPosition(game.scenes[3].gm_objcts[1].spr, board_pos);
    sfSprite_setScale(enemy->spr, nmy_scale);
    sfSprite_setPosition(enemy->spr, nmy_pos);
    enemy = init_health_bar_combat(enemy);
    return (game);
}

game_t combat_scene_intro(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    sfVector2f board_pos = {0, 500};
    sfVector2f but_pos = {75, 1275};
    sfTime time;
    sfClock *clock = sfClock_create();
    float seconds;

    game = init_intro(game, board_pos, enemy);
    while (board_pos.y != 0) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0) {
            board_pos.y -= 5;
            sfRenderWindow_drawSprite(window, \
game.scenes[3].gm_objcts[0].spr, NULL);
            sfRenderWindow_drawSprite(window, \
game.scenes[3].gm_objcts[1].spr, NULL);
            sfRenderWindow_drawSprite(window, game.perso->spr, NULL);
            sfRenderWindow_drawSprite(window, enemy->spr, NULL);
            sfRenderWindow_display(window);
            sfSprite_setPosition(game.scenes[3].gm_objcts[1].spr, board_pos);
            sfClock_restart(clock);
        }
    }
    return (game);
}

void init_combat_scene(game_t game, sfRenderWindow *window, enemy_t *enemy)
{
    sfVector2f pos_char = {50, 320};
    sfVector2f scale_char = {2, 2};
    sfVector2f scale_hp_bar = {1, 1};
    sfVector2f pos_hp_char = pos_char;
    float angle = 0;

    pos_hp_char.y += 150;
    game.scenes[3].gm_objcts = malloc(sizeof(gm_obj_t) * 2);
    game.scenes[3].buttons = malloc(sizeof(button_t) * 2);
    game.scenes[3].gm_objcts[0] = init_game_obj(game.scenes[3].gm_objcts[0], \
    "ressources/combat_bg/grass_plain_3.jpg");
    game.scenes[3].gm_objcts[1] = init_game_obj(game.scenes[3].gm_objcts[1], \
    "ressources/combat_bg/combat_ui_board.png");
    change_sprite(game.perso, "ressources/perso_right.png");
    sfSprite_setPosition(game.perso->spr, pos_char);
    sfSprite_setScale(game.perso->spr, scale_char);
    sfSprite_setPosition(game.perso->hp_bar.hp_bar_spr, pos_hp_char);
    sfRectangleShape_setPosition(game.perso->hp_bar.rect, pos_hp_char);
    sfSprite_setRotation(game.perso->hp_bar.hp_bar_spr, angle);
    sfRectangleShape_setRotation(game.perso->hp_bar.rect, angle);
    sfSprite_setScale(game.perso->hp_bar.hp_bar_spr, scale_hp_bar);
    sfRectangleShape_setScale(game.perso->hp_bar.rect, scale_hp_bar);
    sfRectangleShape_setPosition(game.perso->hp_bar.rect, pos_hp_char);
    game = combat_scene_intro(window, game, enemy);
}