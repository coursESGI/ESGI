#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>

/*#include "menu.h"
#include "choisir_regles_partie.h"*/

void menu();
int quitter(int);
void choisir_regles_partie();
void flush();
void debut_jeu(char *, char *, char *, int *);
void initialiser_le_mot(char [], char []);
void afficher_mot_(char [], int);
int remplacer_lettres_trouvees(char [], char [], char);
int verifier_mot_trouve(char [], int);
void touche_joueur(int, int, int [][4]);
void afficher_etat_adversaire(int, int [][4]);

int main(int argc, char** argv)
{
    menu();

    char bonhomme[4][14][20]= {
        {
            "    _______     ",
            "   |       |    ",
            "   |       _    ",
            "   |      / \\  ",
            "   |      \\_/  ",
            "   |            ",
            "  /|\\          ",
            " / | \\         "
        },
        {
            "    _______     ",
            "   |       |    ",
            "   |       _    ",
            "   |      / \\  ",
            "   |      \\_/  ",
            "   |      _|_   ",
            "   |     /| |\\ ",
            "   |    / |_| \\",
            "   |            ",
            "  /|\\          ",
            " / | \\         "
        },
        {
            "    _______     ",
            "   |       |    ",
            "   |       _    ",
            "   |      / \\  ",
            "   |      \\_/  ",
            "   |      _|_   ",
            "   |      | |   ",
            "   |      |_|   ",
            "   |       ^    ",
            "   |      / \\  ",
            "   |     /   \\ ",
            "   |            ",
            "  /|\\          ",
            " / | \\         "
        },
        {
            "    _______     ",
            "   |       |    ",
            "   |       _    ",
            "   |      / \\  ",
            "   |      \\_/  ",
            "   |      _|_   ",
            "   |     /| |\\ ",
            "   |    / |_| \\",
            "   |       ^    ",
            "   |      / \\  ",
            "   |     /   \\ ",
            "   |            ",
            "  /|\\          ",
            " / | \\         "
        }
    };

    int i;

    for(i = 0; i<14; i++){
        printf("\n%s", bonhomme[3][i]);
    }

    return 0;
}

void flush(){
    char c;
    while((c=getchar()) == -1);
}

void menu(){
    int reponse;

    do{
        printf("           MENU");
        printf("\n\nTapez 1 pour lancer le jeu");
        printf("\nTapez 0 pour quitter");

        printf("\n Réponse : ");
        scanf("%d", &reponse);
    }while(reponse < 0 || reponse > 4);

    switch(reponse){
    case 0:
        quitter(0); ///0 <=> ne sauvegarde rien
        break;
    case 1:
        choisir_regles_partie();
        break;
    }

    printf("\n\nAu revoir ! \n");
}

int quitter(int save){
    if(save == 0)
        return 0;
    else if(save == 1){
        printf("Nom du fichier pour enregistrer le score");

        return 0;
    }
}

void choisir_regles_partie(){
    char joueur1[20], joueur2[20];
    char parieur1[20];
    int nb_parieurs;

    /** nom des joueurs */

    printf("Entrez le nom du joueur A : ");
    flush();
    //scanf("%s", joueur1);
    fgets(joueur1, 20, stdin);
    if(strlen(joueur1)<=20) joueur1[strlen(joueur1)-1]='\0';

    printf("Entrez le nom du joueur B : ");
    //flush();
    //scanf("%s", joueur2);
    fgets(joueur2, 20, stdin);
    if(strlen(joueur2)<=20) joueur2[strlen(joueur2)-1]='\0';

    printf("joueur : %s", joueur1);
    printf(" se bat contre joueur %s", joueur2);

    /** fonction qui récupère nombre de parieurs (0 ou 1) */
    nb_parieurs = demande_nb_parieurs();

    if(nb_parieurs != 0){ /// s'il y a un parieur
       /** nom du parieur */

        printf("Entrez le nom du parieur : ");
        flush();
        fgets(parieur1, 20, stdin);
        if(strlen(parieur1)<=20) parieur1[strlen(parieur1)-1]='\0';

        //printf("%s", parieur1);
    }

    debut_jeu(&joueur1, &joueur2, &parieur1, &nb_parieurs);

    //printf("nb : %d", nb_parieurs);
}

int demande_nb_parieurs(){
    int nb = -1;

    do{
         printf("\nVoulez-vous un parieur ? ");
         printf("\nTapez 1 pour oui et 0 pour non : ");
         scanf("%d", &nb);
     }while(nb != 1 && nb != 0);
}

void debut_jeu(char *joueur1, char *joueur2, char *parieur1, int *nb_parieurs){
    //printf("\nnom du joueur 1 : %s, nb_parieurs : %d", joueur1, nb_parieurs);

    int i, points_j1 = 0, points_j2 = 0, pos, tourJ = 1, nb_essais = 0, trouve = 0; /// tourJ : au tour de joueur 1
    char mots_a_trouver[3][20] = {"clavicule", "cerveau", "rotule"}; /// pos % 4 == 0 : bras
    /// pos % 4 == 1 : jambes
    /// pos % 4 == 2 : tête
    /// pos % 4 == 3 : corps
    int reste_au_joueur[2][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}}; /// [0][1] == 0 : jambes du joueur 1 manquantes, [0][1] == 1 si présentes
    char mot_[20];

    srand(time(NULL));

    pos = rand()%3;    /// position du mot dans le tableau

    //printf("%s", mots_a_trouver[1]);

    //printf("\n%d", strlen(mots_a_trouver[1]));

    printf("\nMot : %s\n", mots_a_trouver[pos]);

    initialiser_le_mot(mot_, mots_a_trouver[pos]);///remplie mot_ de _

    ///affiche le mot à trouver
    afficher_mot_(mot_, strlen(mots_a_trouver[pos]));

    char lettre;
    //int indice_trouve[20]; // indices des lettres trouvée

    while(tourJ == 1){

        afficher_etat_adversaire(2, reste_au_joueur); /// affiche le personnage adverse

        trouve = 0;
        printf("\nAu tour du joueur %s ...", joueur1);
        printf("entrez une lettre : ");
        scanf(" %c", &lettre);

        if(remplacer_lettres_trouvees(mots_a_trouver[pos], mot_, lettre) != 1){ /// remplace lettres trouvées qui correspondent à celles entrée
           nb_essais++; /// n'a pas trouvé la bonne lettre
        }

        afficher_mot_(mot_, strlen(mots_a_trouver[pos]));

        if( verifier_mot_trouve(mot_, strlen(mots_a_trouver[pos])) == 1 ){                                      /// si le mot a été trouvé
            if(nb_essais == 0)
                printf("bravo, vous avez trouvé le mot %s du premier coup", mots_a_trouver[pos]);
            else
                printf("bravo, vous avez trouvé le mot %s et vous n'avez échoué que %d fois.", mots_a_trouver[pos], nb_essais);

            tourJ = 2;

            ///points_j1 = afficher_nb_de_points(points_j1, strlen(mots_a_trouver[pos]), nb_essais);

            ///touche_joueur(2, pos, reste_au_joueur);
        }
    }
}

void afficher_mot_(char mot_[], int taille){
    int i;

    printf("\n\nmot à trouver : ");
    for(i=0; i<taille; i++){
        printf("%c ", mot_[i]);
    }
}

int verifier_mot_trouve(char mot_[], int taille){
    int i;

    for(i=0; i<taille; i++){
        if(mot_[i] == '_')
            return 0;
    }

    return 1;
}

/**int afficher_nb_de_points(nb_points_actuels, taille_mot, nb_essais){

}*/

/** numéro_joueur == 0 pour joueur1 et 1 pour joueur2  */
void touche_joueur(int numero_joueur, int position_mot_a_trouver, int reste_au_joueur[][4]){ /// position_mot_a_trouver : position du mot dans le tableau
    int position_touchee = position_mot_a_trouver % 4;

    if(reste_au_joueur[numero_joueur - 1][position_touchee] == 1){
        reste_au_joueur[numero_joueur - 1][position_touchee] = 0;
        printf("touché");
    }
    else{
        printf("déjà touché à cet endroit");
    }
}

void afficher_etat_adversaire(int numero_joueur, int reste_au_joueur[][4]){
    int i;

    printf("\n\nEtat actuel du joueur %d : \n", numero_joueur);

    for(i = 0; i<4; i++){
        printf("partie du corps %d : %d", i+1, reste_au_joueur[numero_joueur-1][i]);
    }
}

void initialiser_le_mot(char mot_[], char mots_a_trouver[]){
    int i;

    for(i=0; i<strlen(mots_a_trouver); i++){
        mot_[i] = '_';
    }
}

int remplacer_lettres_trouvees(char mots_a_trouver[], char mot_[], char lettre){
    int i, trouve = 0;

    for(i=0; i<strlen(mots_a_trouver); i++){
            if(mots_a_trouver[i] == lettre){
                mot_[i] = lettre;                       /// retourne trouve et change mot_ en pointeur
                trouve = 1; ///a trouvé une lettre
            }
        }

        if(trouve == 1)
            return 1;

        return 0;
}
