/*
** EPITECH PROJECT, 2020
** move perso
** File description:
** moves perso
*/
#include "proto.h"
#include "rpg.h"

void perso_anim(perso_t *perso)
{
    move_rect(&(perso->rect), 64, 256);
    //sfSprite_setPosition(perso->spr, perso->pos);
    sfSprite_setTextureRect(perso->spr, perso->rect);
}

void enemy_anim_test(enemy_t **enemies, game_t game)
{
    for (int i = 0; i < game.scenes[game.cur_scn].enemy_left; i++) {
        move_rect(&enemies[i]->rect, 64, 256);
        sfSprite_setTextureRect(enemies[i]->spr, enemies[i]->rect);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}

void move_perso(game_t *game, perso_t *perso, int i)
{
    sfEvent event;
    int top_y = 0;
    int current_y = 0;
    int bottom_y = 0;

    int left_x = 0;
    int current_x = 0;
    int right_x = 0;

    char **tileset = NULL;
    my_put_nbr(game->cur_scn);

    switch (game->cur_scn) {
        case 4:
            my_putchar('a');
            tileset = open_map("forest");
            break;
        case 5:
            my_putchar('b');
            tileset = open_map("desert");
            break;
        case 6:
            my_putchar('c');
            tileset = open_map("lava");
            break;
        default:
            printf("default statement\n");
            break;
    }

    top_y = (perso->pos.y + 16) / 32;
    current_y = (perso->pos.y + 32) / 32;
    bottom_y = (perso->pos.y + 48) / 32;

    left_x = (perso->pos.x + 16) / 32;
    current_x = (perso->pos.x + 32) / 32;
    right_x = (perso->pos.x + 48) / 32;

    if (i == 1) {
        change_sprite(perso, "ressources/perso_up.png");
        if (tileset[current_y][current_x] == '*' && tileset[bottom_y - 1][current_x] == '*' && tileset[bottom_y - 1][left_x] == '*' && tileset[bottom_y - 1][right_x] == '*')
            perso->pos.y -= 8;
        else if (tileset[current_y - 1][current_x] == 'H') {
            perso->pos.y = 500;
            perso->pos.x = 1000;
        } else
            perso->pos.y -= 0;
    }
    if (i == 2) {
        change_sprite(perso, "ressources/perso_down.png");
        if (tileset[current_y][current_x] == '*' && tileset[current_y + 1][current_x] == '*' && tileset[current_y + 1][left_x] == '*' && tileset[current_y + 1][right_x] == '*')
            perso->pos.y += 8;
        else
            perso->pos.y += 0;
    }
    if (i == 3) {
        change_sprite(perso, "ressources/perso_left.png");
        if (tileset[current_y][current_x] == '*' && tileset[current_y][current_x - 1] == '*' &&  tileset[bottom_y][current_x - 1] == '*')
            perso->pos.x -= 8;
        else if (tileset[current_y][current_x - 1] == 'D') {
            if (game->cur_scn == 4) {
                game->cur_scn = 5;
            }
            if (game->cur_scn == 6) {
                game->cur_scn = 4;
            }
            perso->pos.y = 300;
            perso->pos.x = 1800;
        } else
            perso->pos.x -= 0;
    }
    if (i == 4) {
        change_sprite(perso, "ressources/perso_right.png");
        if (tileset[current_y][current_x] == '*' && tileset[current_y][current_x + 1] == '*' &&  tileset[bottom_y][current_x + 1] == '*')
            perso->pos.x += 8;
        else if (tileset[current_y][current_x + 1] == 'L') {
            if (game->cur_scn == 4) {
                game->cur_scn = 6;
            } else if (game->cur_scn == 5) {
                game->cur_scn = 4;
            }
            perso->pos.y = 300;
            perso->pos.x = 70;
        } else
            perso->pos.x += 0;
    }
    sfSprite_setPosition(perso->spr, perso->pos);
    //printf(" %c \n%c%c%c\n %c\n", tileset[current_y - 1][current_x], tileset[current_y][current_x - 1], tileset[current_y][current_x], tileset[current_y][current_x + 1], tileset[current_y + 1][current_x]);
    //printf("pos.x : %f ; pos.y : %f\n", perso->pos.x, perso->pos.y);
}

void change_sprite(perso_t *perso, char *filepath)
{
    sfTexture_destroy(perso->text);
    perso->text = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(perso->spr, perso->text, sfTrue);
    sfSprite_setTextureRect(perso->spr, perso->rect);
    //sfSprite_setPosition(perso->spr, perso->pos);

    //TODO print les feuilles par dessus tout le reste (ressources/leaves.png)
    // et voir si ça rend bien
}