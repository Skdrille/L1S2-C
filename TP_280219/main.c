#include <stdlib.h>
#include <stdio.h>

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
        {
            mat.coef[i][j] = 0;
        }
    }
}

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
Matrix getTransposeMatrix(Matrix mat)
{
    Matrix transpose = emptyCopyOf(mat);

    for (int i = 0; i < transpose.ligns; i++)
    {
        for (int j = 0; j < transpose.columns; j++)
        {
            transpose.coef[j][i] = mat.coef[i][j];
        }
    }

    return transpose;
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
    }
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
        clearMatrix(A);
        break;
    case 4:
        clearMatrix(B);
        break;
    case 5:
        clearMatrix(C);
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
        clearMatrixDiagonale(A);
        break;
    case 2:
        clearMatrixDiagonale(B);
        break;
    case 3:
        clearMatrixDiagonale(C);
        break;
    default:
        clearMatrixDiagonalMenu();
        break;
    }

    displayMainMenu();
}

void transposeeMatrixMenu()
{
    int userChoice = askUserChoice();

    printf("\n<1> Calculer la transposee de A\n");
    printf("<2> Calculer la transposee de B\n");
    printf("<3> Calculer la transposee de C\n");
    printf("<0> Quitter le calcul des transposees\n");

    switch (userChoice)
    {
    case 0:
        displayMainMenu();
        break;
    case 1:
        displayMatrix(getTransposeMatrix(A));
        break;
    case 2:
        displayMatrix(getTransposeMatrix(B));
        break;
    case 3:
        displayMatrix(getTransposeMatrix(C));
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
}