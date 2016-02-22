#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, somme = 0;

    for(i = 1; i<=100; i++){
        somme += i;
    }

    printf("%d", somme);

    return 0;
}
