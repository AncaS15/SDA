#include <stdio.h>
#include <stdlib.h>

typedef struct text{
    char cuvant[30];
    struct text *next;
    struct text *prev;
} text_t;

text_t *creare(){
    text_t *nod_nou=malloc(sizeof(text_t));
    scanf("%s", nod_nou->cuvant);
    getchar();
    nod_nou->next=NULL;
    nod_nou->prev=NULL;
    return nod_nou;
}

text_t *adaugare_sfarsit(text_t *head){
    text_t *nod_curent=head;
    text_t *nod_nou=creare();
    if(head==NULL)
        return nod_nou;
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=nod_nou;
    nod_nou->prev=nod_curent;
    return head;
}

text_t *adaugare_inceput(text_t *head){
    text_t *nod_nou=creare();
    if(head==NULL)
        return nod_nou;
    nod_nou->next=head;
    head->prev=nod_nou;
    return nod_nou;
}

text_t *adaugare_intermediar(text_t *head, int poz){
    text_t *nod=head;
    text_t *nod_nou=creare();
    int k=0;
    if(head==NULL)
        return nod_nou;
    while((k+1)!=poz && nod->next!=NULL){
        nod=nod->next;
        k++;
    }
    nod->next=nod_nou;
    nod_nou->prev=nod;
    return head;
}

text_t *stergere_inceput(text_t *head){
    text_t *nod=head;
    if(head==NULL)
        return NULL;
    head=head->next;
    free(nod);
    return head;
}

text_t *stergere_sfarsit(text_t *head){
    text_t *nod=head, *nod_sters=NULL;
    if(head==NULL)
        return NULL;
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    while(nod->next->next!=NULL)
        nod=nod->next;
    nod_sters=nod->next;
    free(nod_sters);
    nod->next=NULL;
    return head;
}

text_t *stergere_intermediar(text_t *head, int poz){
    text_t *nod=head, *nod_sters=NULL;
    int k=0;
    if(head==NULL)
        return NULL;
    while((k+1)!=poz && nod->next!=NULL){
        nod=nod->next;
        k++;
    }
    nod_sters=nod->next;
    free(nod_sters);
    nod->next=nod->next->next;
    return head;
}

void afisare(text_t *head){
    text_t *nod=head;
    while(nod!=NULL){
        printf("%s ", nod->cuvant);
        nod=nod->next;
    }
}

void afisare_invers(text_t *head){
    text_t *nod=head;
    while(nod->next!=NULL)
        nod=nod->next;
    while(nod){
        printf("%s ", nod->cuvant);
        nod=nod->prev;
    }
}

void stergere(text_t *head){
    while(head!=NULL){
        text_t *nod=head;
        head=head->next;
        free(nod);
    }
}

int main(){
    int c;
    text_t *t=NULL;
    
    printf("MENIU:\n");
    printf("1. Afișarea cuvintelor din listă\n");
    printf("2. Afișarea cuvintelor din listă în ordine inversă\n");
    printf("3. Adăugarea unui cuvânt la începutul listei\n");
    printf("4. Adăugarea unui cuvânt la finalul listei\n");
    printf("5. Adăugarea unui cuvânt în listă, pe o poziție specificată de utilizator\n");
    printf("6. Ștergerea primului cuvânt din listă\n");
    printf("7. Ștergerea ultimului cuvânt din listă\n");
    printf("8. Ștergerea unui cuvânt din listă, aflat pe o poziție specificată de utilizator\n");
    printf("9. Ștergerea listei\n");
    printf("10. Ieșire din program\n");
    
    scanf("%d", &c);
    while(c!=10){
        if(c==1){
            afisare(t);
        }
        else if(c==2){
            afisare_invers(t);
        }
        else if(c==3){
            t=adaugare_inceput(t);
        }
        else if(c==4){
            t=adaugare_sfarsit(t);
        }
        else if(c==5){
            int poz;
            scanf("%d", &poz);
            t=adaugare_intermediar(t,poz);
        }
        else if(c==6){
            t=stergere_inceput(t);
        }
        else if(c==7){
            t=stergere_sfarsit(t);
        }
        else if(c==8){
            int poz;
            scanf("%d", &poz);
            t=stergere_intermediar(t,poz);
        }
        else if(c==9){
            stergere(t);
        }
        scanf("%d", &c);
    }
    
    return 0;
}
