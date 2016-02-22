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
    int faux = 0;
    int nombre, i, taille_chaine_1 = 0, taille_chaine_2 = 0;

    scanf("%s", chaine1);
    scanf("%s", chaine2);

    while(chaine1[taille_chaine_1] != '\0'){
        taille_chaine_1++;
    }

    while(chaine2[taille_chaine_2] != '\0'){
        taille_chaine_2++;
    }

    if(taille_chaine_1 == taille_chaine_2){
        for(i=0; i<taille_chaine_1; i++){
            if(chaine1[i] != chaine2[i])
                faux = 1;
        }
    }
    else
        faux = 2;

    if(faux == 1)
        printf("chaînes différentes");
    else if(faux == 2)
        printf("les chaînes n'ont pas la même taille");
    else
        printf("chaînes identiques");
}
