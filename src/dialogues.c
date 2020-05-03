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
    char *buffer = malloc(sizeof(char) * 238);
    ssize_t size = 237;
    int fd = open("ressources/dialogue.txt", O_RDONLY);
    read(fd, buffer, size);

    return (buffer);
}

void trigger_dialogue(sfRenderWindow *window, game_t game)
{
    sfEvent event;
    int flag = 0;
    sfVector2f txt_pos = {420, 100};
    sfFont *font = sfFont_createFromFile("ressources/Minecraft.ttf");
    char *txt = malloc(sizeof(char) * 238);
    txt = read_txt_file();
    txt[238] = '\0';
    sfText *dilg = sfText_create();
    sfText_setCharacterSize(dilg, 27);
    sfText_setString(dilg, txt);
    sfText_setPosition(dilg, txt_pos);
    sfText_setFont(dilg, font);
    dialogue_cutscene(window, game, dilg);
}

int check_collision_prf(game_t game)
{
    if (game.perso->pos.x <= 1000 && game.perso->pos.x >= 900) {
        if (game.perso->pos.y >= 300 && game.perso->pos.y <= 400) {
            return (1);
        }
    }
    return (0);
}