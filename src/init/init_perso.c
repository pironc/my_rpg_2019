/*
** EPITECH PROJECT, 2020
** init perso
** File description:
** init perso
*/
#include "proto.h"
#include "rpg.h"

obj_t *init_obj(char *name, int quantity, char *filepath)
{
    obj_t *obj = malloc(sizeof(obj_t) * 1);

    obj->name = malloc(sizeof(char) * 10);
    obj->name = name;
    obj->quantity = quantity;
    obj->spr = sfSprite_create();
    obj->text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(obj->spr, obj->text, sfTrue);
    return (obj);
}

void init_invent(perso_t *perso)
{
    perso->invent[0] = init_obj("objet1", 0, "ressources/objet1.png");
    perso->invent[1] = init_obj("objet2", 0, "ressources/objet2.png");
    perso->invent[2] = init_obj("objet3", 0, "ressources/objet3.png");
    perso->invent[3] = init_obj("objet4", 0, "ressources/objet4.png");
    perso->invent[4] = NULL;
}

abili_t *init_abi(float ratio, char *name)
{
    abili_t *abiliti = malloc(sizeof(abili_t) * 1);

    abiliti->ratio = ratio;
    abiliti->name = name;
}

void init_abilites(perso_t *perso)
{
    perso->all_abili[0] = init_abi(1.5, "abilitie1");
    perso->all_abili[1] = init_abi(2, "abilitie2");
    perso->all_abili[2] = NULL;
}

void init_perso(perso_t *perso)
{
    perso->name = malloc(sizeof(char) * 10);
    perso->name = "Jean-Louis";
    perso->hp = 50;
    perso->attack = 4;
    perso->armor = 0;
    perso->level = 1;
    perso->exp = 0;
    perso->gold = 10;
    perso->spr = sfSprite_create();
    perso->text = sfTexture_createFromFile("ressources/perso_static_down.png", NULL);
    perso->rect = set_rect(64, 64);
    perso->pos = set_pos(300, 575);
    sfVector2f scale_perso = {1.5, 1.5};
    sfSprite_setScale(perso->spr, scale_perso);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect); 
    sfSprite_setPosition(perso->spr, perso->pos);
    perso->invent = malloc(sizeof(obj_t*) * 5);
    init_invent(perso);
    perso->all_abili = malloc(sizeof(abili_t*) * 3);
    init_abilites(perso);
}

void check_perso(perso_t *perso)
{
    printf("PERSO :\nName : %s\nHP: %d\nAttack : %d\nArmor : %d\nLevel : %d\n", \
    perso->name, perso->hp, perso->attack, perso->armor, perso->level);
    printf("EXP : %d\nHP: %d\nGold : %d\nArmor : %d\n", \
    perso->exp, perso->hp, perso->gold, perso->armor, perso->level);
    printf("INVENT :\nName : %s\nQuantity: %d\nName : %s\nQuantity : %d\n", \
    perso->invent[0]->name, perso->invent[0]->quantity, perso->invent[1]->name, perso->invent[0]->quantity);
    printf("ABILITIES :\nName : %s\nRatio: %.2f\nName : %s\nRatio : %.2f", \
    perso->all_abili[0]->name, perso->all_abili[0]->ratio, perso->all_abili[1]->name, perso->all_abili[1]->ratio);
}