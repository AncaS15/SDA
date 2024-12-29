#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct articole{
    char nume[20],culoare[20];
    int marime;
    struct articole *next;
} art_t;

art_t *creare(char nume[20], int marime, char culoare[20]){
    art_t *nod=malloc(sizeof(art_t));
    strcpy(nod->nume,nume);
    nod->marime=marime;
    strcpy(nod->culoare,culoare);
    nod->next=NULL;
    return nod;
}

art_t *adaugare(art_t *head, char nume[20], int marime, char culoare[20]){
    art_t *nod=head;
    if(head==NULL)
        return creare(nume,marime,culoare);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare(nume,marime,culoare);
    return head;
}

int hash_index(char nume[20], int marime, char culoare[20]){
    int s=0;
    for(int i=0;i<strlen(nume);i++)
        s+=(int)nume[i];
    for(int i=0;i<strlen(culoare);i++)
        s+=(int)culoare[i];
    return s+marime;
}

void afisare(art_t *head){
    art_t *nod=head;
    while(nod!=NULL){
        printf("%s %d %s\n", nod->nume,nod->marime,nod->culoare);
        nod=nod->next;
    }
}

void afisare_hash(art_t *head, int m){
    art_t *nod=head;
    while(nod!=NULL){
        printf("%s %d %s ", nod->nume,nod->marime,nod->culoare);
        printf("%d\n", hash_index(nod->nume,nod->marime,nod->culoare)%m);
        nod=nod->next;
    }
}

void test_3(art_t **v, art_t **u, int m){
    int i,j,k;
    art_t *nod_v, *nod_u;
    for(i=m;;i++){
        k=0;
        for(j=0;j<m;j++){
            nod_v=v[j]; nod_u=u[j];
            while(nod_v!=NULL && nod_u!=NULL){
                if(strcmp(nod_v->nume,nod_u->nume) || nod_v->marime!=nod_u->marime || strcmp(nod_v->culoare,nod_u->culoare)){
                    k=1; break;
                }
                nod_v=nod_v->next; nod_u=nod_u->next;
            }
            if(k)
                break;
        }
        if(!k)
            break;
    }
    printf("%d", i);
}

int main(){
    int m,n,t,marime,k;
    char nume[20],culoare[20];
    art_t *v[20]={NULL};
    art_t *u[20]={NULL};
    art_t *art=NULL;
    
    scanf("%d%d", &m,&n);
    for(int i=0;i<n;i++){
        scanf("%s", nume);
        scanf("%d", &marime);
        scanf("%s", culoare);
        art=adaugare(art,nume,marime,culoare);
        v[hash_index(nume,marime,culoare)%m]=adaugare(v[hash_index(nume,marime,culoare)%m],nume,marime,culoare);
        k=hash_index(nume,marime,culoare)%m;
        while(u[k]!=NULL)
            k++;
        u[k]=adaugare(u[k],nume,marime,culoare);
    }
    scanf("%d", &t);
    
    if(t==1)
        afisare(art);
    else if(t==2)
        for(int i=0;i<m;i++)
            afisare_hash(v[i],m);
    else if(t==3)
        //test_3(v,u,m);
    
    return 0;
}
