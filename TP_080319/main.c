#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define KGRN  "\x1B[32m"
#define KNRM  "\x1B[0m"


/*
0 = vide, 1 = génération
*/
typedef int TGeneration[15][15];
int generation = 1;
TGeneration lastGeneration;

void buildGeneration(TGeneration g)
{
    srand(time(NULL));

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            g[i][j] = rand() % 2;
        }
    }
}

void displayGeneration(TGeneration g)
{
    printf("\n-----(%d)-----\n\n", generation);

    for(int i = 0; i < 15; i++)
    {
        printf("\n");
        for(int j = 0; j < 15; j++)
        {
            printf("|%d", g[i][j]);
        }
        printf("|");
    }
}

int getNumberOfOccupiedCases(TGeneration g, int i, int j)
{
    int occupied = 0;

    for(int k = -1; k < 2; k++)
    {
        for(int l = -1; l < 2; l++)
        {
            if(g[i - k][j - l] == 1) occupied++;
        }
    }

    return occupied;
}

void displayNextGeneration(TGeneration g)
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            lastGeneration[i][j] = g[i][j];

            int occupied = getNumberOfOccupiedCases(g, i, j);

            if(g[i][j] == 0 && occupied == 3)
            {
                g[i][j] = 1;
            }else if(g[i][j] == 1 && (occupied == 2 || occupied == 3))
            {
                g[i][j] = 1;
            }else
            {
                g[i][j] = 0;
            }
            
        }
    }

    generation++;
    displayGeneration(g);
}

void displayXGenerations()
{
    TGeneration g;
    buildGeneration(g);

    int userInput;

    printf("Entrez le nb de generations a afficher : ");
    scanf("%d", &userInput);

    displayGeneration(g);

    for(int i = 1; i < userInput; i++)
    {
        displayNextGeneration(g);
    }
}

int isGenerationEvolving(TGeneration g)
{
    int evolving = 0;

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(g[i][j] != lastGeneration[i][j])
            {
                evolving = 1;
            }
        }
    }

    return evolving;
}

void displayGenerationWhileEvolving()
{
    TGeneration g;
    buildGeneration(g);

    displayGeneration(g);

    int i = 0;

    do
    {
        displayNextGeneration(g);
        i++;
    } while (isGenerationEvolving(g) && i <= 2000);

    if(i == 2000) /*Display limit*/
    {
        printf("Stopped program to avoid displaying infinitly");
    }
    
}

int main()
{
    displayGenerationWhileEvolving();
    return 0;
}


