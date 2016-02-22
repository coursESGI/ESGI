#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
int main(int argc, char** argv)
{
    int a=2, b=4, c=2;
    int d=b/a/c;
    a = b/b/c;
    printf("%d", 3+7/7*7); //arrondit en-dessous

    return 0;
}
*/


int aire(rayon){
int resultat = M_PI*pow(rayon, 2); /// périmètre : 2 * MP_I * rayon
                                   /// pythagore : sqrt(pow(a, 2) + pow(b, 2))
return resultat;
}

int main(int argc, char** argv)
{
    int rayon = 10, resultat;

    resultat = aire(rayon);

    printf("%d", resultat);

    return 0;
}





