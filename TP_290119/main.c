#include<stdio.h>
#include<stdlib.h>

typedef int TTableauDeNombres[1000];

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

void permuter(TTableauDeNombres tab, int index_a, int index_b)
{
    int value_a = tab[index_a];
    tab[index_a] = tab[index_b];
    tab[index_b] = value_a;
}

void tri_par_selection(TTableauDeNombres tab, int size)
{
    while(size > 1)
    {
        permuter(tab, size - 1, index_max(tab, size));
        size--;
    }
}

void tri_par_insertion(TTableauDeNombres tab, int size)
{
    for(int i = 1; i < size; i++)
    {
        int x = tab[i];
        int j = i;
        
        while(j > 0 && tab[j - 1] > x)
        {
            tab[j] = tab[j - 1]; //Décalage vers la droite
            j--;
        }
        tab[j] = x;
    }
}

void tri_a_bulles(TTableauDeNombres tab, int size)
{
    for(int i = size - 1; i > 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(tab[j + 1] < tab[j])
            {
                permuter(tab, tab[j + 1], tab[j]);
            }
        }
    }
}

int main()
{
    /*
    Tri par sélection
    */
    TTableauDeNombres tab1 = {7, 0, 3, 8, 23, 45, 5, 31, 12, 10}; //Exemple de tableau à trier avec 10 entiers
    tri_a_bulles(tab1, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", tab1[i]);
    }

    

    return 0;
}