#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cuvant{
    char litera;
    struct cuvant *next;
} cuvant_t;

cuvant_t *creare(char litera){
    cuvant_t *nod_nou=malloc(sizeof(cuvant_t));
    nod_nou->litera=litera;
    nod_nou->next=NULL;
    return nod_nou;
}

cuvant_t *adaugare_inceput(cuvant_t *head, char litera){
    cuvant_t *nod_nou=creare(litera);
    nod_nou->next=head;
    return nod_nou;
}

cuvant_t *eliminare(cuvant_t *head){
    cuvant_t *nod_curent=head;
    if(head==NULL)
        return NULL;
    nod_curent=head;
    head=head->next;
    free(nod_curent);
    return head;
}

int verif_vocala(char c){
    c=tolower(c);
    if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o')
        return 1;
    return 0;
}

int main(){
    char cuvant[100];
    cuvant_t *v=NULL;
    cuvant_t *c=NULL;
    
    scanf("%s", cuvant);
    for(int i=0;i<strlen(cuvant);i++){
        if(verif_vocala(cuvant[i]))
            v=adaugare_inceput(v,cuvant[i]);
        else
            c=adaugare_inceput(c,cuvant[i]);
    }
    
    int alternare=1;
    while(v!=NULL || c!=NULL){
        if((alternare==1 && v!=NULL) || c==NULL){
            printf("%c", v->litera);
            v=eliminare(v);
            alternare=0;
        }
        else if(c!=NULL){
            printf("%c", c->litera);
            c=eliminare(c);
            alternare=1;
        }
    }
    
    return 0;
}
