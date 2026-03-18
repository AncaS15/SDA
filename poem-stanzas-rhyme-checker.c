#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strofa{
    char vers[4][100];
    struct strofa *next;
} strofa_t;

strofa_t *creare(char vers[4][100]){
    strofa_t *nod_nou=malloc(sizeof(strofa_t));
    for(int i=0;i<4;i++)
        strcpy(nod_nou->vers[i],vers[i]);
    nod_nou->next=NULL;
    return nod_nou;
}

strofa_t *adaugare(strofa_t *head, char vers[4][100]){
    strofa_t *nod_curent=head;
    if(head==NULL)
        return creare(vers);
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare(vers);
    return head;
}

void afisare(strofa_t *head){
    strofa_t *nod_curent=head;
    while(nod_curent!=NULL){
        for(int i=0;i<4;i++)
            printf("%s\n", nod_curent->vers[i]);
        printf("\n");
        nod_curent=nod_curent->next;
    }
}

void rima(strofa_t *head){
    strofa_t *nod_curent=head;
    char *v1=&nod_curent->vers[0][strlen(nod_curent->vers[0])-2];
    char *v2=&nod_curent->vers[1][strlen(nod_curent->vers[1])-2];
    char *v3=&nod_curent->vers[2][strlen(nod_curent->vers[2])-2];
    char *v4=&nod_curent->vers[3][strlen(nod_curent->vers[3])-2];
    if(strcmp(v1,v4)==0 && strcmp(v2,v3)==0)
        printf("%s-%s-%s-%s\n", v1,v2,v3,v4);
    else
        printf("nu\n");
}

int main(){
    int nr_strofe,t;
    char vers[4][100];
    strofa_t *strofe=NULL;
    
    scanf("%d", &nr_strofe);
    getchar();
    for(int i=0;i<nr_strofe;i++){
        for(int j=0;j<4;j++){
            scanf("%[^\n]", vers[j]);
            getchar();
        }
        strofe=adaugare(strofe,vers);
    }
    scanf("%d", &t);
    
    if(t==1){
        afisare(strofe);
    }
    else if(t==2){
        rima(strofe);
    }
    
    return 0;
}
