#include<stdio.h>
#include<stdlib.h>

typedef Matrice[100][100];

void transposer_matrice(Matrice mat, int ligns, int columns)
{
    Matrice transposee;

    for(int i = 0; i < ligns; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            transposee[j][i] = mat[i][j];
        }
    }

    afficher_matrice(transposee, ligns, columns, 1);
}

void remplir_matrice(Matrice mat, int ligns, int columns)
{
    int value;

    for(int i = 0; i < ligns; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("Valeur %d %d : ", i, j);
            scanf("%d", &value);

            mat[i][j] = value;
        }
    }
}

void afficher_matrice(Matrice mat, int ligns, int columns, int transposee)
 {
     if(transposee == 0)
     {
         for(int i = 0; i < ligns; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                printf("[%d] ", mat[i][j]);

                if(j == columns - 1) printf("\n");
            }
        }
     }else
     {
         for(int i = 0; i < columns; i++)
     {
         for(int j = 0; j < ligns; j++)
         {
             printf("[%d] ", mat[i][j]);

             if(j == columns - 1) printf("\n");
         }
     }
     }
     
     printf("\n");
 }

int main()
{
    Matrice mat;
    remplir_matrice(mat, 3, 5);
    afficher_matrice(mat, 3, 5, 0);

    transposer_matrice(mat, 3, 5);

    return 0;
}