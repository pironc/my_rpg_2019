/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int num = 0;

    while (str[num] != '\0') {
        num++;
    }
    return num;
}