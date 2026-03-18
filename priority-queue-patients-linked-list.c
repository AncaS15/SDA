#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pacienti{
    char nume[31], prenume[31], sex;
    int varsta;
    int prioritate;
    struct pacienti *next;
} pacient;

pacient *creare(pacient *head){
    if(head==NULL){
        pacient *nod_nou=malloc(sizeof(pacient));
        scanf("%s%s", nod_nou->nume, nod_nou->prenume);
        scanf("%d", &nod_nou->varsta);
        getchar();
        scanf("%c", &nod_nou->sex);
        scanf("%d", &nod_nou->prioritate);
        getchar();
        nod_nou->next=NULL;
        return nod_nou;
    }
    pacient *nod_curent=head;
    pacient *nod_nou=malloc(sizeof(pacient));
    scanf("%s%s", nod_nou->nume, nod_nou->prenume);
    scanf("%d", &nod_nou->varsta);
    getchar();
    scanf("%c", &nod_nou->sex);
    scanf("%d", &nod_nou->prioritate);
    getchar();
    nod_nou->next=NULL;
    if(nod_nou->prioritate<head->prioritate){
        nod_nou->next=head;
        return nod_nou;
    }
    while(nod_curent->next!=NULL){
        if(nod_nou->prioritate<nod_curent->next->prioritate){
            nod_nou->next=nod_curent->next;
            nod_curent->next=nod_nou;
            return head;
        }
        nod_curent=nod_curent->next;
    }
    nod_nou->next=NULL;
    nod_curent->next=nod_nou;
    return head;
}

pacient *afisare(pacient *head){
    printf("%s %s %d %c\n", head->nume,head->prenume,head->varsta,head->sex);
    head=head->next;
    return head;
}

int main(){
    pacient *p=NULL;
    char semn;
    
    scanf("%c", &semn);
    getchar();
    
    while(semn!='*'){
        if(semn=='+')
            p=creare(p);
        else if(semn=='-')
            p=afisare(p);
        scanf("%c", &semn);
        getchar();
    }
    
    return 0;
}
