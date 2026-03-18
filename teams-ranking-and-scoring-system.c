#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct echipa{
    char nume[30];
    int nr_mem;
    int ani[5];
    int nota[3];
    int indicii;
    struct echipa *next;
}ech;

ech *creare(char nume[30], int nr_mem, int ani[5], int nota[3], int indicii){
    ech *nod=malloc(sizeof(ech));
    strcpy(nod->nume,nume);
    nod->nr_mem=nr_mem;
    for(int i=0;i<nr_mem;i++)
        nod->ani[i]=ani[i];
    for(int i=0;i<3;i++)
        nod->nota[i]=nota[i];
    nod->indicii=indicii;
    nod->next=NULL;
    return nod;
}

ech *adaugare(ech *head, char nume[30], int nr_mem, int ani[5], int nota[3], int indicii){
    ech *nod=head;
    if(head==NULL)
        return creare(nume,nr_mem,ani,nota,indicii);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare(nume,nr_mem,ani,nota,indicii);
    return head;
}

void afisare(ech *head){
    ech *nod=head;
    while(nod!=NULL){
        printf("%s\n%d\n", nod->nume, nod->nr_mem);
        for(int i=0;i<nod->nr_mem;i++)
            printf("%d ", nod->ani[i]);
        printf("\n");
        nod=nod->next;
    }
}

float punctaj(ech *nod){
    return (nod->nota[0]+nod->nota[1]+nod->nota[2])*1.0/3-0.25*nod->indicii;
}

float scor(ech *nod){
    float s=0;
    for(int i=0;i<nod->nr_mem;i++)
        s+=nod->ani[i];
    return punctaj(nod)*1.0/s;
}

void afisare_scor(ech *head){
    ech *nod=head;
    while(nod!=NULL){
        printf("%s %d\n", nod->nume, nod->nr_mem);
        printf("%.2f\n", punctaj(nod));
        printf("%.2f\n", scor(nod));
        nod=nod->next;
    }
}

void afisare_premii(ech *head, int n){
    int b=0;
    ech *nod=head, *aux;
    ech **v=(ech **)malloc(n*sizeof(ech *));
    for(int i=0;i<n;i++){
        v[i]=nod;
        nod=nod->next;
    }
    while(b==0){
        b=1;
        for(int i=0;i<n-1;i++)
            if(punctaj(v[i])<punctaj(v[i+1])){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                b=0;
            }
    }
    for(int i=0;i<3;i++)
        printf("%s %.2f\n", v[i]->nume, punctaj(v[i]));
}

void premiu_special(ech *head, int n){
    int b=0;
    ech *nod=head, *aux;
    ech **v=(ech **)malloc(n*sizeof(ech *));
    for(int i=0;i<n;i++){
        v[i]=nod;
        nod=nod->next;
    }
    while(b==0){
        b=1;
        for(int i=0;i<n-1;i++)
            if(scor(v[i])<scor(v[i+1])){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                b=0;
            }
    }
    char nume_premiu[30];
    float scor_premiu=scor(v[0]);
    strcpy(nume_premiu,v[0]->nume);
    
    b=0;
    while(b==0){
        b=1;
        for(int i=0;i<n-1;i++)
            if(punctaj(v[i])<punctaj(v[i+1])){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                b=0;
            }
    }
    if(strcmp(nume_premiu,v[0]->nume)==0 ||
    strcmp(nume_premiu,v[1]->nume)==0 ||
    strcmp(nume_premiu,v[2]->nume)==0)
        printf("NU");
    else
        printf("%s %.2f\n", nume_premiu, scor_premiu);
}

int main(){
    int n, nr_mem, ani[5], t, nota[3], indicii;
    char nume[30];
    ech *echipa=NULL;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s%d", nume, &nr_mem);
        for(int j=0;j<nr_mem;j++)
            scanf("%d", &ani[j]);
        echipa=adaugare(echipa,nume,nr_mem,ani,nota,indicii);
    }
    scanf("%d", &t);
    
    // citire pt test 2-4
    ech *nod=echipa;
    while(nod!=NULL){
        for(int i=0;i<3;i++)
            scanf("%d", &nod->nota[i]);
        scanf("%d", &nod->indicii);
        nod=nod->next;
    }
    
    if(t==1)
        afisare(echipa);
    if(t==2)
        afisare_scor(echipa);
    if(t==3)
        afisare_premii(echipa,n);
    if(t==4)
        premiu_special(echipa,n);
        
    return 0;
}
