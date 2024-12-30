#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arbore{
    char nume[30];
    int distanta;
    struct arbore *next_s;
    struct arbore *next_d;
} oras;

oras *creare(char nume[30], int distanta){
    oras *nod=malloc(sizeof(oras));
    strcpy(nod->nume,nume);
    nod->distanta=distanta;
    nod->next_s=NULL;
    nod->next_d=NULL;
    return nod;
}

oras *adaugare(oras *head, char nume[30], int distanta){
    if(head==NULL)
        return creare(nume,distanta);
    if(strcmp(head->nume,nume)>0)
        head->next_s=adaugare(head->next_s,nume,distanta);
    if(strcmp(head->nume,nume)<0)
        head->next_d=adaugare(head->next_d,nume,distanta);
    return head;
}

oras *cautare_nod(oras *head, char nume[30]){
    if(head!=NULL){
        if(strcmp(head->nume,nume)==0)
            return head;
        else if(strcmp(head->nume,nume)>0)
            return cautare_nod(head->next_s,nume);
        else if(strcmp(head->nume,nume)<0)
            return cautare_nod(head->next_d,nume);
    }
    else
        return NULL;
}

void noduri_descendente(oras *head, int *k){
    if(head!=NULL){
        (*k)++;
        noduri_descendente(head->next_s,k);
        noduri_descendente(head->next_d,k);
    }
}

void noduri_descendente_2(oras *head, oras *nume_2, int *k){
    if(head==NULL || head==nume_2->next_s || head==nume_2->next_d)
        return;
    (*k)+=head->distanta;
    if(strcmp(head->nume,nume_2->nume)>0)
        noduri_descendente_2(head->next_s,nume_2,k);
    else if(strcmp(head->nume,nume_2->nume)<0)
        noduri_descendente_2(head->next_d,nume_2,k);
}

int main(){
    int n,distanta,t;
    char nume[30];
    oras *oras_t=NULL;
    oras *nume_2=NULL, *nume_1=NULL;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s%d", nume, &distanta);
        oras_t=adaugare(oras_t,nume,distanta);
    }
    scanf("%d", &t);
    
    if(t==1){
        char nume2[30];
        int k=0;
        scanf("%s", nume2);
        nume_2=cautare_nod(oras_t,nume2);
        noduri_descendente(nume_2,&k);
        printf("%d", k-1);
    }
    else if(t==2){
        char nume1[30],nume2[30];
        int k=0;
        scanf("%s%s", nume1,nume2);
        nume_1=cautare_nod(oras_t,nume1);
        nume_2=cautare_nod(oras_t,nume2);
        noduri_descendente_2(nume_1,nume_2,&k);
        printf("%d", k-nume_1->distanta);
    }
    
    return 0;
}
