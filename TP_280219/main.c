#include<stdlib.h>
#include<stdio.h>

typedef int MATRICE[50][50];

int demander_nb_lignes()
{
    int lignes;
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &lignes);

    return lignes;
}

int demander_nb_colonnes()
{
    int colonnes;
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &colonnes);

    return colonnes;
}

void saisir_matrice(MATRICE mat, int lignes, int colonnes)
{
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            int valeur;

            printf("\n[%d][%d] = ", i, j);
            scanf("%d", &valeur);

            mat[i][j] = valeur;
        }
    }
}

void afficher_matrice(MATRICE mat, int lignes, int colonnes)
{
    if(colonnes < 20)
    {
        for(int i = 0; i < lignes; i++)
        {
            printf("[");
            for(int j = 0; j < colonnes; j++)
            {
                printf(" %d ", mat[i][j]);
            }
            printf("]\n");
        }
    }else
    {
        for(int i = 0; i < lignes; i++)
        {
            for(int j = 0; j < colonnes; j++)
            {
                printf("M[%d][%d] = %d\n", i, j, mat[i][j]);
            }
        }
    }
    
}

void zeros_diagonale_matrice_carree(MATRICE mat, int lignes, int colonnes)
{
    if(lignes == colonnes)
    {
        for(int i = 0; i < lignes; i++)
        {
            for(int j = 0; j < colonnes; j++)
            {
                if(i == j) mat[i][j] = 0; //Si i = j on est sur la diagonale
            }
        }
    }else
    {
        printf("La matrice n'est pas carree.");
    }
    
}

void afficher_transposee_matrice(MATRICE mat, int lignes, int colonnes)
{
    MATRICE transposee;

    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            transposee[j][i] = mat[i][j];
        }
    }

    afficher_matrice(transposee, lignes, colonnes);
}

void afficher_produit_matrice(MATRICE mat, int lignes, int colonnes, int multiplicateur)
{
    MATRICE result;

    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            result[i][j] = mat[i][j] * multiplicateur;
        }
    }

    afficher_matrice(result, lignes, colonnes);
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
    int lignes = demander_nb_lignes();
    int colonnes = demander_nb_colonnes();

    saisir_matrice(mat1, lignes, colonnes);

    MATRICE mat2;
    int l2 = demander_nb_lignes();
    int c2 = demander_nb_colonnes();

    saisir_matrice(mat2, l2, c2);

    //Affichage des deux matrices
    afficher_matrice(mat1, lignes, colonnes);

    printf("\n");

    afficher_matrice(mat2, l2, c2);

    //Affichage transposée
    printf("\nTransposee A :\n");
    afficher_transposee_matrice(mat1, lignes, colonnes);


    //Affichage somme
    printf("\nSomme A et B :\n");
    afficher_somme_matrices(mat1, mat2, lignes, colonnes, l2, c2);

    //Affichage produit
    printf("\nProduit de A par 3 :\n");
    afficher_produit_matrice(mat1, lignes, colonnes, 3);

}