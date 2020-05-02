/*
** EPITECH PROJECT, 2020
** open_map
** File description:
** function to open a map tileset
*/

#include "rpg.h"
#include "proto.h"

char **open_map(char **tileset)
{
    int c = 0;
    int fori = 0;
    int buffi = 0;
    FILE *fd = open("game_maps/forest", O_RDONLY);
    tileset = malloc(sizeof(char*) * (35));
    char *buff = malloc(sizeof(char) * 2041);

    read(fd, buff, 2041);
    buff[2040] = '\0';

    for (int mindex = 0; mindex < 35; mindex++) {
        tileset[mindex] = malloc(sizeof(char) * 61);
    }

    while (buff[buffi] != '\0' && fori < 35) {
        while (c < 60) {
            tileset[fori][c] = buff[buffi];
            buffi++;
            c++;
        }
        tileset[fori][c] = '\0';
        fori++;
        c = 0;
    }
    tileset[fori] = NULL;
    return (tileset);
}