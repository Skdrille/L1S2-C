#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef int TPolynome[50];

void saisie_polynome(TPolynome poly, int degre_max)
{
    int coef;
    int degre = 1;

    do
    {
        printf("Saisir coefficient [%d] : ", degre);
        scanf("%d", &coef);
        poly[degre] = coef;
        degre++;
    } while (degre <= degre_max);
    
    
}

void afficher_polynome(TPolynome poly, int degre_max)
{
    printf("P(X) = ");

    for(int i = degre_max; i >= 1; i--)
    {
        int coef = poly[i];
        if(i == 1) printf("%d\n", coef);
        else printf("%dX%d + ", coef, i);   
    }
}

int calculer_polynome(TPolynome poly, int degre_max, float x)
{
    int result = 0;

    for(int i = 1; i <= degre_max; i++)
    {
        int coef = poly[i];
        if(i == 1) result += coef;
        else result += coef * pow(x, i);
    }

    return result;
}

int main()
{
    TPolynome poly;

    saisie_polynome(poly, 4);
    afficher_polynome(poly, 4);

    float x;
    printf("Entrez la valeur de X a calculer : ");
    scanf("%f", &x);

    printf("Pour X = %f, resultat = %d", x, calculer_polynome(poly, 4, x));

    return 0;
}