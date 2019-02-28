#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int ligns, columns, content[50][50];
} Matrix;

/*
Define a matrix and fill it
*/
Matrix build_matrix()
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
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mat.content[i][j]);
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
                printf(" %d ", mat.content[i][j]);
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
                printf("M[%d][%d] = %d\n", i, j, mat.content[i][j]);
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
            transpose.content[j][i] = mat.content[i][j];
        }
    }

    return transpose;
}

/*
Multiply a matrix with a coefficient
*/
Matrix getMultipliedMatrix(Matrix mat, int coefficient)
{
    Matrix result = emptyCopyOf(mat);

    for (int i = 0; i < result.ligns; i++)
    {
        for (int j = 0; j < result.columns; j++)
        {
            result.content[i][j] = mat.content[i][j] * coefficient;
        }
    }

    return result;
}

Matrix sumMatrices(Matrix mat1, Matrix mat2)
{
    if (sameSize(mat1, mat2)) //If both matrices have the same size
    {
        Matrix result = emptyCopyOf(mat1);

        for (int i = 0; i < result.ligns; i++)
        {
            for (int j = 0; j < result.columns; j++)
            {
                result.content[i][j] = mat1.content[i][j] + mat2.content[i][j];
            }
        }
    }
}

int main()
{
    Matrix mat1 = build_matrix();
    displayMatrix(getMultipliedMatrix(mat1, 4));
}