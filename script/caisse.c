#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
double genererValeurAPayer() {
    return ((double)rand() / RAND_MAX) * 1000.0;
}
 
double demanderPaiement() {
    double paiement;
    printf("Entrez la somme que vous souhaitez payer : ");
    scanf("%lf", &paiement);
    return paiement;
}
 
int main() {
    srand(time(NULL));
 
    double valeurAPayer = genererValeurAPayer();
    printf("La valeur à payer est : %.2f\n", valeurAPayer);
 
    double paiement;
    do {
        paiement = demanderPaiement();
        if (paiement < valeurAPayer) {
            printf("Le paiement est insuffisant. Veuillez saisir une somme égale ou supérieure à %.2f\n", valeurAPayer);
        }
    } while (paiement < valeurAPayer);
 
    printf("Merci pour votre paiement de %.2f. Vous avez payé la totalité de votre facture.\n", paiement);
    
    return 0;
}
