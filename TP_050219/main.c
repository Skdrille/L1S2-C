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
    int degre = 0;

    do
    {
        printf("Saisir coefficient [%d] : ", degre);
        scanf("%d", &coef);
        poly[degre] = coef;
        degre++;
    } while (degre <= degre_max);
    
    
}

void afficher_polynome(TPolynome poly, int degre_max, int derivee)
{
    if(derivee == 1) printf("P'(X) = ");
    else printf("P(X) = ");

    for(int i = degre_max; i >= 0; i--)
    {
        int coef = poly[i];

        if(coef != 0)
        {
            if(i > 0)
            {
                if(i == 1) printf("%dX + ", coef);
                else printf("%dX%d + ", coef, i);
            }  
            else printf("%d\n", coef);
        }
    }
}

float calculer_polynome(TPolynome poly, int degre_max, float x)
{
    float result = 0;

    for(int i = 0; i <= degre_max; i++)
    {
        int coef = poly[i];
        if(i == 0) result += coef;
        else result += coef * pow(x, i);
    }

    return result;
}

void somme_formelle_polynomes(TPolynome poly1, TPolynome poly2, int degre_max)
{
    TPolynome result;

    for(int i = 0; i <= degre_max; i++)
    {
        result[i] = poly1[i] + poly2[i];
    }

    afficher_polynome(result, degre_max, 0);
}

void derivee_formelle_polynome(TPolynome poly, int degre_max)
{
    TPolynome result;
    result[0] = 0;

    for(int i = 1; i <= degre_max; i++) //On commence à 2 car la dérivée de la constante sera égale à 0
    {
        result[i - 1] = poly[i] * i;
    }

    afficher_polynome(result, degre_max - 1, 1);
}

void produit_polynomes(TPolynome poly1, TPolynome poly2)
{

}

/*

Test des fonctions

*/
int main()
{
    TPolynome poly1, poly2;

    saisie_polynome(poly1, 3); //Pour cet exemple on créera un polynôme de degré 4
    afficher_polynome(poly1, 3, 0); //On l'affiche pour voir s'il n'y a pas d'erreur dans la saisie

    derivee_formelle_polynome(poly1, 3);

    return 0;
}