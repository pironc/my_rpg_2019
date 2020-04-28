/*
** EPITECH PROJECT, 2020
** combat
** File description:
** handles combat scene events
*/
#include "proto.h"
#include "rpg.h"

void combat_scene_intro(sfRenderWindow *window, game_t game, \
sfVector2f board_pos, sfVector2f but_pos)
{
    sfTime time;
    sfClock *clock = sfClock_create();
    float seconds;

    while (board_pos.y != 0) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0) {
            board_pos.y -= 5;
            but_pos.y -= 5;
            sfRenderWindow_drawSprite(window, \
game.scenes[3].gm_objcts[0].spr, NULL);
            sfRenderWindow_drawSprite(window, \
game.scenes[3].gm_objcts[1].spr, NULL);
            sfRenderWindow_drawSprite(window, \
game.scenes[3].buttons[0].spr, NULL);
            sfRenderWindow_drawSprite(window, game.perso->spr, NULL);
            sfRenderWindow_display(window);
            sfSprite_setPosition(game.scenes[3].gm_objcts[1].spr, board_pos);
            sfSprite_setPosition(game.scenes[3].buttons[0].spr, but_pos);
            sfClock_restart(clock);
        }
    }
}

enemy_t init_health_bar_combat(enemy_t enemy)
{
    sfVector2f hp_bar_pos = enemy.pos;
    sfVector2f size = {0, 43};
    sfColor fill_color = sfColor_fromRGBA(0, 0, 0, 255);
    hp_bar_t new_hp_bar;

    hp_bar_pos.y += 150;
    hp_bar_pos.x -= 250;
    new_hp_bar.rect = sfRectangleShape_create();
    new_hp_bar.hp_bar_spr = sfSprite_create();
    new_hp_bar.hp_bar_text = sfTexture_createFromFile("ressources/health_bar.png", NULL);
    sfSprite_setTexture(new_hp_bar.hp_bar_spr, new_hp_bar.hp_bar_text, sfTrue);
    sfSprite_setPosition(new_hp_bar.hp_bar_spr, hp_bar_pos);
    sfRectangleShape_setSize(new_hp_bar.rect, size);
    sfRectangleShape_setPosition(new_hp_bar.rect, hp_bar_pos);
    sfRectangleShape_setFillColor(new_hp_bar.rect, fill_color);
    enemy.hp_bar = new_hp_bar;

    return(enemy);
}

void init_combat_scene(game_t game, sfRenderWindow *window)
{
    int test = 0;
    sfVector2f pos_char = {50, 320};
    sfVector2f board_pos = {0, 500};
    sfVector2f but_pos = {75, 1275};
    sfVector2f scale_char = {6, 6};
    sfVector2f pos_hp_char = pos_char;

    pos_hp_char.y += 150;
    game.scenes[3].enemys = malloc(sizeof(enemy_t) * 1);
    game.scenes[3].gm_objcts = malloc(sizeof(gm_obj_t) * 2);
    game.scenes[3].buttons = malloc(sizeof(button_t) * 1);
    game.scenes[3].gm_objcts[0] = init_game_obj(game.scenes[3].gm_objcts[0], \
    "ressources/combat_bg/grass_plain_3.jpg");
    game.scenes[3].gm_objcts[1] = init_game_obj(game.scenes[3].gm_objcts[1], \
    "ressources/combat_bg/combat_ui_board.png");
    game.scenes[3].buttons[0] = init_button(game.scenes[3].buttons[0], \
    but_pos, "ressources/combat_bg/but/base_atk_idle.png");
    sfSprite_setPosition(game.perso->spr, pos_char);
    sfSprite_setScale(game.perso->spr, scale_char);
    sfSprite_setPosition(game.scenes[3].gm_objcts[1].spr, board_pos);
    sfSprite_setPosition(game.scenes[3].buttons[0].spr, but_pos);
    sfSprite_setPosition(game.perso->hp_bar.hp_bar_spr, pos_hp_char);
    sfRectangleShape_setPosition(game.perso->hp_bar.rect, pos_hp_char);
    combat_scene_intro(window, game, board_pos, but_pos);
    game.scenes[3].enemys[0] = init_health_bar_combat(game.scenes[3].enemys[0]);
}

game_t refresh_hp_bar_player(sfRenderWindow *window, game_t game)
{
    int player_percent = ((50 - game.perso->hp) * 100) / 50;
    int pixels_to_hide = (player_percent * 672) / 100;
    sfVector2f rect_size = {pixels_to_hide, 43};
    sfRectangleShape_setSize(game.perso->hp_bar.rect, rect_size);

    return(game);
}

enemy_t refresh_hp_bar_enemy(sfRenderWindow *window, enemy_t enemy)
{
    int enemy_percent = ((enemy.max_hp - enemy.hp) * 100) / enemy.max_hp;
    int pixels_to_hide = (enemy_percent * 672) / 100;
    sfVector2f rect_size = {pixels_to_hide, 43};
    sfRectangleShape_setSize(enemy.hp_bar.rect, rect_size);
    sfRenderWindow_drawRectangleShape(window, enemy.hp_bar.rect, NULL);
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

game_t enemy_attack(game_t game, enemy_t enemy)
{
    int total_damage = 0;

    total_damage = (enemy.attack) - (game.perso->armor / 2);
    game.perso->hp -= total_damage;

    return(game);
}

game_t combat(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    enemy_t *test_enemy = init_enemy_forest();

    game.player_turn = sfTrue;
    game.scenes[3].enemys[0] = *test_enemy;
    while (game.perso->hp > 0 && game.scenes[3].enemys[0].hp > 0) {
        draw_combat(window, game, game.scenes[3].enemys[0]);
        sfRenderWindow_display(window);
        while (game.player_turn == sfTrue) {
            game = analyse_combat_event(window, event, game);
        }
        if (game.player_turn == sfFalse) {
            enemy_attack(game, game.scenes[3].enemys[0]);
        }
        game.player_turn = change_turn(game.player_turn);
        if (game.perso->hp < 50) {
            game = refresh_hp_bar_player(window, game);
        }
    }
    my_putstr("YOU WON THE FIGHT !!!");
    game.cur_scn = 1;
    game.scenes[1].but_nbr = 1;
    game.scenes[1].obj_nbr = 1;

    return(game);
}