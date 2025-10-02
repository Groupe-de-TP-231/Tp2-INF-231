#include <stdio.h>
#include <stdlib.h>

typedef struct NoeudSC {
    int valeur;
    struct NoeudSC *suivant;
} NoeudSC;

typedef struct NoeudDC {
    int valeur;
    struct NoeudDC *suivant;
    struct NoeudDC *precedent;
} NoeudDC;

void insererSC(NoeudSC **tete, int val) {
    NoeudSC *nouv = malloc(sizeof(NoeudSC));
    nouv->valeur = val;
    nouv->suivant = NULL;
    if (*tete == NULL || (*tete)->valeur >= val) {
        nouv->suivant = *tete;
        *tete = nouv;
        return;
    }
    NoeudSC *actuel = *tete;
    while (actuel->suivant && actuel->suivant->valeur < val)
        actuel = actuel->suivant;
    nouv->suivant = actuel->suivant;
    actuel->suivant = nouv;
}

void afficherSC(NoeudSC *tete) {
    while (tete) {
        printf("%d ", tete->valeur);
        tete = tete->suivant;
    }
    printf("\n");
}

void insererDC(NoeudDC **tete, int val) {
    NoeudDC *nouv = malloc(sizeof(NoeudDC));
    nouv->valeur = val;
    nouv->suivant = NULL;
    nouv->precedent = NULL;
    if (*tete == NULL || (*tete)->valeur >= val) {
        nouv->suivant = *tete;
        if (*tete) (*tete)->precedent = nouv;
        *tete = nouv;
        return;
    }
    NoeudDC *actuel = *tete;
    while (actuel->suivant && actuel->suivant->valeur < val)
        actuel = actuel->suivant;
    nouv->suivant = actuel->suivant;
    nouv->precedent = actuel;
    if (actuel->suivant) actuel->suivant->precedent = nouv;
    actuel->suivant = nouv;
}

void afficherDC(NoeudDC *tete) {
    while (tete) {
        printf("%d ", tete->valeur);
        tete = tete->suivant;
    }
    printf("\n");
}

int main() {
    int choix, n, val, i;
    NoeudSC *teteSC = NULL;
    NoeudDC *teteDC = NULL;
    printf("1. Liste simplement chainee\n2. Liste doublement chainee\nVotre choix: ");
    scanf("%d", &choix);
    printf("Nombre d'elements a inserer: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Entrez la valeur: ");
        scanf("%d", &val);
        if (choix == 1)
            insererSC(&teteSC, val);
        else
            insererDC(&teteDC, val);
    }
    printf("Liste initiale: ");
    if (choix == 1)
        afficherSC(teteSC);
    else
        afficherDC(teteDC);
    printf("Entrez la valeur a inserer: ");
    scanf("%d", &val);
    if (choix == 1) {
        insererSC(&teteSC, val);
        afficherSC(teteSC);
    } else {
        insererDC(&teteDC, val);
        afficherDC(teteDC);
    }
    return 0;
}