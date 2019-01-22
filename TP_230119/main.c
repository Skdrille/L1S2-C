#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Vérifie si un nombre est premier
 */
int estPremier(int n)
{
    int nbDiviseurs = 0;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            nbDiviseurs++;
        }
    }

    return n == 1 || nbDiviseurs == 2;
}

/*
 * Retourne le k-ième nombre premier
 */
int KiemeNombrePremier(int k)
{
    int p = 1;

    for(int i = 1; i < k; i++)
    {
        if(estPremier(i)) p++;
    }

    return p;
}

/*
 * Vérifie si deux nombres sont amis.
 */
int sontAmis(int a, int b)
{
    int sommeA = 0, sommeB = 0;

    for(int i = 1; i <= a; i++)
    {
        if(a % i == 0) sommeA += i;
    }

    for(int i = 1; i <= b; i++)
    {
        if(b % i == 0) sommeB += i;
    }

    return sommeA == sommeB;
}

int main() {
    printf("%d", KiemeNombrePremier(7));
    return 0;
}