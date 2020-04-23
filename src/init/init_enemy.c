/*
** EPITECH PROJECT, 2020
** init enemy
** File description:
** init enemy
*/

#include "../../include/rpg.h"

enemy_t *init_enemy_forest(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t) * 1);

    enemy->name = "Forest Enemy";
    enemy->hp = 25;
    enemy->attack = 2;
    enemy->armor = 2;
    enemy->giv_xp = 10;
    enemy->spr = sfSprite_create();
    enemy->text = sfTexture_createFromFile("ressources/poke_forest.png", NULL);
    enemy->rect = set_rect(64, 64);
    enemy->pos = set_pos(800, 700);
    sfVector2f scale_enemy = {1.5, 1.5};
    sfSprite_setScale(enemy->spr, scale_enemy);
    sfSprite_setTexture(enemy->spr, enemy->text, sfTrue);
    sfSprite_setTextureRect(enemy->spr, enemy->rect); 
    sfSprite_setPosition(enemy->spr, enemy->pos);
    return (enemy);
}

enemy_t *init_enemy_desert(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t) * 1);

    enemy->name = "Desert Enemy";
    enemy->hp = 40;
    enemy->attack = 4;
    enemy->armor = 0;
    enemy->giv_xp = 15;
    enemy->spr = sfSprite_create();
    enemy->text = sfTexture_createFromFile("ressources/poke_desert.png", NULL);
    enemy->rect = set_rect(64, 64);
    enemy->pos = set_pos(800, 575);
    sfVector2f scale_enemy = {1.5, 1.5};
    sfSprite_setScale(enemy->spr, scale_enemy);
    sfSprite_setTexture(enemy->spr, enemy->text, sfTrue);
    sfSprite_setTextureRect(enemy->spr, enemy->rect); 
    sfSprite_setPosition(enemy->spr, enemy->pos);
    return (enemy);
}

enemy_t *init_enemy_lac(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t) * 1);

    enemy->name = "Lac Enemy";
    enemy->hp = 20;
    enemy->attack = 5;
    enemy->armor = 0;
    enemy->giv_xp = 5;
    enemy->spr = sfSprite_create();
    enemy->text = sfTexture_createFromFile("ressources/poke_lac.png", NULL);
    enemy->rect = set_rect(64, 64);
    enemy->pos = set_pos(800, 250);
    sfVector2f scale_enemy = {1.5, 1.5};
    sfSprite_setScale(enemy->spr, scale_enemy);
    sfSprite_setTexture(enemy->spr, enemy->text, sfTrue);
    sfSprite_setTextureRect(enemy->spr, enemy->rect);
    sfSprite_setPosition(enemy->spr, enemy->pos);
    return (enemy);
}

void init_enemies(enemy_t **enemies)
{
    enemies[0] = init_enemy_forest();
    enemies[1] = init_enemy_desert();
    enemies[2] = init_enemy_lac();
    enemies[3] == NULL;
}

void check_enemy(enemy_t **enemies)
{
    for (int i = 0; i < 3; i++) {
        printf("Enemy %d :\nName : %s\nHP : %d\nAttack : %d\n", i, enemies[i]->name, enemies[i]->hp, enemies[i]->attack);
        printf("Giv xp : %d\n", enemies[i]->giv_xp);
    }
}