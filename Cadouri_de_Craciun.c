#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sac_cadouri{
    char cadou[31];
    struct sac_cadouri *next;
} cadouri;

cadouri *creare(char cadou[31]){
    cadouri *nod_nou=malloc(sizeof(cadouri));
    strcpy(nod_nou->cadou,cadou);
    nod_nou->next=NULL;
    return nod_nou;
}

cadouri *adaugare(cadouri *head, char cadou[31]){
    cadouri *nod_curent=head;
    if(head==NULL)
        return creare(cadou);
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare(cadou);
    return head;
}

int main(){
    int n,om_curent=0,nr_pers=0;
    char cadou[31],nume[10][31],cadouri_primite[10][31]={""};
    cadouri *cadouri_t=NULL;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", cadou);
        cadouri_t=adaugare(cadouri_t,cadou);
    }
    // while(scanf("%s", nume[nr_pers])!='\0'){
    //     nr_pers++;
    //     if(getchar()=='\n')
    //         break;
    // }
    do{
        scanf("%s", nume[nr_pers]);
        nr_pers++;
    }while(getchar()!='\n');
    
    cadouri *nod_curent=cadouri_t;
    
    while(nod_curent!=NULL){
        strcat(cadouri_primite[om_curent], nod_curent->cadou);
        strcat(cadouri_primite[om_curent], " ");
        nod_curent=nod_curent->next;
        om_curent=(om_curent+1)%nr_pers;
    }
    
    for(int i=0;i<nr_pers;i++){
        printf("%s: %s\n", nume[i], cadouri_primite[i]);
    }
    
    return 0;
}
