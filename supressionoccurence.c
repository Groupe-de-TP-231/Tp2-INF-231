#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

Element* ajouter_fin(Element* liste, int valeur) {
    Element* nouveau = malloc(sizeof(Element));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    if (!liste) return nouveau;
    Element* tmp = liste;
    while (tmp->suivant) tmp = tmp->suivant;
    tmp->suivant = nouveau;
    return liste;
}

void afficher(Element* liste) {
    Element* tmp = liste;
    while (tmp) {
        printf("%d ", tmp->valeur);
        tmp = tmp->suivant;
    }
    printf("\n");
}

Element* supprimer_occurence(Element* liste, int valeur) {
    while (liste && liste->valeur == valeur) {
        Element* tmp = liste;
        liste = liste->suivant;
        free(tmp);
    }
    Element* courant = liste;
    while (courant && courant->suivant) {
        if (courant->suivant->valeur == valeur) {
            Element* tmp = courant->suivant;
            courant->suivant = tmp->suivant;
            free(tmp);
        } else {
            courant = courant->suivant;
        }
    }
    return liste;
}

int main() {
    Element* liste = NULL;
    int n, val, supp;
    printf("Nombre d'elements : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i+1);
        scanf("%d", &val);
        liste = ajouter_fin(liste, val);
    }
    printf("Liste : ");
    afficher(liste);
    printf("Entrez la valeur a supprimer : ");
    scanf("%d", &supp);
    liste = supprimer_occurence(liste, supp);
    printf("Nouvelle liste : ");
    afficher(liste);
    while (liste) {
        Element* tmp = liste;
        liste = liste->suivant;
        free(tmp);
    }
    return 0;
}