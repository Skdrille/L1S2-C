#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*



[Séance n°3] TP Programmation C



*/

typedef int TPolynome[50];

void saisie_polynome(TPolynome poly, int degre_max)
{
    int coef;
    /*

    On commence au degré 1 et pas 0 (comme écrit dans le sujet) pour pourvoir saisir directement la constante a la fin du polynôme
    */
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
        if(i == 1) printf("%d\n", coef); //Pour éviter l'apparition d'un "+" après la constante à la fin du polynôme
        else printf("%dX%d + ", coef, i);   
    }
}

float calculer_polynome(TPolynome poly, int degre_max, float x)
{
    float result = 0;

    for(int i = 1; i <= degre_max; i++)
    {
        int coef = poly[i];
        if(i == 1) result += coef;
        else result += coef * pow(x, i);
    }

    return result;
}

/*

Test des fonctions

*/
int main()
{
    TPolynome poly;

    saisie_polynome(poly, 4); //Pour cet exemple on créera un polynôme de degré 4
    afficher_polynome(poly, 4); //On l'affiche pour voir s'il n'y a pas d'erreur dans la saisie

    /*
    Calcule d'un X saisi par l'utilisateur
    */
    float x;
    printf("Entrez la valeur de X a calculer : ");
    scanf("%f", &x);

    printf("Pour X = %f, resultat = %f", x, calculer_polynome(poly, 4, x));

    return 0;
}