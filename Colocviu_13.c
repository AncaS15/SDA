#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cuvant{
    char c[20];
    struct cuvant *nod_s;
    struct cuvant *nod_d;
} cuv_t;

typedef struct lista{
    char c[20];
    struct lista *next;
} list_t;

cuv_t *creare(char cuv[20]){
    cuv_t *nod_nou=malloc(sizeof(cuv_t));
    strcpy(nod_nou->c,cuv);
    nod_nou->nod_s=NULL;
    nod_nou->nod_d=NULL;
    return nod_nou;
}

cuv_t *adaugare_nod(cuv_t *head, char cuv[20]){
    if(head==NULL)
        return creare(cuv);
    if(strcmp(head->c,cuv)<0)
        head->nod_d=adaugare_nod(head->nod_d,cuv);
    if(strcmp(head->c,cuv)>0)
        head->nod_s=adaugare_nod(head->nod_s,cuv);
    return head;
}

cuv_t *adaugare(cuv_t *head, char cuv[20]){
    if(head==NULL)
        return creare(cuv);
    adaugare_nod(head,cuv);
    return head;
}

list_t *creare_list(char cuv[20]){
    list_t *nod_nou=malloc(sizeof(list_t));
    strcpy(nod_nou->c,cuv);
    nod_nou->next=NULL;
    return nod_nou;
}

list_t *adaugare_list(list_t *head, char cuv[20]){
    list_t *nod=head;
    if(head==NULL)
        return creare_list(cuv);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare_list(cuv);
    return head;
}

void afisare_preordine(cuv_t *head){
    if(head==NULL)
        return;
    printf("%s\n", head->c);
    afisare_preordine(head->nod_s);
    afisare_preordine(head->nod_d);
    return;
}

void afisare_inordine(cuv_t *head){
    if(head==NULL)
        return;
    afisare_inordine(head->nod_s);
    printf("%s\n", head->c);
    afisare_inordine(head->nod_d);
    return;
}

int index_hash(cuv_t *head, char cuvant[20]){
    int k=0;
    cuv_t *nod=head;
    while(nod!=NULL){
        k++;
        if(strcmp(nod->c,cuvant)>0)
            nod=nod->nod_s;
        else if(strcmp(nod->c,cuvant)<0)
            nod=nod->nod_d;
        else
            break;
    }
    return k;
}

int index_lista(list_t *head, char cuvant[20]){
    int k=0;
    list_t *nod=head;
    while(nod!=NULL){
        k++;
        if(strcmp(nod->c,cuvant)==0)
            break;
        nod=nod->next;
    }
    return k;
}

int main(){
    int t;
    char c[20];
    cuv_t *v[26]={NULL};
    list_t *list=NULL;
    
    scanf("%s", c);
    while(strcmp(c,"stop")){
        v[c[0]-'a']=adaugare(v[c[0]-'a'],c);
        list=adaugare_list(list,c);
        scanf("%s", c);
    }
    scanf("%d", &t);
    getchar();
    
    if(t==1){
        char a;
        scanf("%c", &a);
        afisare_preordine(v[a-'a']);
    }
    else if(t==2){
        for(int i=0;i<26;i++)
            afisare_inordine(v[i]);
    }
    else if(t==3){
        char cuvant[20];
        scanf("%s", cuvant);
        printf("%d\n", index_hash(v[cuvant[0]-'a'],cuvant));
        printf("%d", index_lista(list,cuvant));
    }
    
    return 0;
}
