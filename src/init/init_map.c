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

char **read_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat statbuf;
    char *buffer = NULL;
    char **tab = NULL;

    tab = malloc(sizeof(char*) * 34);
    if (stat(filepath, &statbuf) == -1)
        return (NULL);
    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (statbuf.st_size + 1));
    if (buffer == NULL)
        return (NULL);
    read(fd, buffer, statbuf.st_size);
    tab = my_str_to_word_array_space(buffer);
    free(buffer);
    return (tab);
}

maps_t *init_map(void)
{
    maps_t *map = malloc(sizeof(maps_t) * 1);

    map->maps = malloc(sizeof(char**) * 4);
    // map->forest = malloc(sizeof(char**) * 1);
    // map->desert = malloc(sizeof(char**) * 1);
    // map->lava = malloc(sizeof(char**) * 1);
    map->maps[0] = read_map("game_maps/forest");
    map->maps[1] = read_map("game_maps/desert");
    map->maps[2] = read_map("game_maps/lava");
    map->maps[3] = NULL;
    return (map);
}

void check_map(maps_t *map)
{
    for (int j = 0; map->maps[j]; j++) {
        for (int i = 0; i < 34; i++) {
            printf("%s\n", map->maps[j][i]);
        }
    }
    printf("aled\n");
}