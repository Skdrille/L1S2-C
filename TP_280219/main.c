#include<stdlib.h>
#include<stdio.h>

typedef int MATRICE[15][15];

int demander_nb_ligns()
{
    int ligns;
    printf("Entrez le nombre de ligns : ");
    scanf("%d", &ligns);

    return ligns;
}

int demander_nb_columns()
{
    int columns;
    printf("Entrez le nombre de columns : ");
    scanf("%d", &columns);

    return columns;
}

void saisir_matrice(MATRICE mat, int ligns, int columns)
{
    for(int i = 0; i < ligns; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            int valeur;

            printf("\n[%d][%d] = ", i, j);
            scanf("%d", &valeur);

            mat[i][j] = valeur;
        }
    }
}

void afficher_matrice(MATRICE mat, int ligns, int columns)
{
    if(columns < 20)
    {
        for(int i = 0; i < ligns; i++)
        {
            printf("[");
            for(int j = 0; j < columns; j++)
            {
                printf(" %d ", mat[i][j]);
            }
            printf("]\n");
        }
    }else
    {
        for(int i = 0; i < ligns; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                printf("M[%d][%d] = %d\n", i, j, mat[i][j]);
            }
        }
    }
    
}

void zeros_diagonale_matrice_carree(MATRICE mat, int ligns, int columns)
{
    if(ligns == columns)
    {
        for(int i = 0; i < ligns; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(i == j) mat[i][j] = 0; //Si i = j on est sur la diagonale
            }
        }
    }else
    {
        printf("La matrice n'est pas carree.");
    }
    
}

void afficher_transposee_matrice(MATRICE mat, int ligns, int columns)
{
    MATRICE transposee;

    for(int i = 0; i < ligns; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            transposee[j][i] = mat[i][j];
        }
    }

    afficher_matrice(transposee, ligns, columns);
}

void afficher_produit_matrice(MATRICE mat, int ligns, int columns, int multiplicateur)
{
    MATRICE result;

    for(int i = 0; i < ligns; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            result[i][j] = mat[i][j] * multiplicateur;
        }
    }

    afficher_matrice(result, ligns, columns);
}

void afficher_somme_matrices(MATRICE mat1, MATRICE mat2, int l1, int c1, int l2, int c2)
{
    MATRICE result;

    if(l1 == l2 && c1 == c2)
    {
        for(int i = 0; i < l1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                result[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        afficher_matrice(result, l1, c1);
    }else
    {
        printf("Les deux matrices ne sont pas de meme taille !");
    }
    
}

void afficher_produit_matrice_matrice(MATRICE mat1, MATRICE mat2, int l1, int c1, int l2, int c2)
{

}

int main()
{
    MATRICE mat1;
    int ligns = demander_nb_ligns();
    int columns = demander_nb_columns();

    saisir_matrice(mat1, ligns, columns);

    MATRICE mat2;
    int l2 = demander_nb_ligns();
    int c2 = demander_nb_columns();

    saisir_matrice(mat2, l2, c2);

    //Affichage des deux matrices
    afficher_matrice(mat1, ligns, columns);

    printf("\n");

    afficher_matrice(mat2, l2, c2);

    //Affichage transposée
    printf("\nTransposee A :\n");
    afficher_transposee_matrice(mat1, ligns, columns);


    //Affichage somme
    printf("\nSomme A et B :\n");
    afficher_somme_matrices(mat1, mat2, ligns, columns, l2, c2);

    //Affichage produit
    printf("\nProduit de A par 3 :\n");
    afficher_produit_matrice(mat1, ligns, columns, 3);

}