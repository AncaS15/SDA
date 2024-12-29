#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dictionar{
    char cuvant[20];
    struct dictionar *next;
} text;

text *creare(char c[20]){
    text *nod=malloc(sizeof(text));
    strcpy(nod->cuvant,c);
    nod->next=NULL;
    return nod;
}

text *adaugare(text *head, char c[20]){
    text *nod=head;
    if(head==NULL)
        return creare(c);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare(c);
    return head;
}

int hash_index(char c[20]){
    int s=0;
    for(int i=0;i<strlen(c);i++)
        s+=(int)c[i];
    return s;
}

void afisare(text *head, int m){
    text *nod=head;
    while(nod!=NULL){
        printf("%s %d\n", nod->cuvant,hash_index(nod->cuvant)%m);
        nod=nod->next;
    }
}

int litere(char c1[20], char c2[20]){
    int v_c1[26]={0}, v_c2[26]={0};
    for(int i=0;i<strlen(c1);i++)
        v_c1[c1[i]-'a']++;
    for(int i=0;i<strlen(c2);i++)
        v_c2[c2[i]-'a']++;
    for(int i=0;i<26;i++)
        if(v_c1[i]!=v_c2[i])
            return 0;
    return 1;
}

void anagrame(text *head, char c2[20], int m){
    text *nod=head;
    while(nod!=NULL){
        if(hash_index(nod->cuvant)%m==hash_index(c2)%m && litere(nod->cuvant,c2)){
            printf("%s\n", nod->cuvant);
        }
        nod=nod->next;
    }
}

int main(){
    int m,n,t;
    char cuvant[20];
    text **v;
    
    scanf("%d%d", &m,&n);
    v=malloc(m*sizeof(text));
    for(int i=0;i<m;i++)
        v[i]=NULL;
        
    for(int i=0;i<n;i++){
        scanf("%s", cuvant);
        v[hash_index(cuvant)%m]=adaugare(v[hash_index(cuvant)%m],cuvant);
    }
    scanf("%d", &t);
    
    if(t==1){
        for(int i=0;i<m;i++)
            afisare(v[i],m);
    }
    else if(t==2){
        char c2[20];
        scanf("%s", c2);
        for(int i=0;i<m;i++)
            anagrame(v[i],c2,m);
    }
    else if(t==3){
        
    }
    
    return 0;
}
