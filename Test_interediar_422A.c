#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct echipe{
    char nume[31];
    int nr_mem,nr_ani[5];
    int note[3],indicii;
    struct echipe *next;
} echipa;

echipa *creare(char nume[31], int nr_mem, int nr_ani[5], int note[3], int indicii){
    echipa *nod_nou=malloc(sizeof(echipa));
    strcpy(nod_nou->nume, nume);
    nod_nou->nr_mem=nr_mem;
    for(int i=0;i<nr_mem;i++)
        nod_nou->nr_ani[i]=nr_ani[i];
    for(int i=0;i<3;i++)
        nod_nou->note[i]=note[i];
    nod_nou->indicii=indicii;
    nod_nou->next=NULL;
    return nod_nou;
}

echipa *adaugare(echipa *head, char nume[31], int nr_mem, int nr_ani[5], int note[3], int indicii){
    echipa *nod_curent=head;
    if(head==NULL)
        return creare(nume,nr_mem,nr_ani,note,indicii);
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare(nume,nr_mem,nr_ani,note,indicii);
    return head;
}

void afisare(echipa *head){
    echipa *nod_curent=head;
    while(nod_curent!=NULL){
        printf("%s\n", nod_curent->nume);
        printf("%d\n", nod_curent->nr_mem);
        for(int i=0;i<nod_curent->nr_mem;i++)
            printf("%d ", nod_curent->nr_ani[i]);
        printf("\n");
        nod_curent=nod_curent->next;
    }
}

// float punctaj(echipa *head, int note[3], int indicii){
//     echipa *nod_curent=head;
//     float p,s=0;
//     for(int i=0;i<3;i++)
//         s+=nod_curent->note[i];
//     p=(float)(s/3-0.25*nod_curent->indicii);
//     return p;
// }

// float scor(echipa *head, float pct, int nr_ani[5]){
//     echipa *nod_curent=head;
//     float s=0.0;
//     for(int i=0;i<nod_curent->nr_mem;i++)
//         s+=nod_curent->nr_ani[i];
//     return pct/s;
// }

void afis_pct(echipa *head){
    echipa *nod_curent=head;
    float pct,s=0.0,sum=0.0;
    while(nod_curent!=NULL){
        for(int i=0;i<3;i++)
            s+=nod_curent->note[i];
        pct=(float)s/3-0.25*nod_curent->indicii;
        for(int i=0;i<nod_curent->nr_mem;i++)
            sum+=nod_curent->nr_ani[i];
        printf("%s %d\n", nod_curent->nume, nod_curent->nr_mem);
        //pct=punctaj(nod_curent,note,indicii);
        printf("%.2f\n", pct);
        printf("%.2f\n", pct/sum);
        nod_curent=nod_curent->next;
    }
}

int main(){
    int t,nr_echipe,nr_mem,nr_ani[5];
    int note[3],indicii;
    char nume[31];
    echipa *ech=NULL;
    
    scanf("%d", &nr_echipe);
    for(int i=0;i<nr_echipe;i++){
        scanf("%s", nume);
        scanf("%d", &nr_mem);
        for(int j=0;j<nr_mem;j++)
            scanf("%d", &nr_ani[j]);
        ech=adaugare(ech,nume,nr_mem,nr_ani,note,indicii);
    }
    scanf("%d", &t);
    
    if(t==1){
        afisare(ech);
    }
    else if(t==2){
        for(int i=0;i<nr_echipe;i++){
            for(int j=0;j<3;j++)
                scanf("%d", &note[j]);
            scanf("%d", &indicii);
            ech=adaugare(ech,nume,nr_mem,nr_ani,note,indicii);
        }
        afis_pct(ech);
    }
    
    return 0;
}
