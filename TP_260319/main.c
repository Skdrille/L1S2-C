#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char titre[50];
    char auteur[50];
    char genre[50];
    int duree;
} TMorceau;

typedef struct
{
    int numero;
    char support[50];
    char titre_album[50];
    int nb_morceaux;
    TMorceau morceaux[20];
} TDisque;

typedef struct
{
    int nombreDisques;
    TDisque disques[50];
} TDiscotheque;

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
    scanf("%d", &morceau.duree);

    return morceau;
}

TDisque saisirDisque()
{
    TDisque disque;

    printf("Support : ");
    scanf("%s", &disque.support);

    printf("Titre album : ");
    scanf("%s", &disque.titre_album);

    printf("Nombre de morceaux a saisir : ");
    scanf("%d", &disque.nb_morceaux);

    for (int i = 0; i < disque.nb_morceaux; i++)
    {
        disque.morceaux[i] = saisirMorceau();
    }

    return disque;
}

TDiscotheque saisirDiscotheque()
{
    TDiscotheque discotheque;

    printf("Nombre de disques a saisir : ");
    scanf("%d", &discotheque.nombreDisques);

    for (int i = 0; i < discotheque.nombreDisques; i++)
    {
        TDisque disque = saisirDisque();
        disque.numero = i + 1;
        discotheque.disques[i] = disque;
    }

    return discotheque;
}

void afficherInformationsMorceau(TMorceau morceau)
{
    printf("\n[\n\tTitre : %s\n\tAuteur : %s\n\tGenre : %s\n\tDuree : %d\n]", morceau.titre, morceau.auteur, morceau.genre, morceau.duree);
}

void afficherInformationsDisque(TDisque disque)
{
    printf("\n--------------[Disque %d]--------------\n", disque.numero);
    printf("Titre album : %s\n", disque.titre_album);
    printf("Morceaux :\n");

    for (int i = 0; i < disque.nb_morceaux; i++)
    {
        afficherInformationsMorceau(disque.morceaux[i]);
    }
    printf("\n------------------------------------------\n");
}

void afficherInformationsDiscotheque(TDiscotheque discotheque)
{
    for (int i = 0; i < discotheque.nombreDisques; i++)
    {
        afficherInformationsDisque(discotheque.disques[i]);
    }
}

int dureeTotaleDisque(TDisque disque)
{
    int dureeTotale = 0;

    for (int i = 0; i < disque.nb_morceaux; i++)
    {
        dureeTotale += disque.morceaux[i].duree;
    }

    return dureeTotale;
}

int dureeTotaleDiscotheque(TDiscotheque discotheque)
{
    int dureeTotale = 0;

    for (int i = 0; i < discotheque.nombreDisques; i++)
    {
        dureeTotale += dureeTotaleDisque(discotheque.disques[i]);
    }

    return dureeTotale;
}

void afficherMorceaux(TDiscotheque discotheque, char auteur[50])
{
    for (int i = 0; i < discotheque.nombreDisques; i++)
    {
        TDisque disque = discotheque.disques[i];

        for (int j = 0; j < disque.nb_morceaux; j++)
        {
            if (strcmp(disque.morceaux[i].auteur, auteur) == 0)
            {
                afficherInformationsMorceau(disque.morceaux[i]);
            }
        }
    }
}

int main()
{
    TDiscotheque discotheque = saisirDiscotheque();
    afficherInformationsDiscotheque(discotheque);

    return 0;
}