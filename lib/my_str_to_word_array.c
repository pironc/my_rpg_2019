/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** program used to separate a sentence into words
*/

#include <stdlib.h>

char my_putchar(char c);

int my_strlen(char const *str);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char *clean_str(char *str)
{
    int i = 0;
    int index = 0;
    int found = 0;
    char *cleaned_str = malloc((my_strlen(str)+1) * sizeof(char *));

    for (i = 0; str[i] != 0; i++) {
        if (str[i] >= 33 && str[i] <= 126) {
            cleaned_str[index] = str[i];
            index++;
            found = 1;
        }
        if ((str[i] == ' ' || str[i] == '\t') && found == 1) {
            cleaned_str[index] = str[i];
            index++;
            found = 0;
        }
    }
    if (str[i-1] == ' ' || str[i-1] == '\t')
        cleaned_str[index-1] = 0;
    return (cleaned_str);
}

char **my_str_to_word_array(char *str)
{
    char *cleaned_str = clean_str(str);
    char **array = malloc(my_strlen(cleaned_str) * sizeof(char *));
    array[0] = malloc(my_strlen(cleaned_str));
    int index = 0;
    int c = 0;

    for (int i = 0; cleaned_str[i] != '\0'; i++) {
        if (cleaned_str[i] >= 33 && cleaned_str[i] <= 127) {
            array[index][c] = cleaned_str[i];
            c++;
        }
        if (cleaned_str[i] == ' ' || cleaned_str[i] == '\t') {
            c = 0;
            index++;
            array[index] = malloc(my_strlen(cleaned_str));
        }
    }
    array[index+1] = 0;
    return (array);
}