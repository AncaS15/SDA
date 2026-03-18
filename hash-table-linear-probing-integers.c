#include <stdio.h>
#include <stdlib.h>

typedef struct nr{
    int x;
    struct nr *next;
} nr_t;

nr_t *creare(int x){
    nr_t *nod_nou=malloc(sizeof(nr_t));
    nod_nou->x=x;
    nod_nou->next=NULL;
    return nod_nou;
}

nr_t *adaugare(nr_t *head, int x){
    nr_t *nod=head;
    if(head==NULL)
        return creare(x);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare(x);
    return head;
}

void afisare(nr_t *head){
    nr_t *nod=head;
    while(nod!=NULL){
        printf("%d", nod->x);
        nod=nod->next;
    }
    printf("\n");
}

int main(){
    int n,m,a,k;
    nr_t **v;
    scanf("%d%d", &m,&n);
    v=malloc(m*sizeof(nr_t*));
    
    for(int i=0;i<m;i++)
        v[i]=NULL;
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        if(a<0){
            k=m-((-1)*a)%m;
            while(v[k]!=NULL)
                k++;
            v[k]=adaugare(v[k],a);
        }
        else{
            k=a%m;
            while(v[k]!=NULL)
                k++;
            v[k]=adaugare(v[k],a);
        }
    }
    
    for(int i=0;i<m;i++){
        printf("%d: ", i);
        afisare(v[i]);
    }
    
    return 0;
}
