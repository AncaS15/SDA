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

void afisare_par(codru *head){
    if(head==NULL)
        return;
    afisare_par(head->nod_s);
    if(head->x%2==0)
        printf("%d ", head->x);
    afisare_par(head->nod_d);
    return;
}

void afisare_impar(codru *head){
    if(head==NULL)
        return;
    afisare_impar(head->nod_d);
    if(head->x%2!=0)
        printf("%d ", head->x);
    afisare_impar(head->nod_s);
    return;
}

int main(){
    int a;
    codru *padure=NULL;
    while(scanf("%d", &a)!=EOF){
        
        padure=adaugare(padure,a);
    }
    
    afisare_par(padure);
    afisare_impar(padure);
    
    return 0;
}
