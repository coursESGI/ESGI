#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tri(int tab[]);
void tri_inverse(int tab[]);

int main(int argc, char** argv)
{
    int tab[] = {11, 15, 13, 10, 8, 8, 13, 14};

    tri(tab);

    printf("\n \n");

    tri_inverse(tab);

    return 0;
}

void tri(int tab[]){
    int temp, i, k;

        do{

            k = 0;

            for(i=0; i<7; i++){
                if(tab[i] > tab[i+1]){
                    temp = tab[i];
                    tab[i] = tab[i+1];
                    tab[i+1] = temp;

                    k = 1;
                }
            }
        }while(k != 0);

    for(i=0; i<8; i++){
        printf("%d ", tab[i]);
    }
}

void tri_inverse(int tab[]){
    int temp, i, k;

        do{

            k = 0;

            for(i=0; i<7; i++){
                if(tab[i] < tab[i+1]){
                    temp = tab[i];
                    tab[i] = tab[i+1];
                    tab[i+1] = temp;

                    k = 1;
                }
            }
        }while(k != 0);

    for(i=0; i<8; i++){
        printf("%d ", tab[i]);
    }
}
