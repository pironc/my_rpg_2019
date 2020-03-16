/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; src[i] != '\0' && i <= n; i++) {
        dest[i] = src[i];
    }
    return (dest);
}