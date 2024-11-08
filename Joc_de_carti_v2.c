#include <stdio.h>
#include <stdlib.h>

typedef struct joc{
    char nume[20];
    int carte;
    struct joc *next;
} joc_t;

struct joc *creare_nod(){
    struct joc *nod_nou=malloc(sizeof(joc_t));
    scanf("%s", nod_nou->nume);
    scanf("%d", &nod_nou->carte);
    nod_nou->next=NULL;
    return nod_nou;
}

struct joc *adaugare(struct joc *head){
    if(head==NULL){
        head=creare_nod();
        return head;
    }
    joc_t *nod_curent, *nod_nou;
    nod_curent=head;
    while(nod_curent!=NULL){
        if(nod_curent->next==NULL){
            nod_nou=creare_nod();
            nod_curent->next=nod_nou;
            return head;
        }
        nod_curent=nod_curent->next;
    }
}

int main(){
    int nr_jucatori;
    scanf("%d", &nr_jucatori);
    //for()
    
    return 0;
}
