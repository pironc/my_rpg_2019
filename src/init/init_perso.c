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

void init_stats_text(perso_t *perso)
{
    perso->invent.stats[0] = sfText_create();
    perso->invent.stats[1] = sfText_create();
    perso->invent.stats[2] = sfText_create();
    perso->invent.stats[3] = sfText_create();
    perso->invent.stats[4] = sfText_create();
    perso->invent.stats[5] = sfText_create();
    perso->invent.stats[6] = sfText_create();
    perso->invent.stats[7] = NULL;
}

void init_invent(perso_t *perso)
{
    sfVector2f perso_pos = {600, 180};
    sfVector2f perso_scale = {5, 5};

    perso->invent.stats = malloc(sizeof(sfText*) * 8);
    init_stats_text(perso);
    perso->invent.perso_spr = sfSprite_create();
    perso->invent.perso_text = sfTexture_createFromFile\
    ("ressources/perso_invtry.png", NULL);
    sfSprite_setTexture(perso->invent.perso_spr, \
    perso->invent.perso_text, sfTrue);
    sfSprite_setPosition(perso->invent.perso_spr, perso_pos);
    sfSprite_setScale(perso->invent.perso_spr, perso_scale);
    perso->invent.invent_spr = sfSprite_create();
    perso->invent.invent_text = sfTexture_createFromFile\
    ("ressources/invtry.png", NULL);
    sfSprite_setTexture(perso->invent.invent_spr, \
    perso->invent.invent_text, sfTrue);
    perso->invent.objcts[0] = init_obj("object1", 0, "ressources/object1.png");
    perso->invent.objcts[1] = init_obj("object2", 0, "ressources/object2.png");
    perso->invent.objcts[2] = init_obj("object3", 0, "ressources/object3.png");
    perso->invent.objcts[3] = init_obj("object4", 0, "ressources/object4.png");
    perso->invent.objcts[4] = NULL;
}

void init_perso(perso_t *perso)
{
    sfVector2f gm_pos = {200, 270};
    perso->name = malloc(sizeof(char) * 10);
    perso->name = "Jean-Louis";
    perso->max_hp = 50;
    perso->hp = 50;
    perso->item_nbr = 0;
    perso->attack = 4;
    perso->armor = 1;
    perso->level = 1;
    perso->exp = 0;
    perso->max_exp = 10;
    perso->gold = 10;
    perso->spr = sfSprite_create();
    perso->text = sfTexture_createFromFile\
    ("ressources/perso_static_down.png", NULL);
    perso->rect = set_rect(64, 64);
    perso->pos = set_pos(296, 576);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect);
    sfSprite_setPosition(perso->spr, perso->pos);
    init_perso_hp_bar(perso);
    perso->invent.objcts = malloc(sizeof(obj_t*) * 5);
    init_invent(perso);
    perso->all_abili = malloc(sizeof(abili_t*) * 3);
    init_abilites(perso);
    perso->pos = gm_pos;
    sfSprite_setPosition(perso->spr, perso->pos);
}