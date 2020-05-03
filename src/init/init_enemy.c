/*
** EPITECH PROJECT, 2020
** init enemy
** File description:
** init enemy
*/

#include "proto.h"
#include "rpg.h"

npc_t init_professor(game_t game)
{
    sfVector2f pr_pos = {950, 290};
    sfVector2f pr_scale = {1.5, 1.5};

    game.scenes[8].npc[0].name = malloc(sizeof(char) * 10);
    game.scenes[8].npc[0].name = "Professor";
    game.scenes[8].npc[0].spr = sfSprite_create();
    game.scenes[8].npc[0].text = \
    sfTexture_createFromFile("ressources/professor.png", NULL);
    sfSprite_setTexture(game.scenes[8].npc[0].spr, \
    game.scenes[8].npc[0].text, sfTrue);
    sfSprite_setPosition(game.scenes[8].npc[0].spr, pr_pos);
    sfSprite_setScale(game.scenes[8].npc[0].spr, pr_scale);

    return (game.scenes[8].npc[0]);
}

enemy_t init_enemy_forest(void)
{
    enemy_t enemy;

    enemy.name = "Forest Enemy";
    enemy.hp = 25;
    enemy.max_hp = 25;
    enemy.attack = 2;
    enemy.armor = 2;
    enemy.giv_xp = 5;
    enemy.spr = sfSprite_create();
    enemy.text = sfTexture_createFromFile("ressources/poke_forest.png", NULL);
    enemy.rect = set_rect(64, 64);
    enemy.pos = set_pos(800, 550);
    sfVector2f scale_enemy = {1.5, 1.5};
    sfSprite_setScale(enemy.spr, scale_enemy);
    sfSprite_setTexture(enemy.spr, enemy.text, sfTrue);
    sfSprite_setTextureRect(enemy.spr, enemy.rect);
    sfSprite_setPosition(enemy.spr, enemy.pos);
    return (enemy);
}

enemy_t init_enemy_desert(void)
{
    enemy_t enemy;

    enemy.name = "Desert Enemy";
    enemy.hp = 40;
    enemy.max_hp = 40;
    enemy.attack = 4;
    enemy.armor = 0;
    enemy.giv_xp = 15;
    enemy.spr = sfSprite_create();
    enemy.text = sfTexture_createFromFile("ressources/poke_desert.png", NULL);
    enemy.rect = set_rect(64, 64);
    enemy.pos = set_pos(420, 250);
    sfVector2f scale_enemy = {1.5, 1.5};
    sfSprite_setScale(enemy.spr, scale_enemy);
    sfSprite_setTexture(enemy.spr, enemy.text, sfTrue);
    sfSprite_setTextureRect(enemy.spr, enemy.rect);
    sfSprite_setPosition(enemy.spr, enemy.pos);
    return (enemy);
}

enemy_t init_enemy_lac(void)
{
    enemy_t enemy;
    sfVector2f scale_enemy = {1.5, 1.5};

    enemy.name = "Lac Enemy";
    enemy.hp = 20;
    enemy.max_hp = 20;
    enemy.attack = 5;
    enemy.armor = 0;
    enemy.giv_xp = 5;
    enemy.spr = sfSprite_create();
    enemy.text = sfTexture_createFromFile("ressources/poke_lac.png", NULL);
    enemy.rect = set_rect(64, 64);
    enemy.pos = set_pos(945, 375);
    sfSprite_setScale(enemy.spr, scale_enemy);
    sfSprite_setTexture(enemy.spr, enemy.text, sfTrue);
    sfSprite_setTextureRect(enemy.spr, enemy.rect);
    sfSprite_setPosition(enemy.spr, enemy.pos);
    return (enemy);
}

enemy_t init_enemy_lava(void)
{
    enemy_t enemy;
    sfVector2f scale_enemy = {1.5, 1.5};

    enemy.name = "Lava Enemy";
    enemy.hp = 100;
    enemy.max_hp = 100;
    enemy.attack = 10;
    enemy.armor = 5;
    enemy.giv_xp = 10;
    enemy.spr = sfSprite_create();
    enemy.text = sfTexture_createFromFile("ressources/monster.png", NULL);
    enemy.rect = set_rect(128, 128);
    enemy.pos = set_pos(753, 503);
    sfSprite_setScale(enemy.spr, scale_enemy);
    sfSprite_setTexture(enemy.spr, enemy.text, sfTrue);
    sfSprite_setTextureRect(enemy.spr, enemy.rect);
    sfSprite_setPosition(enemy.spr, enemy.pos);
    return (enemy);
}