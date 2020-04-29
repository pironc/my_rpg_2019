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
    char **tab = malloc(sizeof(char*) * 34);

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

void init_map(maps_t *map)
{
    // map->forest = malloc(sizeof(char**) * 1);
    // map->desert = malloc(sizeof(char**) * 1);
    // map->lava = malloc(sizeof(char**) * 1);
    map->forest = read_map("game_maps/forest");
    map->desert = read_map("game_maps/desert");
    map->lava = read_map("game_maps/lava");
}

void check_map(maps_t *map)
{
    for (int i = 0; i < 34; i++) {
        printf("%s\n", map->forest[i]);
    }
}