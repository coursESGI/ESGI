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
    int i, j, tab2[8];

    for(i=0, j=7; i<8; i++, j--){
       tab2[i] = tab[j];
    }

    for(i=0; i<8; i++){
        tab[i] = tab2[i];
    }

    for(i=0; i<8; i++){
        printf("%d", tab[i]);
    }
}
