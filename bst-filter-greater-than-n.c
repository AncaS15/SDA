#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arbore{
    int x;
    struct arbore *next_s;
    struct arbore *next_d;
} arb;

arb *creare(int x){
    arb *nod=malloc(sizeof(arb));
    nod->x=x;
    nod->next_s=NULL;
    nod->next_d=NULL;
    return nod;
}

arb *adaugare(arb *head, int x){
    if(head==NULL)
        return creare(x);
    if(head->x<x)
        head->next_d=adaugare(head->next_d,x);
    if(head->x>x)
        head->next_s=adaugare(head->next_s,x);
    return head;
}

void afisare(arb *head, int n){
    if(head!=NULL){
        afisare(head->next_d,n);
        if(head->x>=n)
            printf("%d\n", head->x);
        afisare(head->next_s,n);
    }
}

int main(){
    char c[5];
    int x,n;
    arb *arb_t=NULL;
    
    scanf("%s", c);
    while(strcmp(c,"stop")){
        x=atoi(c);
        arb_t=adaugare(arb_t,x);
        scanf("%s", c);
    }
    scanf("%d", &n);
    afisare(arb_t,n);
    
    return 0;
}
