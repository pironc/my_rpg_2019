/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Split a string into words array
*/

#include <stdlib.h>

int is_itchar_space(char a);
int count_word_space(char *str);
int word_len_space(char *str, int i);
char **my_str_to_word_array_space(char *str);
int str_begin_space(char *str);

int str_begin_space(char *str)
{
    int a = 0;

    while (is_itchar_space(str[a]) != 1) {
        a++;
    }
    return (a);
}

char **my_str_to_word_array_space(char *str)
{
    int a = str_begin_space(str);
    int b = 0;
    int c = 0;
    char **tab_result = malloc(sizeof(char *) * (count_word_space(str) + 1));

    if (tab_result == NULL)
        return (NULL);
    for (;b < count_word_space(str) + 1; b++) {
        tab_result[b] = malloc(sizeof(char) * word_len_space(str, a) + 1);
        if (tab_result[b] == NULL)
            return (NULL);
        for (;str[a] != '\0' && is_itchar_space(str[a]) == 1; a++, c++) {
            tab_result[b][c] = str[a];
        }
        tab_result[b][c] = '\0';
        c = 0;
        a++;
    }
    tab_result[b] = '\0';
    return (tab_result);
}

int is_itchar_space(char a)
{
    if ((a >= '0' && a <= '9') || a == '*') {
        return (1); 
    }
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) {
        return (1);
    } else {
        return (0);
    }
}

int count_word_space(char *str)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0') {
        if ((is_itchar_space(str[a]) == 1) && \
        (is_itchar_space(str[a + 1])) != 1) {
            b++;
        }
        a++;
    }
    return (b);
}

int word_len_space(char *str, int i)
{
    int a = i;

    while (is_itchar_space(str[a]) != 1) {
        i++;
        a++;
    }
    while (str[i] != '\0') {
        if (is_itchar_space(str[i]) != 1)
            return (i - a);
        i++;
    }
    return (i - a);
}
