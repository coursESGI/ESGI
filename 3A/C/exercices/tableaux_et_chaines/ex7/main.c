#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palindrome();

int main(int argc, char** argv)
{
    palindrome();

    return 0;
}

void palindrome(){
    char mot[20], tab[20];
    int i, j=7, nb_lettres = 0, faux = 0;

    scanf("%s", mot);

    while(mot[i] != '\0'){
        i++;
    }

    nb_lettres = i;


    for(i=0, j=nb_lettres-1; i<nb_lettres; i++, j--){
        if(mot[i] != mot[j]){
            faux = 1;
            break;
        }
    }

    if(faux == 0)
        printf("palindrome");
    else
        printf("ce n'est pas un palindrome");
}
