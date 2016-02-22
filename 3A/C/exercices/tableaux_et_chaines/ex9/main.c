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
    char chaine3[40];
    int nombre, i, taille_chaine_1 = 0, taille_chaine_2 = 0;

    scanf("%s", chaine1);
    scanf("%s", chaine2);

    while(chaine1[taille_chaine_1] != '\0'){
        taille_chaine_1++;
    }

    while(chaine2[taille_chaine_2] != '\0'){
        taille_chaine_2++;
    }

    for(i=0; i<taille_chaine_1; i++){
        chaine3[i] = chaine1[i];
    }

    for(i=0; i<taille_chaine_2; i++){
        chaine3[i+taille_chaine_1] = chaine2[i];
    }

    printf("%s", chaine3);
}
