#include<stdio.h>
#include<stdlib.h>

typedef int TTableauDeNombres[1000];

/* Récupérer l'index de la plus grande valeur d'un tableau d'entiers */
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

/* Permuter les valeurs d'un tableau */
void permuter(TTableauDeNombres tab, int index_a, int index_b)
{
    int value_a = tab[index_a];
    tab[index_a] = tab[index_b];
    tab[index_b] = value_a;
}

/* Afficher le contenu d'un tableau */
void afficher_tableau(TTableauDeNombres tab, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/* Trier un tableau par sélection */
void tri_par_selection(TTableauDeNombres tab, int size)
{
    while(size > 1)
    {
        permuter(tab, size - 1, index_max(tab, size));
        size--;
    }
}

/* Trier un tableau par insertion */
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

/* Trier un tableau par bulles */
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
    TTableauDeNombres tab1 = {7, 0, 3, 8, 23, 45, 5, 31, 12, 10}; //Exemple de tableau à trier avec 10 entiers
    tri_par_selection(tab1, 10);
    afficher_tableau(tab1, 10);

    TTableauDeNombres tab2 = {2, 7, 0, 8, 11, 28, 73, 31, 44, 5}; 
    tri_par_insertion(tab2, 10);
    afficher_tableau(tab2, 10);

    TTableauDeNombres tab3 = {2, 7, 0, 8, 11, 28, 73, 31, 44, 5}; 
    tri_a_bulles(tab3, 10);
    afficher_tableau(tab3, 10);

    

    return 0;
}