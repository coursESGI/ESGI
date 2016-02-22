#include <stdio.h>
#include <stdlib.h>
/*
int main() /// exercice 5
{
    int min = -1, max = -1, i, somme = 0;

    do{
        printf("borne minimum : ");
        scanf("%d", &min);
    }while(min < 0 || min > 100 );

    do{
        printf("borne maximum : ");
        scanf("%d", &max);
    }while(min < 0 || min > 100 );

    for(i = min; i<=max; i++){
        somme += i;
    }

    printf("%d", somme);

    return 0;
}
*/
/*
int main() /// exercice 5
{
    int i, somme = 0;

    for(i = 2; i<=100; i++){
        if(i%2 == 0)
            somme += i;
    }

    printf("%d", somme);

    return 0;
}
*/

/*
int main() /// exercice 6
{
    int i, somme = 0;

    for(i = 1; i<=20; i++){
        printf("%d", i);

        if(i%3 == 0)
            printf("\n");
    }
    return 0;
}
*/

/*
int main() /// exercice 7
{
    int i, nombre, resultat = 1;

    scanf("%d", &nombre);

    for(i = 1; i<=nombre; i++){
        resultat *= i;
    }

    printf("%d", resultat);

    return 0;
}
*/

/*
int main() /// exercice 8
{
    int i, nombre, resultat = 1;

    scanf("%d", &nombre);

    nombre = factorielle(1, nombre, 1);

    printf("%d", nombre);

    return 0;
}

int factorielle(int i, int nombre, int resultat){
        resultat *= i;

    if(i >= nombre)
        return resultat;

    return factorielle(i+1, nombre, resultat);
}
*/


int main() /// exercice 8
{
    int nombre;

    scanf("%d", &nombre);

    while(nombre > 0){
        printf("%d", nombre%10);

        nombre = nombre/10;
    }

    return 0;
}

