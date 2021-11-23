
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


int n = 0; // number of accounts.
char** nomePrenome;
char** cin;
int* montant;



void triComptes(){
      // variables pour enregistrer les accounts apres chaque tour de bocle pour le triage.
    char triNomePrenome[20];
    char triCin[20];
    int triMontant;

    for (int i = n-1 ; i >= 0 ; i--){
        strcpy(triNomePrenome, nomePrenome[i]);
        strcpy(triCin, cin[i]);
        triMontant = montant[i];


        for(int j = i ; j >= 0; j--){
            if(triMontant > montant[j]){
                strcpy(triNomePrenome, nomePrenome[j]);
                strcpy(triCin, cin[j]);
                triMontant = montant[j];

                strcpy(nomePrenome[j], nomePrenome[i]);
                strcpy(nomePrenome[i], triNomePrenome);

                strcpy(cin[j], cin[i]);
                strcpy(cin[i], triCin);

                montant[j] = montant[i];
                montant[i] = triMontant;

            }
        }
    }
}


int main() {

        bool compte = false;// if false print the warning message to enter acounte first...
        bool usFidelisation = false;// check if he all ready use this promo.



        start:
        system("cls");
        printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
        printf("\t1-Introduire un compte bancaire.\n\t2-Introduire plusier comptes bancaire.\n\t3-Operations (Retrait-Depot).\n\t4-Affichage.\n\t5-Fidelisation.\n\t6-Quitter l\'application.\n");
        printf("\n\t\t\033[0;34m-----------------------------------------------------------------------------------------\033[0m\n");
        if(compte != true){
            printf("\n\t\t\t\033[0;41m-Attention:\033[0;31m vous dovez premierment entrer un ou plusier comptes.\033[0m"); //pintf le condition qui est important. warning to enter acount first.
        }
        int choixMenu;// stocker le menu choix du client.
        printf("\n\n  choisi l'opperation que tu veux : ");
        scanf("%d", &choixMenu);


        while(choixMenu < 0 || choixMenu > 7){ // start again if the input is not much with the menu using while loop.
            printf("le choix que tu a entrer est pas dans le menu. voller essayer autre fois : ");
            scanf("%d", &choixMenu);
        }


        if(choixMenu == 1){
            n = 1;
            // allocat memory for the arrays.
            nomePrenome = malloc(sizeof(char*) * n);
            cin = malloc(sizeof(char*) * n);
            montant = malloc(sizeof(int) * n);
            for(int i = 0 ; i < n ; i++){
                nomePrenome[i] = malloc(sizeof(char) * 20);
                cin[i] = malloc(sizeof(char) * 20);
            }

            printf("\nvoller entrer le Nome et le Prenome du compte svp : ");
            scanf("\n");
            scanf("%[^\n]s", nomePrenome[0]); // registre le nome et prenome du compte bancaire;

            printf("\nvoller entrer le CIN du compte svp : ");
            scanf("\n");
            scanf("%[^\n]s", cin[0]); // registre le CIN du compte bancaire;

            printf("\nvoller entrer le Montant du compte svp : ");
            scanf("%d", &montant[0]); // registre le montant du compte bancaire;

            system("cls");
            printf("le compte que tu entrer : \n");
            printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n", nomePrenome[0], cin[0], montant[0]);
            printf("le compte est regestrer, clicker entrer pour retour a la menu.\n");

            compte = true;// turn variable true if there is atleast one acount;
            system("pause");
            goto start;




        } else if(choixMenu == 2){
            printf("qu\'elle est le nombre de compte tu veux : ");
            scanf("%d", &n);
            // allocat memory for the arrays.
            nomePrenome = malloc(sizeof(char*) * n);
            cin = malloc(sizeof(char*) * n);
            montant = malloc(sizeof(int) * n);
            for(int i = 0 ; i < n ; i++){
                nomePrenome[i] = malloc(sizeof(char) * 20);
                cin[i] = malloc(sizeof(char) * 20);
            }

            for(int i = 0 ; i < n ; i++){ // entrer les comptes
                printf("\nvoller entrer le Nome et le Prenome du compte N %d svp : ", i+1);
                scanf("\n");
                scanf("%[^\n]s", nomePrenome[i]); // registre le nome et prenome du dcompte bancaire;

                printf("\nvoller entrer le CIN du compte N %d svp : ", i+1);
                scanf("\n");
                scanf("%[^\n]s", cin[i]); // registre le CIN du dcompte bancaire;

                printf("\nvoller entrer le Montant du compte N %d svp : ", i+1);
                scanf("%d", &montant[i]); // registre le montant du dcompte bancaire;
                printf("\n\033[0;32m--------------------------le compte a ete registrer-------------------------\033[0m\n");
            }
            system("cls");
            printf("les comptes que tu entrer : \n\n");
            for(int i = 0 ; i < n ; i++){// display les comptes
                printf("Compte N%d :\n", i + 1);
                printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                printf("--------------------------------------------------------------\n");
            }
            printf("le compte est regestrer, clicker entrer pour retour ou la menu.\n");
            compte = true; // turn variable true if ther is atleas one compte;
            system("pause");
            goto start;


        } else if(choixMenu == 3){
            if (n <= 0){// reteur au menu si il y a pas du comptes.
                printf("\n\a\033[0;31m\t!!!tu doit enregistre un aux plusieur comptes pour cette operation.\033[0m\n");
                system("pause");
                goto start;
            }

            system("cls");
            printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
            printf("\t1-Retrait.\n\t2-Depot.\n\t3-Reteur au menu.\n");
            int operationsMenu; // variable that store client's choice on 3)Opérations (Retrait-Dépôt).
            printf("\n\nchoisi l'opperation que tu veux : ");
            scanf("%d", &operationsMenu);

            while(operationsMenu < 0 || operationsMenu > 3){ // start again if the input is not much with the Opérations menu using while loop.
                printf("le choix que tu a entre est pas dans le menu. voller essayer autre fois : ");
                scanf("%d", &operationsMenu);
            }

            if(operationsMenu == 1){
                if(n == 1){// if there is only one account. Retrait
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n", nomePrenome[0], cin[0], montant[0]);
                    printf("\n--------------------------------------------------------------\n\n");
                    int retrait;
                    bool retraitValable = true;
                    while(retraitValable) {
                        printf("Entrer le montant que tu veux retirai dans le compte : ");
                        scanf("%d", &retrait);// store the amount from the client.
                        if(retrait > 0 && retrait <= montant[0]) {// checking if the input is correct.
                            montant[0] -= retrait;
                            retraitValable = false;
                        } else if(retrait > montant[0]) {
                            printf("\n\t\a\033[0;31mVotre argent est pas suffisant pour retrait ce montant.\033[0m\n");
                        } else if (retrait <= 0){
                            printf("\n\t\a\033[0;31mce montant est pas valable.\033[0m\n");
                        } else if(!isdigit(retrait)) {
                            printf("\n\t\a\033[0;31mEntrer un numero valable svp.\033[0m\n");
                        }
                    }

                    // display la dernier version du compte avec le retrait.
                    system("cls");
                    printf("\n\n\n\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\033[0;33m *Nouveau Montant\033[0m\n",nomePrenome[0], cin[0], montant[0]);
                    printf("\n\t\033[0;31mRetrait : %dDH.\033[0m", retrait);
                    printf("\n--------------------------------------------------------------\n");
                    system("pause");
                    goto start;

                } else if(n >= 2){// if there arr more than one account. Retrait
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    printf("\n\n");
                    for(int i = 0 ; i < n ; i++){ // display les comptes qui ont enregistrer.
                        printf("Compte N%d :\n", i + 1);
                        printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                        printf("--------------------------------------------------------------\n");
                    }
                    int numCompte;
                    printf("\nEntrer la numero de compte qui tu veux fair l'opperation : ");
                    scanf("%d", &numCompte);
                    while(numCompte < 0 || numCompte > n){
                        printf("\n\033[0;31mle choix est pas correct.\033[0m\n");
                        printf("Entrer la numero de compte qui tu veux fair l'opperation : ");
                        scanf("%d", &numCompte);
                    }
                    numCompte--;
                    int retrait;
                    bool retraitValable = true;
                     while(retraitValable) {
                        printf("Entrer le montant que tu veux retirai dans ce compte : ");
                        scanf("%d", &retrait);// store the amount from the client.
                        if(retrait > 0 && retrait <= montant[numCompte]) {// checking if the input is correct.
                            montant[numCompte] -= retrait;
                            retraitValable = false;
                        } else if(retrait > montant[numCompte]) {
                            printf("\n\t\a\033[0;31mVotre argent est pas suffisant pour retrait ce montant.\033[0m\n");
                        } else if (retrait <= 0){
                            printf("\n\t\a\033[0;31mce montant est pas valable.\033[0m\n");
                        } else if(!isdigit(retrait)) {
                            printf("\n\t\a\033[0;31mEntrer un numero valable svp.\033[0m\n");
                        }
                    }
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    printf("\n");
                    for(int i = 0 ; i < n ; i++){ // display les comptes qui ont enregistrer.
                        printf("Compte N%d :\n", i + 1);
                        if(i == numCompte){
                            printf("\n\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\033[0;33m *Nouveau Montant\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                            printf("\n\t\033[0;31mRetrait : %dDH.\033[0m\n\n", retrait);
                            printf("--------------------------------------------------------------\n");
                        } else {
                            printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                            printf("--------------------------------------------------------------\n");
                        }
                    }
                    system("pause");
                    goto start;
                }

                //*** end the retrait part.

            } else if(operationsMenu == 2){
                if(n == 1) {// if there is only one account. Depot
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n", nomePrenome[0], cin[0], montant[0]);
                    printf("\n--------------------------------------------------------------\n\n");

                    int depot;
                    bool depotValable = true;
                     while(depotValable) {
                        printf("  Entrer le montant que tu veux le depot dans le compte : ");
                        scanf("%d", &depot);// store the amount from the client.
                        if(depot > 0) {// checking if the input is correct.
                            montant[0] += depot;
                            depotValable = false;
                        } else if (depot <= 0){
                            printf("\n\t\a\033[0;31mce montant est pas valable.\033[0m\n");
                        } else {
                            printf("\n\t\a\033[0;31mEntrer un numero valable svp.\033[0m\n");
                        }
                     }
                     // display le dernier donner de compte avec le retrait.
                    system("cls");
                    printf("\n\n\n\033[0;36m\tNome et Penome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\033[0;33m *Nouveau Montant\033[0m\n",nomePrenome[0], cin[0], montant[0]);
                    printf("\n\t\033[0;32mDepot : %dDH.\033[0m", depot);
                    printf("\n--------------------------------------------------------------\n");
                    system("pause");
                    goto start;

                } else if(n >= 2){// if there arr more than one account. Depot
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    printf("\n\n");
                    for(int i = 0 ; i < n ; i++){ // display les comptes qui ont enregistrer.
                        printf("Compte N%d :\n", i + 1);
                        printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                        printf("--------------------------------------------------------------\n");
                    }
                    int numCompte;
                    printf("\n  Entrer la numero de compte qui tu veux fair l'opperation : ");
                    scanf("%d", &numCompte);
                    while(numCompte < 0 || numCompte > n){
                        printf("\n\033[0;31mle choix est pas correct.\033[0m\n");
                        printf("Entrer la numero de compte qui tu veux fair l'opperation : ");
                        scanf("%d", &numCompte);
                    }
                    numCompte--;
                    int depot;
                    bool depotValable = true;
                    while(depotValable) {
                        printf("  Entrer le montant que tu veux le depot dans ce compte : ");
                        scanf("%d", &depot);// store the amount from the client.
                        if(depot > 0) {// checking if the input is correct.
                            montant[numCompte] += depot;
                            depotValable = false;
                        } else if (depot <= 0){
                            printf("\n\t\a\033[0;31mce montant est pas valable.\033[0m\n");
                        } else {
                            printf("\n\t\a\033[0;31mEntrer un numero valable svp.\033[0m\n");
                        }
                     }
                     system("cls");
                     printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                     printf("\n");
                     for(int i = 0 ; i < n ; i++){ // display les comptes qui ont enregistrer.
                        printf("Compte N%d :\n", i + 1);
                        if(i == numCompte){
                            printf("\n\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\033[0m\033[0;33m *Nouveau Montant\n",nomePrenome[i], cin[i], montant[i]);
                            printf("\n\t\033[0;32mRetrait : %dDH.\033[0m\n\n", depot);
                            printf("--------------------------------------------------------------\n");
                        } else {
                            printf("\n\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                            printf("--------------------------------------------------------------\n");
                        }
                    }

                    system("pause");
                    goto start;
                }

                //*** end the depot part.

            } else if(operationsMenu == 3){
                goto start;
            }

            //************************** end of the Operation ***********************************




        } else if(choixMenu == 4){
            if (n < 2){// reteur au menu si il y a pas des comptes.
                printf("\n\a\033[0;31m\t!!!tu doit enregistre plusieur comptes pour cette operation.\033[0m\n");
                system("pause");
                goto start;
            }

            system("cls");
            printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
            printf("\t1-Par Ordre Ascendant.\n\t2-Par Ordre Descendant.\n\t3-Recherche par CIN.\n\t4-Reteur au menu.\n");
            int affichageMenu; // variable that store client's choice on 4)Affichage.
            printf("\n\n  choisi l\'opperation que tu veux : ");
            scanf("%d" ,&affichageMenu);

            while(affichageMenu < 0 || affichageMenu > 4){ // start again if the input is not much with the Affichage menu using while loop.
                printf("le choix que tu a entre est pas dans le menu. voller essayer autre fois : ");
                scanf("%d", &affichageMenu);
            }

            if(affichageMenu == 1){//tri par Ascendant partie.
                system("cls");
                printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                printf("\t1-Par Ordre Ascendant.\n\t2-Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit).\n\t3-Reteur au menu.\n");
                int triChoix; //registrer le choix de tri.
                printf("\n\n  choisi l\'opperation que tu veux : ");
                scanf("%d", &triChoix);
                while(triChoix <= 0 || triChoix > 3){ // checking if the input of triChoix variable is valable or note.
                    printf("\n\033[0;31mle choix est pas correct.\033[0m\n");
                    printf("\n\n  choisi l\'opperation que tu veux : ");
                    scanf("%d", &triChoix);
                }

                if(triChoix == 1){
                    // call the sorting function.
                    triComptes();
                    // display the new list of accounts with sorting (tri Ascendant).
                    system("cls");
                    int x = 1;
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    for(int i = n-1 ; i >= 0 ; i--){ // display les comptes qui est enregistrer.
                        printf("Compte N%d :\n", x);
                        printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                        printf("--------------------------------------------------------------\n");
                        x++;
                    }
                    printf("  Clicker entrer pour retour ou menu.\n");
                    system("pause");
                    goto start;

                    //---------------------------------------------------------------------------------

                } else if (triChoix == 2){
                    printf("\n  Entrer le montant pour trier les comptes qui ayant ce montant : ");
                    int montantTri;
                    scanf("%d", &montantTri);
                    // call the sorting function.
                    triComptes();
                    // display the new list of accounts with sorting (tri Descendant).
                    system("cls");
                    int x = 1;
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    for(int i = n-1 ; i >= 0 ; i--){ // display les comptes qui est enregistrer.
                        if(montant[i] >= montantTri){
                            printf("Compte N%d :\n", x);
                            printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                            printf("--------------------------------------------------------------\n");
                            x++;
                        }
                    }
                    printf("  Clicker entrer pour retour ou menu.\n");
                    system("pause");
                    goto start;

                }


            } else if(affichageMenu == 2){ //tri par Descendant partie.
                system("cls");
                printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                printf("\t1-Par Ordre Descendant.\n\t2-Par Ordre Descendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit).\n\t3-Reteur au menu.\n");
                int triChoix; //registrer le choix de tri.
                printf("\n\n  choisi l\'opperation que tu veux : ");
                scanf("%d", &triChoix);
                while(triChoix <= 0 || triChoix > 3){ // checking if the input of triChoix variable is valable or note.
                    printf("\n\033[0;31mle choix est pas correct.\033[0m\n");
                    printf("\n\n  choisi l\'opperation que tu veux : ");
                    scanf("%d", &triChoix);
                }

                if(triChoix == 1){
                    // call the sorting function.
                    triComptes();
                    // display the new list of accounts with sorting (tri Descendant).
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");

                    for(int i = 0 ; i < n ; i++){ // display les comptes qui est enregistrer.
                        printf("Compte N%d :\n", i + 1);
                        printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                        printf("--------------------------------------------------------------\n");
                    }
                    printf("  Clicker entrer pour retour ou menu.\n");
                    system("pause");
                    goto start;

                    //---------------------------------------------------------------

                } else if (triChoix == 2){
                    printf("\n  Entrer le montant pour trier les comptes qui ayant ce montant : ");
                    int montantTri;
                    scanf("%d", &montantTri);
                    // call the sorting function.
                    triComptes();
                    // display the new list of accounts with sorting (tri Descendant).
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    for(int i = 0 ; i < n ; i++){ // display les comptes qui est enregistrer.
                        if(montant[i] >= montantTri){
                            printf("Compte N%d :\n", i + 1);
                            printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                            printf("--------------------------------------------------------------\n");
                        }
                    }
                    printf("  Clicker entrer pour retour ou menu.\n");
                    system("pause");
                    goto start;

                }



            } else if (affichageMenu == 3){
                chercherAutrefois:
                system("cls");
                printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                printf("  c'est quoi la CIN de compte qui tu veux le recherche : ");
                char rechercheCIN[20];
                bool isDoneRecherche = false; // check if there is an accounte with same CIN;
                scanf("%s", rechercheCIN);
                for(int i = 0 ; i < n ; i++){
                    if(!strcmp(rechercheCIN, cin[i])){//strcmp is for checking if rechercheCIN value is in cin[i].
                        printf("\n  la resultat du recherche : \n");
                        printf("\n\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                        printf("\n--------------------------------------------------------------\n\n");
                        isDoneRecherche = true;
                        break;
                    }
                }
                if(isDoneRecherche == false){
                    printf("\n\033[0;31m il y a pas un compte bancair avec ce CIN.\033[0m\n\n");
                    printf("  \tEntrer:\t\t1-pour rechercher autre fois.\t2-pour retour aux menu principal.\n");
                    printf("\nvotre choix : ");
                    int r; // store the choice that given above.
                    scanf("%d", &r);
                    while(r != 1 && r != 2){
                        printf("\n  \033[0;31m\l'entree est pas correct.\033[0m\n");
                        printf("  Entrer\t\t1-pour rechercher autre fois.\t2-pour retour aux menu principal.\n");
                        printf("\nvotre choix : ");
                        scanf("%d", &r);
                    }
                    if(r == 1){
                        goto chercherAutrefois; // go to serch more time.
                    } else if (r == 2) {
                        goto start; // go to the menu principal.
                    }
                } else {
                    printf("\n  Clicker Entrer pour retour ou menu principale.\n");
                    system("pause");
                    goto start;
                }

            } else if(affichageMenu == 4){
                goto start;
            }

            //*************************************************************





        } else if(choixMenu == 5){
            if (n < 2){// reteur au menu si il y a pas des comptes.
                printf("\n\a\033[0;31m\t!!!tu doit enregistre plusieur comptes pour cette operation.\033[0m\n");
                system("pause");
                goto start;

            } else if (usFidelisation){
                printf("\n tu est deja utiliser cette promo.\n");
                system("pause");
                goto start;
            }

            system("cls");
            printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
            printf("\t1-Ajouter 1.3%% aux comptes ayant les 3 premiers montants superieurs.\n\t2-Reteur au menu.\n");
            int fidelisationMenu;// variable that store client's choice on 5)Fidélisation.
            printf("\n\n  choisi l'opperation que tu veux : ");
            scanf("%d", &fidelisationMenu);

            while(fidelisationMenu < 0 || fidelisationMenu > 2){  // start again if the input is not much with the Fidélisation menu using while loop.
                printf("\033[0;31m  le choix que tu a entre est pas dans le menu.\033[0m\nvoller essayer autre fois : ");
                scanf("%d", &fidelisationMenu);
            }

            if(fidelisationMenu == 1){
                // call the sorting function.
                triComptes();
                // add 1.3% to the big 3 accounts.
                if(n <= 3){ // if there is 3 or less accounts.
                    for(int i = 0 ; i < n ; i++){
                        montant[i] *= 1.013;
                    }
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    printf("\n");
                    for(int i = 0 ; i < n ; i++){ // display les comptes qui ont ajouter la Fedelisation.
                        printf("Compte N%d :\n", i + 1);
                        printf("\n\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\033[0m\033[0;33m *Nouveau Montant\n",nomePrenome[i], cin[i], montant[i]);
                        printf("\n\t\033[0;32mFidelisation : +%dDH.\033[0m\n\n", (montant[i]/1.013) - montant[i]);
                        printf("--------------------------------------------------------------\n");
                    }

                } else { // if there is more than 3 accounts.
                    int a = 3;
                    int numOfFidelisation = 0; // numero du comptes qui ajoute le montant de fedelisation.
                    int maxIndexFidelisation = 0;
                    while(a > 0){
                        if(montant[maxIndexFidelisation] != montant[maxIndexFidelisation + 1]){// check if there is an account with same amount of mony.
                            a--;
                        }
                        montant[maxIndexFidelisation] *= 1.013;

                        numOfFidelisation++;
                        maxIndexFidelisation++;
                    }
                    system("cls");
                    printf("\n\t\t\t\t\033[0;44m      \t        \033[0;34m   Gestion Bancaire   \033[0m\033[0;44m        \t       \033[0m\n\n");
                    printf("\n");
                    for(int i = 0 ; i < numOfFidelisation ; i++){ // display les comptes qui ont ajouter la Fedelisation.
                        printf("Compte N%d :\n", i + 1);
                        printf("\n\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\033[0m\033[0;33m *Nouveau Montant\n",nomePrenome[i], cin[i], montant[i]);
                        printf("\n\t\033[0;32mFidelisation : +%dDH.\033[0m\n\n", montant[i] - (montant[i]/1.013));
                        printf("--------------------------------------------------------------\n");
                    }

                }
                    usFidelisation = true;
                    system("pause");
                    goto start;

                    // ==== ent fedelisation part ====

                } else if(fidelisationMenu == 2){
                    goto start;
                }





            //*************************************************************




        } else if(choixMenu == 6){
            printf("\n\n\t\t\t\t\033[0;34m****** you exite\'s from the programe ******\033[0m\n");
            return 1;


        } else if (choixMenu == 7){
            if (n == 0){// reteur au menu si il y a pas des comptes.
                printf("\n\a\033[0;31m\t!!!tu doit enregistre plusieur comptes premierment.\033[0m\n");
                system("pause");
                goto start;
            }
            system("cls");
                printf(" le compte que tu entrer : \n\n");
            for(int i = 0 ; i < n ; i++){ // display les comptes qui est enregistrer.
                printf("Compte N%d :\n", i + 1);
                printf("\033[0;36m\tNome et Prenome : %s.\n\tCIN : %s.\n\tMontant : %dDH.\033[0m\n",nomePrenome[i], cin[i], montant[i]);
                printf("--------------------------------------------------------------\n");
            }
            printf(" le compte est regestrer, clicker entrer pour retour a la menu.\n");
            system("pause");
            goto start;

        } else {
            goto start;
        }

        for(int i = 0 ; i < n ; i++){
            free(nomePrenome[i]);
            nomePrenome = NULL;
            free(cin[i]);
            cin[i] = NULL;
        }

        free(nomePrenome);
        free(cin);
        free(montant);



// I NEED TO USE FLOAT OR DOUBL


    return 0;
}



