#include<stdio.h>
#include<stdlib.h>

int index_max(int tab[], int size)
{
    int max = 0;
    int index = 0;

    for(int i = 0; i < size; i++)
    {
        if(tab[i] > max){
            max = tab[i];
            index = i;
        }
    }
    return index;
}

void permuter(int tab[], int index_a, int index_b)
{
    int value_a = tab[index_a];
    tab[index_a] = tab[index_b];
    tab[index_b] = value_a;
}

void tri_par_selection(int tab[], int size)
{
    while(size > 1)
    {
        size--;
        permuter(tab, index_max(tab, size), size - 1);
    }
}

int main()
{
    int tab[] = {7, 2, 3, 8, 4, 6, 5, 9, 1, 10};
    tri_par_selection(tab, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", tab[i]);
    }

    return 0;
}