#include <stdio.h>
#include <stdlib.h>

typedef struct joc{
    char nume[20];
    int carte;
    struct joc *next;
} joc_t;

joc_t *creare_nod(){
    joc_t *nod_nou=malloc(sizeof(joc_t));
    scanf("%s", nod_nou->nume);
    nod_nou->next=NULL;
    return nod_nou;
}

joc_t *adaugare(joc_t *head){
    if(head==NULL)
        return creare_nod();
    
    joc_t *nod_curent=head;
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare_nod();
    return head;
}

void afisare(joc_t *head){
    joc_t *nod_curent=head;
    
    if(head==NULL)
        return;
    
    while(nod_curent!=NULL){
        printf("%s\n", nod_curent->nume);
        nod_curent=nod_curent->next;
    }
}

joc_t *eliminare(joc_t *head){
    joc_t *nod_curent=head, *min=head, *prev_min=NULL, *prev=NULL;
    while(nod_curent!=NULL){
        if(nod_curent->carte<min->carte){
            min=nod_curent;
            prev_min=prev;
        }
        prev=nod_curent;
        nod_curent=nod_curent->next;
    }
    if(min==head)
        head=head->next;
    else
        prev_min->next=min->next;
    free(min);
    return head;
}

int main(){
    int nr_jucatori;
    joc_t *lista_joc=NULL;
    
    scanf("%d", &nr_jucatori);
    for(int i=0;i<nr_jucatori;i++)
        lista_joc=adaugare(lista_joc);
    afisare(lista_joc);
    
    while(lista_joc!=NULL){
        joc_t *nod_curent=lista_joc;
        while(nod_curent!=NULL){
            scanf("%d", &nod_curent->carte);
            nod_curent=nod_curent->next;
        }
        lista_joc=eliminare(lista_joc);
        afisare(lista_joc);
    }
    
    return 0;
}
