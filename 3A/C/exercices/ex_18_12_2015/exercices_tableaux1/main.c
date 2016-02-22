#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[10], i;

    for(i = 0; i<10; i++){
        tab[i] = 0;
    }

    i = tab;

    printf("%d", i);

   /* for(i = 0; i<10; i++){
        printf("%d", tab[i]);
    }
*/
    return 0;
}
