/*
** EPITECH PROJECT, 2020
** init map
** File description:
** init map
*/

#include "../../include/rpg.h"
#include "../../include/proto.h"
#include <sys/types.h>
#include <sys/stat.h>

char **read_map(maps_t maps, char *filepath)
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
            maps.forest[fori][c] = buff[buffi];
            buffi++;
            c++;
        }
        maps.forest[fori][c] = '\0';
        fori++;
        c = 0;
    }
    maps.forest[fori] = NULL;
    return (maps.forest);
}

maps_t *init_map(maps_t maps, char *filepath)
{
    maps.forest = malloc(sizeof(char*) * 35);
    for (int i = 0; i < 35; i++)
        maps.forest[i] = malloc(sizeof(char) * 61);
    maps.forest[60] = '\0';
    read_map(maps, filepath);
    return (maps.forest);
}

void check_map(maps_t *map)
{
    for (int j = 0; map->forest[j]; j++) {
        for (int i = 0; i < 34; i++) {
            printf("%s\n", map->forest[j][i]);
        }
    }
    printf("aled\n");
}