#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    int valoare;
    char comportament[20];
    int efect;
    struct celula *next;
} celule;

celule *creare(int valoare, char comportament[20], int efect){
    celule *nod_nou=malloc(sizeof(celule));
    nod_nou->valoare=valoare;
    strcpy(nod_nou->comportament,comportament);
    nod_nou->efect=efect;
    nod_nou->next=NULL;
    return nod_nou;
}

celule *adaugare(celule *head, int valoare, char comportament[20], int efect){
    celule *nod=head;
    if(head==NULL)
        return creare(valoare,comportament,efect);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare(valoare,comportament,efect);
    return head;
}

void afisare(celule *head){
    celule *nod=head;
    while(nod!=NULL){
        if(strcmp(nod->comportament,"dubleaza")){
            printf("%d ", nod->valoare);
            printf("%s ", nod->comportament);
            printf("%d\n", nod->efect);
        }
        else{
            printf("%d ", nod->valoare);
            printf("%s\n", nod->comportament);
        }
        nod=nod->next;
    }
}

void test_2(celule *head, int celula, int zar){
    celule *nod=head;
    while(nod!=NULL){
        if(celula+zar==nod->valoare){
            if(strcmp(nod->comportament,"avanseaza")==0){
                printf("%d", celula+zar+nod->efect);
            }
            else if(strcmp(nod->comportament,"intoarce")==0){
                printf("%d", celula+zar-nod->efect);
            }
            else if(strcmp(nod->comportament,"dubleaza")==0){
                printf("%d", (celula+zar)*2);
            }
        }
        nod=nod->next;
    }
}



int main(){
    int n,x,valoare,efect,t;
    char comportament[20];
    celule *list=NULL;
    
    scanf("%d%d", &n,&x);
    for(int i=0;i<x;i++){
        scanf("%d", &valoare);
        scanf("%s", comportament);
        getchar();
        if(strcmp(comportament,"dubleaza"))
            scanf("%d", &efect);
        else
            efect=0;
        list=adaugare(list,valoare,comportament,efect);
    }
    scanf("%d", &t);
    
    if(t==1){
        afisare(list);
    }
    else if(t==2){
        int celula,zar;
        scanf("%d%d", &celula, &zar);
        test_2(list,celula,zar);
    }
    
    return 0;
}
