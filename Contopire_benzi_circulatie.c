#include <stdio.h>
#include <stdlib.h>

typedef struct banda_unu{
    char nr[10];
    struct banda_unu *next;
} banda_1;

typedef struct banda_doi{
    char nr[10];
    struct banda_doi *next;
} banda_2;

banda_1 *creare_1(){
    banda_1 *nod_nou=malloc(sizeof(banda_1));
    scanf("%s", nod_nou->nr);
    nod_nou->next=NULL;
    return nod_nou;
}

banda_2 *creare_2(){
    banda_2 *nod_nou=malloc(sizeof(banda_2));
    scanf("%s", nod_nou->nr);
    nod_nou->next=NULL;
    return nod_nou;
}

banda_1 *adaugare_1(banda_1 *head){
    banda_1 *nod_curent=head;
    if(head==NULL)
        return creare_1();
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare_1();
    return head;
}

banda_2 *adaugare_2(banda_2 *head){
    banda_2 *nod_curent=head;
    if(head==NULL)
        return creare_2();
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare_2();
    return head;
}

banda_1 *eliminare_1(banda_1 *head){
    banda_1 *nod_curent=head;
    if(head==NULL)
        return NULL;
    head=head->next;
    free(nod_curent);
    return head;
}

banda_2 *eliminare_2(banda_2 *head){
    banda_2 *nod_curent=head;
    if(head==NULL)
        return NULL;
    head=head->next;
    free(nod_curent);
    return head;
}

int main(){
    int m,n;
    banda_1 *b_1=NULL;
    banda_2 *b_2=NULL;
    
    scanf("%d%d", &m,&n);
    for(int i=0;i<m;i++)
        b_1=adaugare_1(b_1);
    for(int i=0;i<n;i++)
        b_2=adaugare_2(b_2);
    
    while(b_1!=NULL && b_2!=NULL){
        printf("%s\n", b_2->nr);
        printf("%s\n", b_1->nr);
        b_1=eliminare_1(b_1);
        b_2=eliminare_2(b_2);
    }
    while(b_2!=NULL){
        printf("%s\n", b_2->nr);
        b_2=eliminare_2(b_2);
    }
    while(b_1!=NULL){
        printf("%s\n", b_1->nr);
        b_1=eliminare_1(b_1);
    }
    
    return 0;
}
