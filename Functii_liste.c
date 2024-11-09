struct node{
    struct node *next;
} node_t;

node_t *creare_nod(){
    node_t *nod_nou = malloc(sizeof(node_t));
    // citire date
    nod_nou->next = NULL;
    return nod_nou;
}

node_t *adaugare_nod_sfarsit_lista(struct node *head){
    node_t *nod_curent = head;

    if (head == NULL) {
        return creare_nod();
    }

    while (nod_curent->next != NULL){
        nod_curent = nod_curent->next;
    }

    nod_curent->next = creare_nod();
    return head;
}

node_t *adaugare_nod_inceput_lista(struct node *head){
    struct node *nod_nou = creare_nod();
    nod_nou->next = head;
    return nod_nou;
}

node_t *eliminare_nod_sfarsit_lista(struct node *head){
    node_t *nod_curent = head, *nod_sters = NULL;

    if (head == NULL){
        return NULL;
    }

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    while (nod_curent->next->next != NULL){
        nod_curent = nod_curent->next;
    }

    nod_sters = nod_curent->next;
    free(nod_sters);
    nod_curent->next = NULL;
    return head;
}

node_t *eliminare_nod_inceput_lista(struct node *head){
    struct node *nod_curent = head;

    if (head == NULL){
        return NULL;
    }

    nod_curent = head;
    head = head->next;
    free(nod_curent);
    return head;
}
