#include <stdlib.h>
#include <stdio.h>

/*

J'ai préféré créer une structure pour les matrices afin ne pas avoir à inclure le nombre de lignes et colonnes dans les paramètres de chaque fonction

*/
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

    //Fill the matrix
    for (int i = 0; i < mat.ligns; i++)
    {
        for (int j = 0; j < mat.columns; j++)
        {
            printf("Coefficient [%d][%d] = ", i, j);
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
        {
            mat.coef[i][j] = 0;
        }
    }

    return mat;
}

/*
Set the matrix's diagonal coefficients to 0
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
            {
                printf(" %d ", mat.coef[i][j]);
            }
            printf("]\n");
        }
    }
    else
    {
        for (int i = 0; i < ligns; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                printf("M[%d][%d] = %d\n", i, j, mat.coef[i][j]);
            }
        }
    }
}

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
        }
    }

    displayMatrix(transpose);
}

/*
Multiply a matrix by a coefficient
*/
Matrix getMultipliedMatrixByCoefficient(Matrix mat, int coefficient)
{
    Matrix result = emptyCopyOf(mat);

    for (int i = 0; i < result.ligns; i++)
    {
        for (int j = 0; j < result.columns; j++)
        {
            result.coef[i][j] = mat.coef[i][j] * coefficient;
        }
    }

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
        {
            for (int j = 0; j < result.columns; j++)
            {
                result.coef[i][j] = mat1.coef[i][j] + mat2.coef[i][j];
            }
        }

        return result;
    }
}

/*
Get the product of a matrix by a matrix
*/
Matrix getMultipliedMatrixByMatrix(Matrix mat1, Matrix mat2)
{
    Matrix result = emptyCopyOf(mat1);

    if (mat1.columns == mat2.ligns)
    {
        for (int i = 0; i < mat1.columns; i++)
        {
            for (int j = 0; j < mat2.ligns; j++)
            {
                for (int k = 0; k < mat2.ligns; k++)
                {
                    result.coef[i][j] += mat1.coef[i][k] * mat2.coef[k][j];
                }
            }
        }

        return result;
    }
}

/*
get user input
*/
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
        C = getMultipliedMatrixByMatrix(A, B);
        displayMatrix(C);
        displayMainMenu();
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

void transposeeMatrixMenu()
{
    printf("\n<1> Calculer la transposee de A\n");
    printf("<2> Calculer la transposee de B\n");
    printf("<3> Calculer la transposee de C\n");
    printf("<0> Quitter le calcul des transposees\n");

    int userChoice = askUserChoice();

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

void displayMatrixMenu()
{
    printf("\n<1> Afficher A\n");
    printf("<2> Afficher B\n");
    printf("<3> Afficher C\n");
    printf("<0> Quitter l'affichage\n");

    int userChoice = askUserChoice();

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

int main()
{
    displayMainMenu();
    return 0;
}