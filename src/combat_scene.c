/*
** EPITECH PROJECT, 2020
** combat
** File description:
** handles combat scene events
*/
#include "proto.h"
#include "rpg.h"

enemy_t *init_health_bar_combat(enemy_t *enemy)
{
    sfVector2f hp_bar_pos = sfSprite_getPosition(enemy->spr);
    sfVector2f size = {0, 43};
    sfColor fill_color = sfColor_fromRGBA(0, 0, 0, 255);

    hp_bar_pos.x -= 250;
    hp_bar_pos.y += 175;
    enemy->hp_bar.rect = sfRectangleShape_create();
    enemy->hp_bar.hp_bar_spr = sfSprite_create();
    enemy->hp_bar.hp_bar_text = sfTexture_createFromFile("ressources/health_bar.png", NULL);
    sfSprite_setTexture(enemy->hp_bar.hp_bar_spr, enemy->hp_bar.hp_bar_text, sfTrue);
    sfSprite_setPosition(enemy->hp_bar.hp_bar_spr, hp_bar_pos);
    sfRectangleShape_setSize(enemy->hp_bar.rect, size);
    sfRectangleShape_setPosition(enemy->hp_bar.rect, hp_bar_pos);
    sfRectangleShape_setFillColor(enemy->hp_bar.rect, fill_color);

    return(enemy);
}

game_t init_intro(game_t game, sfVector2f board_pos, enemy_t *enemy)
{
    sfVector2f base_atk_pos = {0, 0};
    sfVector2f nmy_pos = {1500, 320};
    sfVector2f nmy_scale = {3, 3};

    game.scenes[3].buttons[0] = init_button(game.scenes[3].buttons[0], \
    base_atk_pos, "ressources/combat_bg/but/base_atk_idle.png");
    game.scenes[3].buttons[1] = init_button(game.scenes[3].buttons[1], \
    base_atk_pos, "ressources/combat_bg/but/heavy_atk_idle.png");
    sfSprite_setPosition(game.scenes[3].gm_objcts[1].spr, board_pos);
    sfSprite_setScale(enemy->spr, nmy_scale);
    sfSprite_setPosition(enemy->spr, nmy_pos);
    enemy = init_health_bar_combat(enemy);

    return(game);
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
            sfSprite_setPosition(game.scenes[3].buttons[0].spr, but_pos);
            sfClock_restart(clock);
        }
    }
    return (game);
}

void init_combat_scene(game_t game, sfRenderWindow *window, enemy_t *enemy)
{
    sfVector2f pos_char = {50, 320};
    sfVector2f scale_char = {2, 2};
    sfVector2f pos_hp_char = pos_char;

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
    game = combat_scene_intro(window, game, enemy);
}

game_t refresh_hp_bar_player(sfRenderWindow *window, game_t game)
{
    int player_percent = ((50 - game.perso->hp) * 100) / 50;
    int pixels_to_hide = (player_percent * 672) / 100;
    sfVector2f rect_size = {pixels_to_hide, 43};
    sfRectangleShape_setSize(game.perso->hp_bar.rect, rect_size);

    return(game);
}

enemy_t *refresh_hp_bar_enemy(sfRenderWindow *window, enemy_t *enemy)
{
    int enemy_percent = ((enemy->max_hp - enemy->hp) * 100) / enemy->max_hp;
    int pixels_to_hide = (enemy_percent * 672) / 100;
    sfVector2f rect_size = {pixels_to_hide, 43};
    sfRectangleShape_setSize(enemy->hp_bar.rect, rect_size);
    sfRenderWindow_drawRectangleShape(window, enemy->hp_bar.rect, NULL);
    sfRenderWindow_display(window);

    return(enemy);
}

sfBool change_turn(sfBool player_turn)
{
    if (player_turn == sfTrue) {
        player_turn = sfFalse;
    } else {
        player_turn = sfTrue;
    }
    return (player_turn);
}

game_t enemy_attack(game_t game, enemy_t *enemy)
{
    int total_damage = 0;

    total_damage = (enemy->attack) - (game.perso->armor / 2);
    game.perso->hp -= total_damage;

    return(game);
}

void earn_loot(game_t game, enemy_t *enemy)
{
    game.perso->exp += enemy->giv_xp;
}

game_t back_to_gameplay(game_t game)
{
    sfVector2f scale_pers = {1, 1};
    game.cur_scn = 4;
    game.scenes[4].but_nbr = 0;
    game.scenes[4].obj_nbr = 1;
    sfSprite_setScale(game.perso->spr, scale_pers);
}

game_t combat(sfRenderWindow *window, game_t game, enemy_t *enemy)
{
    sfEvent event;

    game.player_turn = sfTrue;
    while (game.perso->hp > 0 && enemy->hp > 0) {
        draw_combat(window, game, enemy);
        sfRenderWindow_display(window);
        while (game.player_turn == sfTrue && sfRenderWindow_isOpen(window)) {
            game = analyse_combat_event(window, event, game, enemy);
        }
        if (game.player_turn == sfFalse) {
            enemy_attack(game, enemy);
        }
        game.player_turn = change_turn(game.player_turn);
        if (game.perso->hp < 50) {
            game = refresh_hp_bar_player(window, game);
        }
    }
    if (enemy->hp <= 0) {
        earn_loot(game, enemy);
        destroy_enemy(enemy);
        game.scenes[4].enemy_left--;
    } else {
        //GAME_OVER;
    }
    back_to_gameplay(game);
    return(game);
}