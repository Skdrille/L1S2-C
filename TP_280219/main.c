#include <stdlib.h>
#include <stdio.h>

<<<<<<< HEAD
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
=======
typedef struct
{
    int ligns, columns, coef[50][50];
} Matrix;

Matrix A, B, C;

/*
Define a matrix and fill it
*/
Matrix buildMatrix()
{
    Matrix mat;

    printf("Entrez le nombre de lignes : ");
    scanf("%d", &mat.ligns);

    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &mat.columns);

    printf("\nEntrez les coefficients de la matrice : ");

    //Fill the matrix
    for (int i = 0; i < mat.ligns; i++)
    {
        for (int j = 0; j < mat.columns; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mat.coef[i][j]);
        }
    }

    return mat;
}

/*
Make a copy of a matrix with the same ligns and columns
*/
Matrix emptyCopyOf(Matrix mat)
{
    Matrix copy;
    copy.ligns = mat.ligns;
    copy.columns = mat.columns;

    return copy;
}

int sameSize(Matrix mat1, Matrix mat2)
{
    return (mat1.ligns == mat2.ligns && mat1.columns == mat2.columns);
}

/*
Set all the matrix's coefficients to 0
*/
Matrix clearMatrix(Matrix mat)
{
    for (int i = 0; i < mat.ligns; i++)
    {
        for (int j = 0; j < mat.columns; j++)
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
        {
            mat.coef[i][j] = 0;
        }
    }

    return mat;
}

/*
THIS FUNCTION DOESN'T WORK 
*/
Matrix clearMatrixDiagonale(Matrix mat)
{
    for (int i = 0; i < mat.ligns; i++)
    {
        for (int j = 0; j < mat.columns; j++)
        {
            if (i == j)
                mat.coef[i][j] = 0;
        }
    }

    return mat;
}

<<<<<<< HEAD
void afficher_matrice(MATRICE mat, int ligns, int columns)
{
    if(columns < 20)
    {
        for(int i = 0; i < ligns; i++)
        {
            printf("[");
            for(int j = 0; j < columns; j++)
=======
/*
Display the coefficients of a matrix
*/
void displayMatrix(Matrix mat)
{
    int ligns = mat.ligns;
    int columns = mat.columns;

    if (columns < 20)
    {
        for (int i = 0; i < ligns; i++)
        {
            printf("[");
            for (int j = 0; j < columns; j++)
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
            {
                printf(" %d ", mat.coef[i][j]);
            }
            printf("]\n");
        }
    }
    else
    {
<<<<<<< HEAD
        for(int i = 0; i < ligns; i++)
        {
            for(int j = 0; j < columns; j++)
=======
        for (int i = 0; i < ligns; i++)
        {
            for (int j = 0; j < columns; j++)
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
            {
                printf("M[%d][%d] = %d\n", i, j, mat.coef[i][j]);
            }
        }
    }
}

<<<<<<< HEAD
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
=======
/*
Get the transpose of a matrix 
*/
void displayTransposeMatrix(Matrix mat)
{
    Matrix transpose = emptyCopyOf(mat);

    for (int i = 0; i < transpose.ligns; i++)
    {
        for (int j = 0; j < transpose.columns; j++)
        {
            transpose.coef[j][i] = mat.coef[i][j];
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
        }
    }

    displayMatrix(transpose);
}

<<<<<<< HEAD
void afficher_transposee_matrice(MATRICE mat, int ligns, int columns)
=======
/*
Multiply a matrix by a coefficient
*/
Matrix getMultipliedMatrixByCoefficient(Matrix mat, int coefficient)
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
{
    Matrix result = emptyCopyOf(mat);

<<<<<<< HEAD
    for(int i = 0; i < ligns; i++)
    {
        for(int j = 0; j < columns; j++)
=======
    for (int i = 0; i < result.ligns; i++)
    {
        for (int j = 0; j < result.columns; j++)
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
        {
            result.coef[i][j] = mat.coef[i][j] * coefficient;
        }
    }

<<<<<<< HEAD
    afficher_matrice(transposee, ligns, columns);
}

void afficher_produit_matrice(MATRICE mat, int ligns, int columns, int multiplicateur)
{
    MATRICE result;

    for(int i = 0; i < ligns; i++)
    {
        for(int j = 0; j < columns; j++)
=======
    return result;
}

/*
Get the sum of two matrices
*/
Matrix sumMatrices(Matrix mat1, Matrix mat2)
{
    if (sameSize(mat1, mat2)) //If both matrices have the same size
    {
        Matrix result = emptyCopyOf(mat1);

        for (int i = 0; i < result.ligns; i++)
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
        {
            for (int j = 0; j < result.columns; j++)
            {
                result.coef[i][j] = mat1.coef[i][j] + mat2.coef[i][j];
            }
        }

<<<<<<< HEAD
    afficher_matrice(result, ligns, columns);
=======
        return result;
    }
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99
}

Matrix getMultipliedMatrixByMatrix(Matrix mat1, Matrix mat2)
{
    Matrix result;

    if (mat1.columns == mat2.ligns)
    {
        int product = 0;

        for (int i = 0; i < mat1.ligns; i++)
        {
            for (int j = 0; j < mat2.columns; j++)
            {
            }
        }
    }
}

int askUserChoice()
{
    int userChoice;

    printf(": ");
    scanf("%d", &userChoice);

    return userChoice;
}

void displayMainMenu()
{

    printf("\n<1> Saisir une matrice\n");
    printf("<2> Mettre a zero la diaginale d'une matrice\n");
    printf("<3> Calculer la transposee d'une matrice\n");
    printf("<4> Calculer C = A + B\n");
    printf("<5> Calculer C = A x B\n");
    printf("<6> Afficher une matrice\n");
    printf("<0> Quitter le programme\n");

    int userChoice = askUserChoice();

    switch (userChoice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        buildMatrixMenu();
        break;
    case 2:
        clearMatrixDiagonalMenu();
        break;
    case 3:
        transposeeMatrixMenu();
        break;
    case 4:
        C = sumMatrices(A, B);
        displayMatrix(C);
        displayMainMenu();
        break;
    case 5:
        printf("A finir");
    case 6:
        displayMatrixMenu();
        break;
    default:
        displayMainMenu();
        break;
    }
}

void buildMatrixMenu()
{
    printf("\n<1> Matrice A (taille et contenu)\n");
    printf("<2> Matrice B (taille et contenu)\n");
    printf("<3> Mettre la matrice A a zero\n");
    printf("<4> Mettre la matrice B a zero\n");
    printf("<5> Mettre la matrice C a zero\n");
    printf("<0> Quitter les saisies\n");

    int userChoice = askUserChoice();

    switch (userChoice)
    {
    case 0:
        displayMainMenu();
        break;
    case 1:
        A = buildMatrix();
        break;
    case 2:
        B = buildMatrix();
        break;
    case 3:
        A = clearMatrix(A);
        break;
    case 4:
        B = clearMatrix(B);
        break;
    case 5:
        C = clearMatrix(C);
        break;
    default:
        buildMatrixMenu();
        break;
    }

    displayMainMenu();
}

void clearMatrixDiagonalMenu()
{
<<<<<<< HEAD
    MATRICE mat1;
    int ligns = demander_nb_ligns();
    int columns = demander_nb_columns();

    saisir_matrice(mat1, ligns, columns);

    MATRICE mat2;
    int l2 = demander_nb_ligns();
    int c2 = demander_nb_columns();
=======
    printf("\n<1> Mettre a zero la diagonale de A\n");
    printf("<2> Mettre a zero la diagonale de B\n");
    printf("<3> Mettre a zero la diagonale de C\n");
    printf("<0> Quitter la mise a zero des diagnoales\n");

    int userChoice = askUserChoice();

    switch (userChoice)
    {
    case 0:
        displayMainMenu();
        break;
    case 1:
        A = clearMatrixDiagonale(A);
        break;
    case 2:
        B = clearMatrixDiagonale(B);
        break;
    case 3:
        C = clearMatrixDiagonale(C);
        break;
    default:
        clearMatrixDiagonalMenu();
        break;
    }

    displayMainMenu();
}
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99

void transposeeMatrixMenu()
{
    printf("\n<1> Calculer la transposee de A\n");
    printf("<2> Calculer la transposee de B\n");
    printf("<3> Calculer la transposee de C\n");
    printf("<0> Quitter le calcul des transposees\n");

<<<<<<< HEAD
    //Affichage des deux matrices
    afficher_matrice(mat1, ligns, columns);
=======
    int userChoice = askUserChoice();
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99

    switch (userChoice)
    {
    case 0:
        displayMainMenu();
        break;
    case 1:
        displayTransposeMatrix(A);
        break;
    case 2:
        displayTransposeMatrix(B);
        break;
    case 3:
        displayTransposeMatrix(C);
        break;
    default:
        transposeeMatrixMenu();
        break;
    }

    displayMainMenu();
}

<<<<<<< HEAD
    //Affichage transposée
    printf("\nTransposee A :\n");
    afficher_transposee_matrice(mat1, ligns, columns);
=======
void displayMatrixMenu()
{
    printf("\n<1> Afficher A\n");
    printf("<2> Afficher B\n");
    printf("<3> Afficher C\n");
    printf("<0> Quitter l'affichage\n");
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99

    int userChoice = askUserChoice();

<<<<<<< HEAD
    //Affichage somme
    printf("\nSomme A et B :\n");
    afficher_somme_matrices(mat1, mat2, ligns, columns, l2, c2);

    //Affichage produit
    printf("\nProduit de A par 3 :\n");
    afficher_produit_matrice(mat1, ligns, columns, 3);
=======
    switch (userChoice)
    {
    case 0:
        displayMainMenu();
        break;
    case 1:
        displayMatrix(A);
        break;
    case 2:
        displayMatrix(B);
        break;
    case 3:
        displayMatrix(C);
        break;
    default:
        displayMatrixMenu();
        break;
    }

    displayMainMenu();
}
>>>>>>> cb7ae5e8a6d8b5be1ae62eed8da9fddce78beb99

int main()
{
    displayMainMenu();
    return 0;
}