#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct masina{
    char nr[10];
    int banda;
    int plecare;
    struct masina * next;
} masini;

masini *creare(char nr_t[10], int banda_t, int plecare_t){
    masini *nod_nou=malloc(sizeof(masini));
    strcpy(nod_nou->nr, nr_t);
    nod_nou->banda=banda_t;
    nod_nou->plecare=plecare_t;
    nod_nou->next=NULL;
    return nod_nou;
}

masini *adaugare(masini *head, char nr_t[10], int banda_t, int plecare_t){
    masini *nod=head;
    if(head==NULL)
        return creare(nr_t,banda_t,plecare_t);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare(nr_t,banda_t,plecare_t);
    return head;
}

void afisare(masini *head){
    masini *nod=head;
    while(nod->next!=NULL){
        if(nod->banda==1)
            printf("%s %d\n", nod->nr, nod->plecare);
        nod=nod->next;
    }
    nod=head;
    while(nod!=NULL){
        if(nod->banda==2)
            printf("%s %d\n", nod->nr, nod->plecare);
        nod=nod->next;
    }
}

void test2(masini *head, int distanta, int timp, int viteza1, int viteza2){
    masini *nod=head;
    while(nod!=NULL){
        if(nod->banda==1)
            if((timp-nod->plecare)*viteza1>distanta)
                printf("%s %d\n", nod->nr, nod->plecare);
        nod=nod->next;
    }
    nod=head;
    while(nod!=NULL){
        if(nod->banda==2)
            if((timp-nod->plecare)*viteza2>distanta)
                printf("%s %d\n", nod->nr, nod->plecare);
        nod=nod->next;
    }
}

int timp_necesar(masini *nod, int distanta, int viteza1, int viteza2){
    if(nod->banda==1)
        return distanta/viteza1+nod->plecare;
    if(nod->banda==2)
        return distanta/viteza2+nod->plecare;
}

masini *sortare(masini *head, int distanta, int viteza1, int viteza2, int n){
    int b=0;
    masini *nod=head, *aux;
    masini **v=(masini **)malloc(n*sizeof(masini *));
    for(int i=0;i<n;i++){
        v[i]=nod;
        nod=nod->next;
    }
    while(b==0){
        b=1;
        for(int i=0;i<n-1;i++)
            if(timp_necesar(v[i],distanta,viteza1,viteza2)>
            timp_necesar(v[i+1],distanta,viteza1,viteza2)){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                b=0;
            }
    }
    for(int i=0;i<n;i++)
        printf("%s %d\n", v[i]->nr, v[i]->plecare);
}

int timp_final(masini *nod, int dist1, int dist2, int viteza1, int viteza2, int viteza3){
    return timp_necesar(nod,dist1,viteza1,viteza2)+(dist2-dist1)/viteza3;
}

masini *sortare2(masini *head, int dist1, int dist2, int viteza1, int viteza2, int viteza3, int timp, int n){
    int b=0;
    masini *nod=head, *aux;
    masini **v=(masini **)malloc(n*sizeof(masini *));
    for(int i=0;i<n;i++){
        v[i]=nod;
        nod=nod->next;
    }
    while(b==0){
        b=1;
        for(int i=0;i<n-1;i++)
            if(timp_final(v[i],dist1,dist2,viteza1,viteza2,viteza3)>
            timp_final(v[i+1],dist1,dist2,viteza1,viteza2,viteza3)){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                b=0;
            }
    }
    for(int i=0;i<n;i++)
        if(timp_final(v[i],dist1,dist2,viteza1,viteza2,viteza3)<timp)
            printf("%s %d\n", v[i]->nr, v[i]->plecare);
}

int main(){
    int viteza1, viteza2, n, t;
    char nr_t[10];
    int banda_t, plecare_t;
    masini *car=NULL;
    
    scanf("%d%d%d", &viteza1, &viteza2, &n);
    for(int i=0; i<n; i++){
        scanf("%s%d%d", nr_t, &banda_t, &plecare_t);
        car=adaugare(car,nr_t,banda_t,plecare_t);
    }
    scanf("%d", &t);
    
    if(t==1)
        afisare(car);
    else if(t==2){
        int distanta, timp;
        scanf("%d%d", &distanta, &timp);
        test2(car,distanta,timp,viteza1,viteza2);
    }
    else if(t==3){
        int distanta;
        scanf("%d", &distanta);
        sortare(car,distanta,viteza1,viteza2,n);
    }
    else if(t==4){
        int dist1, dist2, timp, viteza3;
        scanf("%d%d%d%d", &dist1, &dist2, &timp, &viteza3);
        sortare2(car,dist1,dist2,viteza1,viteza2,viteza3,timp,n);
    }
    
    return 0;
}
