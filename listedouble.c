#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* init_simple_circulaire(int n) {
    if (n <= 0) return NULL;
    Node *head = NULL, *temp = NULL, *last = NULL;
    for (int i = 0; i < n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (!head) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    last->next = head;
    return head;
}

Node* insert_tete_simple_circulaire(Node *head, int val) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    if (!head) {
        new_node->next = new_node;
        return new_node;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    new_node->next = head;
    temp->next = new_node;
    return new_node;
}

void afficher_simple_circulaire(Node *head) {
    if (!head) return;
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

Node* init_double_circulaire(int n) {
    if (n <= 0) return NULL;
    Node *head = NULL, *temp = NULL, *last = NULL;
    for (int i = 0; i < n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = NULL;
        if (!head) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
    last->next = head;
    head->prev = last;
    return head;
}

Node* insert_tete_double_circulaire(Node *head, int val) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    if (!head) {
        new_node->next = new_node;
        new_node->prev = new_node;
        return new_node;
    }
    Node *last = head->prev;
    new_node->next = head;
    new_node->prev = last;
    last->next = new_node;
    head->prev = new_node;
    return new_node;
}

void afficher_double_circulaire(Node *head) {
    if (!head) return;
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choix, n, val;
    Node *head = NULL;
    printf("1. Liste simple chainee circulaire\n2. Liste double chainee circulaire\nVotre choix: ");
    scanf("%d", &choix);
    printf("Donner le nombre d'elements de la liste initiale: ");
    scanf("%d", &n);
    printf("Entrer les elements:\n");
    if (choix == 1) {
        head = init_simple_circulaire(n);
        printf("Liste initiale: ");
        afficher_simple_circulaire(head);
        printf("Entrer la valeur a inserer en tete: ");
        scanf("%d", &val);
        head = insert_tete_simple_circulaire(head, val);
        printf("Liste apres insertion: ");
        afficher_simple_circulaire(head);
    } else if (choix == 2) {
        head = init_double_circulaire(n);
        printf("Liste initiale: ");
        afficher_double_circulaire(head);
        printf("Entrer la valeur a inserer en tete: ");
        scanf("%d", &val);
        head = insert_tete_double_circulaire(head, val);
        printf("Liste apres insertion: ");
        afficher_double_circulaire(head);
    }
    return 0;
}