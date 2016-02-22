#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverser(int tab[]);

int main(int argc, char** argv)
{
    int tab[] = {11, 15, 13, 10, 8, 8, 13, 14};

    inverser(tab);

    return 0;
}

void inverser(int tab[]){
    int nombre, nombre2, i, indice1 = -1, indice2 = -1;

    printf("Entrez le premier nombre : ");
    scanf("%d", &nombre);
    printf("Entrez le second nombre : ");
    scanf("%d", &nombre2);

    for(i=0; i<8; i++){
        if(tab[i] == nombre){
            indice1 = i;
        }
        else if(tab[i] == nombre2){
            indice2 = i;
        }
    }

    if(indice1 != -1 && indice1 != -1){
        i = tab[indice1];
        tab[indice1] = tab[indice2];
        tab[indice2] = i;
    }

    for(i=0; i<8; i++){
        printf("%d ", tab[i]);
    }
}
