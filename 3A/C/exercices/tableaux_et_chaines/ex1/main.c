#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rechercher(int tab[]);

int main(int argc, char** argv)
{
    int tab[] = {11, 15, 13, 10, 8, 8, 13, 14};

    if(rechercher(tab) == 1)
        printf("oui");
    else
        printf("non");

    return 0;
}

int rechercher(int tab[]){
    int nombre, i;

    printf("Entrez le nombre à chercher dans le tableau : ");

    scanf("%d", &nombre);

    for(i=0; i<8; i++){
        if(tab[i] == nombre)
            return 1;
    }

    return 0;
}
