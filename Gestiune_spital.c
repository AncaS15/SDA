#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct examinari{
    char nume[20];
    struct examinari *next;
    struct examinari *prev;
} exam;

exam *creare_nod(){
    exam *nod_nou=malloc(sizeof(exam));
    scanf("%s", nod_nou->nume);
    nod_nou->next=NULL;
    return nod_nou;
}

exam *adaugare(exam *head){
    exam *nod_curent=head;
    if(head==NULL)
        return creare_nod();
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare_nod();
    nod_curent->next->prev=nod_curent;
    return head;
}

void afisare(exam *head){
    exam *nod_curent=head;
    while(nod_curent!=NULL){
        printf("%s\n", nod_curent->nume);
        nod_curent=nod_curent->next;
    }
}

void inversare(exam *head, int m, int n){
    exam *nod_1=head;
    exam *nod_2=head;
    char aux[20];
    for(int i=0;i<n/m;i++){
        nod_2=nod_1;
        for(int j=1;j<m;j++)
            nod_2=nod_2->next;
        for(int j=0;j<m/2;j++){
            strcpy(aux,nod_1->nume);
            strcpy(nod_1->nume,nod_2->nume);
            strcpy(nod_2->nume,aux);
            nod_1=nod_1->next;
            nod_2=nod_2->prev;
        }
        if(m%2==1)
            for(int j=0;j<m/2+1;j++)
                nod_1=nod_1->next;
        else
            for(int j=0;j<(m+1)/2;j++)
                nod_1=nod_1->next;
    }
    if(n%m>1)
        inversare(nod_1,n%m,n%m);
}

void afisare_7(exam *head){
    exam *nod_curent=head;
    int k=0;
    while(nod_curent!=NULL){
        k++;
        if(k%7!=0)
            printf("%s\n", nod_curent->nume);
        nod_curent=nod_curent->next;
    }
}

int main(){
    int nr_exam,t;
    exam *exam_t=NULL;
    
    scanf("%d", &nr_exam);
    
    for(int i=0;i<nr_exam;i++)
        exam_t=adaugare(exam_t);
    scanf("%d", &t);
    
    if(t==1){
        afisare(exam_t);
    }
    else if(t==2){
        inversare(exam_t,3,nr_exam);
        afisare(exam_t);
    }
    else if(t==3){
        int n;
        scanf("%d", &n);
        inversare(exam_t,n,nr_exam);
        afisare(exam_t);
    }
    else if(t==4){
        inversare(exam_t,3,nr_exam);
        afisare_7(exam_t);
    }
    
    return 0;
}
