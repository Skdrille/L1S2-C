#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*



[Séance n°3] TP Programmation C



*/

typedef int TPolynome[50];
TPolynome poly1, poly2;
int DEGRE_MAX;

void saisie_polynome(TPolynome poly, int degre_max)
{
    int coef;
    int degre = 0;

    do
    {
        printf("Saisir coefficient [%d] : ", degre);
        scanf("%d", &coef);
        poly[degre] = coef;
        degre++;
    } while (degre <= degre_max);
}

void afficher_polynome(TPolynome poly, int derivee)
{
    printf(derivee == 1 ? "P'(X) = " : "P(X) = ");

    for (int i = (derivee == 1 ? DEGRE_MAX - 1 : DEGRE_MAX); i >= 0; i--)
    {
        int coef = poly[i];

        if (coef != 0)
        {
            if (i > 0)
            {
                if (i == 1)
                    printf("%dX + ", coef);
                else
                    printf("%dX%d + ", coef, i);
            }
            else
                printf("%d\n", coef);
        }
    }
}

void calculer_polynome(TPolynome poly)
{
    float x;

    printf("\nEntrez une valeur de x a calculer : ");
    scanf("%f", &x);

    float result = 0;

    for (int i = 0; i <= DEGRE_MAX; i++)
    {
        int coef = poly[i];
        if (i == 0)
            result += coef;
        else
            result += coef * pow(x, i);
    }

    printf("Resultat : %.2f", result);
}

void somme_formelle_polynomes(TPolynome poly1, TPolynome poly2)
{
    TPolynome result;

    for (int i = 0; i <= DEGRE_MAX; i++)
    {
        result[i] = poly1[i] + poly2[i];
    }

    afficher_polynome(result, 0);
}

void derivee_formelle_polynome(TPolynome poly)
{
    TPolynome result;
    result[0] = 0;

    for (int i = 1; i <= DEGRE_MAX; i++) //On commence à 2 car la dérivée de la constante sera égale à 0
    {
        result[i - 1] = poly[i] * i;
    }

    afficher_polynome(result, 1);
}

void produit_polynomes(TPolynome poly1, TPolynome poly2)
{
    TPolynome result_poly;
    int result;

    for (int i = 0; i <= DEGRE_MAX; i++)
    {
        result = 0;

        for (int j = 0; j <= DEGRE_MAX; j++)
        {
            result += poly1[i] * poly2[j];
        }

        result_poly[i] = result;
    }

    afficher_polynome(result_poly, 0);
}

int demander_degre_max()
{
    int degre_max;

    printf("Degre max du polynome : ");
    scanf("%d", &degre_max);

    return degre_max;
}

float demander_x()
{
    float x;

    printf("Entrez une valeur de X a calculer : ");
    scanf("%f", &x);

    return x;
}

int afficher_menu_principal()
{
    printf("\n\n\n");
    printf("<1> - Saisir un polynome\n");
    printf("<2> - Calculer la somme S = A + B\n");
    printf("<3> - Calculer le produit P = A * B\n");
    printf("<4> - Calculer la derivee D = P'\n");
    printf("<5> - Afficher un polynome\n");
    printf("<6> - Calculer une image\n");
    printf("<0> - Quitter le programme\n");

    int user_choice;
    scanf("%d", &user_choice);

    switch (user_choice)
    {
    case 0: //Fin du programme
        break;

    case 1:

        /* On demande quel polynome l'utilisateur souhaite saisir */
        printf("<1> Polynome 1 \n<2> Polynome 2\n");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 1:
            saisie_polynome(poly1, DEGRE_MAX);
            afficher_polynome(poly1, 0);
            break;

        case 2:
            saisie_polynome(poly2, DEGRE_MAX);
            afficher_polynome(poly2, 0);
            break;

        default:
            printf("Veuillez appuyer sur une touche correcte !\n");
            break;
        }

        afficher_menu_principal();
        break;

    case 2:

        somme_formelle_polynomes(poly1, poly2);
        afficher_menu_principal();
        break;

    case 3:

        produit_polynomes(poly1, poly2);
        afficher_menu_principal();
        break;

    case 4:

        printf("<1>Derivee polynome 1 \n<2>Derivee polynome 2\n");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 1:

            derivee_formelle_polynome(poly1);
            break;

        case 2:

            derivee_formelle_polynome(poly2);
            break;

        default:
            printf("Veuillez choisir un polynome correct !");
            break;
        }

    case 5:
        menu_afficher_polynome();
        break;

    case 6:
        printf("<1> Polynome 1 \n<2> Polynome 2\n");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 1:
            calculer_polynome(poly1);
            break;

        case 2:
            calculer_polynome(poly2);
            break;

        default:
            printf("Veuillez appuyer sur une touche correcte !\n");
            break;
        }

        break;
    }

    afficher_menu_principal();
    return 0;
}

void menu_afficher_polynome()
{
    printf("\n");
    printf("<1> Afficher A\n");
    printf("<2> Afficher B\n");
    printf("<3> Afficher S\n");
    printf("<4> Afficher P\n");
    printf("<5> Afficher D\n");
    printf("<0> Quitter\n");

    int user_choice;
    scanf("%d", &user_choice);

    switch (user_choice)
    {
    case 1:

        afficher_polynome(poly1, 0);
        menu_afficher_polynome();
        break;
    case 2:

        afficher_polynome(poly2, 0);
        menu_afficher_polynome();
        break;

    case 3:

        somme_formelle_polynomes(poly1, poly2);
        menu_afficher_polynome();
        break;

    case 4:

        printf("Fonctionnalite en cours de dev...");
        menu_afficher_polynome();
        break;

    case 5:

        printf("<1>Derivee polynome 1 \n<2>Derivee polynome 2\n");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 1:

            derivee_formelle_polynome(poly1);
            break;

        case 2:

            derivee_formelle_polynome(poly2);
            break;

        default:

            printf("Veuillez choisir un polynome correct !");
            break;
        }
        menu_afficher_polynome();
        break;

    case 0: //Retour au menu principal
        return;
        break;
    }
}

int main()
{
    DEGRE_MAX = demander_degre_max();
    return afficher_menu_principal();
}