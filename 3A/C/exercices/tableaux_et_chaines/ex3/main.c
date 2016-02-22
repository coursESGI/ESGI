#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rechercher(int tab[]);

int main(int argc, char** argv)
{
    int tab[] = {11, 15, 13, 10, 8, 8, 13, 14};

    rechercher(tab);

    return 0;
}

void rechercher(int tab[]){
    int nombre, i, trouve = -1;

    printf("Entrez le nombre à chercher dans le tableau : ");

    scanf("%d", &nombre);

    for(i=0; i<8; i++){
        if(tab[i] == nombre)
            trouve = i;
    }

    if(trouve != -1)
        printf("position : %d", trouve);
    else
        printf("non trouvé");
}
