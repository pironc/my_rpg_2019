/*
** EPITECH PROJECT, 2020
** init map
** File description:
** init map
*/

#include "../../include/rpg.h"
#include "../../include/proto.h"

char **read_map(game_t game, char *filepath, int scene_nb)
{
    int c = 0;
    int fori = 0;
    int buffi = 0;
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * 2041);

    read(fd, buff, 2041);
    buff[2040] = '\0';

    while (buff[buffi] != '\0' && fori < 35) {
        while (c < 60) {
            game.scenes[scene_nb].map[fori][c] = buff[buffi];
            buffi++;
            c++;
        }
        game.scenes[scene_nb].map[fori][c] = '\0';
        fori++;
        c = 0;
    }
    game.scenes[scene_nb].map[fori] = NULL;
    return (game.scenes[scene_nb].map);
}

char **init_map(game_t game, char *filepath, int scene_nb)
{
    game.scenes[scene_nb].map = malloc(sizeof(char*) * 35);
    for (int i = 0; i < 35; i++)
        game.scenes[scene_nb].map[i] = malloc(sizeof(char) * 61);
    game.scenes[scene_nb].map = read_map(game, filepath, scene_nb);
    return (game.scenes[scene_nb].map);
}

void check_map(game_t game)
{
    for (int j = 0; game.scenes[4].map[j]; j++) {
        for (int i = 0; i < 34; i++) {
            printf("%s\n", game.scenes[4].map[j][i]);
        }
    }
    printf("aled\n");
}