#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
double genererValeurAPayer() 
{
    return ((double)rand() / RAND_MAX) * 1000.0;
}
 
double demanderPaiement() 
{
    double paiement;
    printf("Entrez la somme que vous souhaitez payer : ");
    scanf("%lf", &paiement);
    return paiement;
}
 
double calculerMonnaie(double montantAPayer, double paiement) 
{
    return paiement - montantAPayer;
}
 
void rendreMonnaie(double monnaie) 
{
    int billets[] = {2000, 1000, 500, 200, 100, 50, 25};
    int pieces[] = {20, 10, 5, 1, 50, 20, 5};
    
    printf("Monnaie rendue : \n");
 
    for (int i = 0; i < sizeof(billets) / sizeof(billets[0]); i++) {
        while (monnaie >= billets[i]) {
            printf("Billet de %d RS\n", billets[i]);
            monnaie -= billets[i];
        }
    }
 
    for (int i = 0; i < sizeof(pieces) / sizeof(pieces[0]); i++) {
        while (monnaie >= pieces[i]) {
            printf("Pièce de %d RS\n", pieces[i]);
            monnaie -= pieces[i];
        }
    }
}
 
int main() {
    srand(time(NULL));
 
    double valeurAPayer = genererValeurAPayer();
    printf("La valeur à payer est : %.2f RS\n", valeurAPayer);
 
    double paiement;
    do {
        paiement = demanderPaiement();
        if (paiement < valeurAPayer) {
            printf("Le paiement est insuffisant. Veuillez saisir une somme égale ou supérieure à %.2f RS\n", valeurAPayer);
        }
    } while (paiement < valeurAPayer);
 
    double monnaie = calculerMonnaie(valeurAPayer, paiement);
    printf("Monnaie à rendre : %.2f RS\n", monnaie);
 
    rendreMonnaie(monnaie);
    
    return 0;
}
