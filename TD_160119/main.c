#include<stdio.h>
#include<stdlib.h>

/**
 * Calculer la factorielle d'un entier
 * @param n l'entier
 * @return sa factorielle
 */
float factorielle(int n) {
    int i;
    float produit = 1;

    for(i = 2; i <= n; i++) {
        produit *= i;
    }
    return produit;
}

int puissance(int n) {
    if(n % 2 == 0) {
        return 1;
    }
    return -1;
}

/*
 * Fonction (a) énoncé
 */
float functionA(int n) {
    int i;
    float somme = 0.0;

    for(i = 1; i <= n; i++) {
        somme += (i / factorielle(1 + i));
    }

    return somme;
}

/*
 * Fonction (b) énoncé
 */
float functionB(int n) {
    int i;
    float somme = 0.0;

    for(i = 1; i <= n; i++) {
        somme += ((i * (-1)*puissance(i)) / factorielle(1 + i));
    }
    return somme;
}

int main() {
    return 0;
}
