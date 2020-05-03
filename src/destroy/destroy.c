/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy elemnts when changing scenes
*/
#include "proto.h"
#include "rpg.h"

void destroy_menu(game_t game)
{
    sfSprite_destroy(game.scenes[0].gm_objcts[0].spr);
    sfTexture_destroy(game.scenes[0].gm_objcts[0].text);
    for (int i = 0; i != 3; i++) {
        sfSprite_destroy(game.scenes[0].buttons[i].spr);
        sfTexture_destroy(game.scenes[0].buttons[i].text);
    }
}

void destroy_perso(perso_t *perso)
{
    sfSprite_destroy(perso->spr);
    sfTexture_destroy(perso->text);
    for (int i = 0; perso->invent.objcts[i]; i++) {
        sfSprite_destroy(perso->invent.objcts[i]->spr);
        sfTexture_destroy(perso->invent.objcts[i]->text);
        free(perso->invent.objcts[i]);
    }
    for (int i = 0; perso->all_abili[i]; i++) {
        free(perso->all_abili[i]);
    }
}

void destroy_enemy(enemy_t *enemy)
{
    sfRectangleShape_destroy(enemy->hp_bar.rect);
    sfTexture_destroy(enemy->hp_bar.hp_bar_text);
    sfSprite_destroy(enemy->hp_bar.hp_bar_spr);
    sfTexture_destroy(enemy->text);
    sfSprite_destroy(enemy->spr);
}

void destroy_all(game_t game)
{
    sfMusic_destroy(game.cave_music);
    sfMusic_destroy(game.cbt_music);
    sfMusic_stop(game.am_music);
    sfMusic_destroy(game.am_music);
    sfMusic_destroy(game.menu_music);
    sfSound_destroy(game.door_sound);
    sfSoundBuffer_destroy(game.door);
}

void destroy_in_game(game_t game)
{
    sfSound_destroy(game.oof_sound);
    sfSoundBuffer_destroy(game.oof);
    sfSound_destroy(game.slash_sound);
    sfSoundBuffer_destroy(game.slash);
}