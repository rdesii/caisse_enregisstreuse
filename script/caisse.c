#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define NB_BILLETS 7
#define NB_PIECES 7
 
typedef struct {
    int billets[NB_BILLETS];
    int pieces[NB_PIECES];
} Stock;
 
double genererValeurAPayer() {
    return ((double)rand() / RAND_MAX) * 1000.0;
}
 
double demanderPaiement() {
    double paiement;
    printf("Entrez la somme que vous souhaitez payer : ");
    scanf("%lf", &paiement);
    return paiement;
}
 
double calculerMonnaie(double montantAPayer, double paiement) {
    return paiement - montantAPayer;
}
 
void rendreMonnaie(double monnaie, Stock *stock) {
    int billets[] = {2000, 1000, 500, 200, 100, 50, 25};
    int pieces[] = {20, 10, 5, 1, 50, 20, 5};
 
    printf("Monnaie rendue :\n");
 
    for (int i = 0; i < NB_BILLETS; i++) {
        while (monnaie >= billets[i] && stock->billets[i] > 0) {
            printf("Billet de Rs%d\n", billets[i]);
            monnaie -= billets[i];
            stock->billets[i]--;
        }
    }
 
    for (int i = 0; i < NB_PIECES; i++) {
        while (monnaie >= pieces[i] && stock->pieces[i] > 0) {
            printf("Pièce de Rs%d\n", pieces[i]);
            monnaie -= pieces[i];
            stock->pieces[i]--;
        }
    }
}
 
int verifierStocks(Stock stock) {
    for (int i = 0; i < NB_BILLETS; i++) {
        if (stock.billets[i] > 0) {
            return 1;
        }
    }
    for (int i = 0; i < NB_PIECES; i++) {
        if (stock.pieces[i] > 0) {
            return 1;
        }
    }
    return 0;
}
 
void afficherStocks(Stock stock) {
    printf("Stock de billets :\n");
    for (int i = 0; i < NB_BILLETS; i++) {
        printf("Billet de Rs%d : %d\n", (i == NB_BILLETS - 1) ? 1 : (i + 1) * 50, stock.billets[i]);
    }
    printf("Stock de pièces :\n");
    for (int i = 0; i < NB_PIECES; i++) {
        printf("Pièce de Rs%d : %d\n", (i == NB_PIECES - 1) ? 5 : (i + 1) * 5, stock.pieces[i]);
    }
}
 
void remplirCaisse(Stock *stock) {
    for (int i = 0; i < NB_BILLETS; i++) {
        stock->billets[i] = 50;
    }
    for (int i = 0; i < NB_PIECES; i++) {
        stock->pieces[i] = 50;
    }
    printf("La caisse a été remplie.\n");
}
 
int main() {
    srand(time(NULL));
 
    Stock stock;
    remplirCaisse(&stock);
 
    while (1) {
        double valeurAPayer = genererValeurAPayer();
        printf("La valeur à payer est : %.2f\n", valeurAPayer);
 
        double paiement;
        do {
            paiement = demanderPaiement();
            if (paiement < valeurAPayer) {
                printf("Le paiement est insuffisant. Veuillez saisir une somme égale ou supérieure à %.2f\n", valeurAPayer);
            }
        } while (paiement < valeurAPayer);
 
        double monnaie = calculerMonnaie(valeurAPayer, paiement);
        printf("Monnaie à rendre : %.2f\n", monnaie);
 
        if (monnaie > 0 && verifierStocks(stock)) {
            rendreMonnaie(monnaie, &stock);
            afficherStocks(stock);
        } else {
            printf("Le stock de billets et de pièces est épuisé.\n");
            char choix;
            printf("Que souhaitez-vous faire ? (C: fermer la caisse / R: remplir la caisse) : ");
            scanf(" %c", &choix);
            if (choix == 'C' || choix == 'c') {
                break;
            } else if (choix == 'R' || choix == 'r') {
                remplirCaisse(&stock);
            } else {
                printf("Choix invalide.\n");
            }
        }
    }
    
    return 0;
}
