#include <stdio.h>
#include <stdlib.h>

typedef struct restaurant{
    char nume[30];
    int nr;
    struct restaurant *next;
} r;

r *creare(){
    r *nod_nou=malloc(sizeof(r));
    scanf("%d", &nod_nou->nr);
    scanf("%s", nod_nou->nume);
    nod_nou->next=NULL;
    return nod_nou;
}

r *adaugare(r *head){
    r *nod=head;
    if(head==NULL)
        return creare();
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare();
    return head;
}

r *creare2(int min){
    r *nod_nou=malloc(sizeof(r));
    nod_nou->nr=min;
    scanf("%s", nod_nou->nume);
    nod_nou->next=NULL;
    return nod_nou;
}

r *adaugare2(r *head, int min){
    r *nod=head;
    if(head==NULL)
        return creare2(min);
    while(nod->next!=NULL)
        nod=nod->next;
    nod->next=creare2(min);
    return head;
}

r *timp(r *head, int min){
    if(head==NULL){
        return head;
    }
    if(head->nr-min>0){
        head->nr-=min;
        return head;
    }
    else{
        min=min-head->nr;
        head->nr=0;
        
        printf("%s\n", head->nume);
        head=head->next;
    }
    return timp(head, min);
}

int main(){
    int n,min;
    
    scanf("%d", &n);
    getchar();
    
    if(n==0){
        r *nod=NULL;
        char c;
        while(scanf("%c", &c)!=EOF){
            if(c=='+'){
                nod=adaugare(nod);
            }
            else if(c=='-'){
                scanf("%d", &min);
                timp(nod, min);
            }
            else if(c=='?'){
                printf("%d\n", nod->nr);
            }
        }
    }
    
    else if(n==1){
        r *v[3]={NULL};
        char c;
        int i=0;
        while(scanf("%c", &c)!=EOF){
            if(c=='+'){
                v[i%3]=adaugare(v[i%3]);
                i++;
            }
            else if(c=='-'){
                scanf("%d", &min);
                v[0]=timp(v[0],min);
                v[1]=timp(v[1],min);
                v[2]=timp(v[2],min);
                
            }
            else if(c=='?'){
                int m=v[0]->nr;
                for(int j=1;j<3;j++){
                    if(v[j]->nr<m){
                        m=v[j]->nr;
                    }
                }
                printf("%d\n", m);
            }
        }
    }
    
    else if(n==2){
        r *v[3]={NULL};
        int timp1;
        char c;
        int i=0;
        while(scanf("%c", &c)!=EOF){
            if(c=='+'){
                scanf("%d", &timp1);
                if(timp1<=15)
                    v[3]=adaugare2(v[3],timp1);
                else{
                    v[i%2]=adaugare2(v[i%2],timp1);
                    i++;
                }
            }
            else if(c=='-'){
                scanf("%d", &min);
                v[0]=timp(v[0],min);
                v[1]=timp(v[1],min);
                v[2]=timp(v[2],min);
                
            }
            else if(c=='?'){
                int m=v[0]->nr;
                for(int j=1;j<3;j++){
                    if(v[j]->nr<m){
                        m=v[j]->nr;
                    }
                }
                printf("%d\n", m);
            }
        }
    }
    
    return 0;
}
