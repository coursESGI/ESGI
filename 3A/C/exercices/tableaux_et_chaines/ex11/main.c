#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenation();

int main(int argc, char** argv)
{
    concatenation();

    return 0;
}

void concatenation(){
    char chaine1[20];
    char chaine2[20];
    int faux = 0, nb;
    int nombre, i, taille_chaine_1 = 0, taille_chaine_2 = 0;

    printf("Entrez les deux chaînes\n");

    scanf("%s", chaine1);
    scanf("%s", chaine2);

    printf("Entrez le nombre\n");

    scanf("%d", &nb);

    while(chaine1[taille_chaine_1] != '\0'){
        taille_chaine_1++;
    }

    while(chaine2[taille_chaine_2] != '\0'){
        taille_chaine_2++;
    }

    if(taille_chaine_1 == taille_chaine_2){
        for(i=nb; i<taille_chaine_1; i++){
            if(chaine1[i] != chaine2[i])
                faux = 1;
        }
    }
    else
        faux = 1;

    if(faux == 1)
        printf("chaînes différentes");
    else
        printf("chaînes identiques");
}
