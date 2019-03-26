#include<stdlib.h>
#include<stdio.h>
#include<string.h>

static int numero = 0;

typedef struct {
    char titre[50];
    char auteur[50];
    char genre[50];
    int duree;
} TMorceau;

typedef struct {
    int numero;
    char support[50];
    char titre_album[50];
    int nb_morceaux;
    TMorceau morceaux[20];
} TDisque;

TMorceau saisirMorceau()
{
    TMorceau morceau;

    printf("Titre : ");
    scanf("%s", &morceau.titre);

    printf("Auteur : ");
    scanf("%s", &morceau.auteur);

    printf("Genre : ");
    scanf("%s", &morceau.genre);

    printf("Duree : ");
    scanf("%d", morceau.duree);

    return morceau;
}

TDisque saisirDisque()
{
    TDisque disque;
    disque.numero = ++numero;

    printf("Support : ");
    scanf("%s", &disque.support);


    printf("Titre album : ");
    scanf("%s", &disque.titre_album);


    printf("Nombre de morceaux a saisir : ");
    scanf("%d", &disque.nb_morceaux);

    for(int i = 0; i < disque.nb_morceaux; i++)
    {
        disque.morceaux[i] = saisirMorceau();
    }

    return disque;
}

void afficherInformationsMorceau(TMorceau morceau)
{
    printf("\n[\n\tTitre : %s\n\tAuteur : %s\n\tGenre : %s\n\tDuree : %d\n]", morceau.titre, morceau.auteur, morceau.genre, morceau.duree);
}

void afficherInformationsDisque(TDisque disque)
{
    printf("===========[Disque %d]===========\n", disque.numero);
    printf("Titre album : %s\n", disque.titre_album);
    printf("Morceaux :\n");

    for(int i = 0; i < disque.nb_morceaux; i++)
    {
        afficherInformationsMorceau(disque.morceaux[i]);
    }
    printf("=================================\n");

}

int main()
{
    TDisque disque = saisirDisque();
    afficherInformationsDisque(disque);

    return 0;
}