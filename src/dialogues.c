/*
** EPITECH PROJECT, 2020
** dialogues
** File description:
** dialogues
*/

#include "proto.h"
#include "rpg.h"

char *read_txt_file(void)
{
    char buffer[32];
    ssize_t size = 31;
    int fd = open("ressources/dialogue.txt", O_RDONLY);
    read(fd, buffer, size);
    my_putstr(buffer);

    return (buffer);
}

void trigger_dialogue(sfRenderWindow *window, game_t game)
{
    char *txt = malloc(sizeof(char) * 40);
    txt = read_txt_file();
    my_putchar('a');
    my_putstr(txt);
}

int check_collision_prf(game_t game)
{
    sfFloatRect g_bnd = \
    sfSprite_getGlobalBounds(game.scenes[8].npc[0].spr);
    if (game.perso->pos.x >= g_bnd.left && game.perso->pos.x <= \
    (g_bnd.left + g_bnd.width)) {
        if (game.perso->pos.y <= (g_bnd.top + g_bnd.height) && \
game.perso->pos.y >= g_bnd.top) {
            return (1);
        }
    }
    return (0);
}