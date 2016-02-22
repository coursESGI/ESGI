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
    int nb_lettres_en_commun = 0, trouve = 0;
    int nombre, i, taille_chaine_1 = 0, taille_chaine_2 = 0;

    printf("Entrez les deux chaînes\n");

    scanf("%s", chaine1);
    scanf("%s", chaine2);

    while(chaine1[taille_chaine_1] != '\0'){
        taille_chaine_1++;
    }

    while(chaine2[taille_chaine_2] != '\0'){
        taille_chaine_2++;
    }

    for(i=0; i<taille_chaine_1, i<taille_chaine_2; i++){
        if(chaine1[i] == chaine2[j]){
            nb_lettres_en_commun++;

            if(nb_lettres_en_commun == taille_chaine_2)
                trouve = 1;
        }
        else{
            nb_lettres_en_commun = 0;
            j++;
        }
    }

    if(trouve == 1)
        printf("trouvé");
    else
        printf("non trouvé");
}
