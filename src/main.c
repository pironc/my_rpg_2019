/*
** EPITECH PROJECT, 2020
** rpg main
** File description:
** main function of my_rpg
*/
#include "proto.h"
#include "rpg.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        my_rpg();
    } else {
        my_putstr("Error! Please use \"./my_rpg\" to start the game.\n");
        return (84);
    }
    return (0);
}