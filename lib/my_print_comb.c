/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** my_print_comb
*/

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

void print(char a, char b, char c)
{
    my_put_nbr(a);
    my_put_nbr(b);
    my_put_nbr(c);
    my_putstr(", ");
}

int my_print_comb(void)
{
    int a = 0;
    int b = 1;
    int c = 2;

    while (a <= 7 && b <= 8 && c <= 9) {
        if (a == 7 && b == 8 && c == 9) {
            my_put_nbr(a);
            my_put_nbr(b);
            my_put_nbr(c);
            return (0);
        }
        while (c > b && b > a && c < 9) {
            print(a, b, c);
            c++;
        }
        if (b == 8 && c == 9) {
            print(a, b, c);
            a++;
            b = a+1;
            c = b+1;
        } else if (c == 9) {
            print(a, b, c);
            b++;
            c = b + 1;
        }
    }
}

int main(void)
{
    my_print_comb();
}