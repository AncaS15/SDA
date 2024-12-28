#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct utilizator{
    char nume[30];
    int zi, luna, an;
    struct utilizator *next;
} user;

user *creare(char nume[30]){
    user *nod=malloc(sizeof(user));
    strcpy(nod->nume,nume);
    scanf("%d%d%d", &nod->an,&nod->luna,&nod->zi);
    nod->next=NULL;
    return nod;
}

user *adaugare(user *head, char nume[30]){
    user *nod=head;
    if(head==NULL)
        return creare(nume);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare(nume);
    return head;
}

int hash_index(char c[30]){
    int s=0;
    for(int i=0;i<strlen(c);i++)
        s+=(int)c[i];
    return s;
}

void afisare(user *head){
    user *nod=head;
    while(nod!=NULL){
        printf("%s ", nod->nume);
        if((nod->an>2006) || (nod->an==2006 && nod->luna>1) || (nod->an==2006 && nod->luna==1 && nod->zi>9))
            printf("Minor\n");
        else
            printf("%d %d %d\n", nod->an,nod->luna,nod->zi);
        nod=nod->next;
    }
}

void user_similar(user *head, char username[30]){
    user *nod=head;
    int k=0;
    while(nod!=NULL){
        if(hash_index(nod->nume)==hash_index(username) && strcmp(nod->nume,username)!=0){
            printf("%s ", nod->nume); k=1;
        }
        nod=nod->next;
    }
    if(k==0)
        printf("Nu exista useri similari");
    printf("\n");
}

void gestiune(user **v, int n){
    int k,i,j,a;
    for(i=n;;i++){
        for(j=0;j<i;j++){
            k=0;
            for(a=0;a<n;a++){
                user *nod=v[a];
                while(nod!=NULL){
                    if(hash_index(nod->nume)%i==j){
                        k++;
                    }
                    nod=nod->next;
                }
            }
            if(k>2)
                break;
        }
        if(j==i)
            break;
    }
    printf("%d", i);
}

int main(){
    int n,nr_user,t;
    char nume[30];
    user **v;
    
    scanf("%d%d", &n,&nr_user);
    v=malloc(n*sizeof(user*));
    for(int i=0;i<n;i++)
        v[i]=NULL;
    for(int i=0;i<nr_user;i++){
        scanf("%s", nume);
        v[hash_index(nume)%n]=adaugare(v[hash_index(nume)%n],nume);
    }
    scanf("%d", &t);
    
    if(t==1){
        for(int i=0;i<n;i++)
            afisare(v[i]);
    }
    else if(t==2){
        char username[30];
        for(int i=0;i<3;i++){
            scanf("%s", username);
            user_similar(v[hash_index(username)%n],username);
        }
    }
    else if(t==3){
        gestiune(v,n);
    }
    
    return 0;
}
