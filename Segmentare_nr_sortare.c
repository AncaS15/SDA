#include <stdio.h>
#include <stdlib.h>

typedef struct copac{
    int x;
    struct copac *nod_s;
    struct copac *nod_d;
} codru;

codru *creare(int x){
    codru *nod_nou=malloc(sizeof(codru));
    nod_nou->x=x;
    nod_nou->nod_s=NULL;
    nod_nou->nod_d=NULL;
    return nod_nou;
}

codru *adaugare_nod(codru *head, int x){
    if(head==NULL)
        return creare(x);
    if(head->x<x)
        head->nod_d=adaugare_nod(head->nod_d,x);
    else
        head->nod_s=adaugare_nod(head->nod_s,x);
    return head;
}

codru *adaugare(codru *head, int x){
    if(head==NULL)
        return creare(x);
    adaugare_nod(head,x);
    return head;
}

void afisare(codru *head){
    if(head==NULL)
        return;
    afisare(head->nod_s);
    printf("%d ", head->x);
    afisare(head->nod_d);
    return;
}

int main(){
    int x;
    codru *padure=NULL;
    while(scanf("%d", &x)!=EOF){
        
        padure=adaugare(padure,x);
    }
    
    afisare(padure);
    
    return 0;
}
