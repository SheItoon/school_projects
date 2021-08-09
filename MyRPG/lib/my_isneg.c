/*
** EPITECH PROJECT, 2019
** positif negatif
** File description:
** retunr n or p
*/

int my_putchar(char);

int my_isneg(int nbr)
{
    int N = 78;
    int P = 80;

    if(nbr < 0)
    {
        my_putchar(N);
    }else{
        my_putchar(P);
    }
}
