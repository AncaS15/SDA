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
    scanf("%d", &nod_nou->carte);
    nod_nou->next=NULL;
    return nod_nou;
}

joc_t *adaugare(joc_t *head){
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

void afisare(joc_t *head){
    
}

int main(){
    int nr_jucatori;
    joc_t *lista_joc=NULL;
    
    scanf("%d", &nr_jucatori);
    for(int i=0;i<nr_jucatori;i++){
        lista_joc=adaugare(lista_joc);
    }
        
    
    return 0;
}
