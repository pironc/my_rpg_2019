/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** my_strstr
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != to_find[j]) {
        i++;
        if (str[i] == to_find[j]) {
            i++;
            j++;
        }
    }
    return (to_find);
}