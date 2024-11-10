#include <stdio.h>
#include <stdlib.h>

typedef struct numar_1{
    int cifra;
    struct numar_1 *next;
    struct numar_1 *prev;
} nr_1;

nr_1 *creare_1(int cifra){
    nr_1 *nod_nou=malloc(sizeof(nr_1));
    nod_nou->cifra=cifra;
    nod_nou->next=NULL;
    return nod_nou;
}

nr_1 *adaugare_1(nr_1 *head, int cifra){
    nr_1 *nod_curent=head;
    if(head==NULL)
        return creare_1(cifra);
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare_1(cifra);
    nod_curent->next->prev=nod_curent;
    return head;
}

void afisare(nr_1 *head){
    nr_1 *nod_curent=head;
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    while(nod_curent->prev!=NULL){
        printf("%d", nod_curent->cifra);
        nod_curent=nod_curent->prev;
    }
    printf("%d\n", nod_curent->cifra);
}

nr_1 *esti_varza(nr_1 *n1, nr_1 *n2, nr_1 *n3){
    while(n1!=NULL && n2!=NULL){
        n3=adaugare_1(n3, n1->cifra+n2->cifra);
        n1=n1->next;
        n2=n2->next;
    }
    while(n1!=NULL){
        n3=adaugare_1(n3, n1->cifra);
        n1=n1->next;
    }
    while(n2!=NULL){
        n3=adaugare_1(n3, n2->cifra);
        n2=n2->next;
    }
    return n3;
}

nr_1 *suma(nr_1 *head){
    nr_1 *n3=head;
    while(n3!=NULL){
        if(n3->cifra>9){
            n3->cifra-=10;
            n3->next->cifra+=1;
        }
        n3=n3->next;
    }
    // if(n3->cifra>9){
    //     n3->cifra-=10;
    //     head=adaugare_1(head,1);
    // }
    return head;
}

int main(){
    int n1,n2,t;
    nr_1 *nr1=NULL;
    nr_1 *nr2=NULL;
    
    scanf("%d%d%d", &n1,&n2,&t);
    while(n1!=0){
        nr1=adaugare_1(nr1,n1%10);
        n1=n1/10;
    }
    while(n2!=0){
        nr2=adaugare_1(nr2,n2%10);
        n2=n2/10;
    }
    
    if(t==1){
        afisare(nr1);
        afisare(nr2);
    }
    else if(t==2){
        nr_1 *nr3=NULL;
        nr3=esti_varza(nr1,nr2,nr3);
        nr3=suma(nr3);
        afisare(nr3);
    }
    
    return 0;
}
