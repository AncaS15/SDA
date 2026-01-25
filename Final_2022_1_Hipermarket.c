#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clienti{
    char nume[16];
    int nr_produse;
    struct clienti *next;
} client;


client *creare(char nume[16], int nr_produse){
    client *nod=malloc(sizeof(client));
    strcpy(nod->nume, nume);
    nod->nr_produse = nr_produse;
    nod->next = NULL;
    return nod;
}

client *adaugare(client *head, char nume[16], int nr_produse){
    client *nod = head;
    if(head == NULL)
        return creare(nume,nr_produse);
    while(nod->next != NULL)
        nod = nod->next;
    nod->next = creare(nume,nr_produse);
    return head;
}

void afisare(client *head){
    client *nod = head;
    while(nod != NULL){
        printf("%s %d\n", nod->nume, nod->nr_produse);
        nod = nod->next;
    }
}

void afisare_test3(client *head){
    client *nod = head;
    while(nod != NULL){
        printf("%s\n", nod->nume);
        nod = nod->next;
    }
}

int nr_total_produse(client *head){
    client *nod = head;
    int s = 0;
    while(nod != NULL){
        s += nod->nr_produse;
        nod = nod->next;
    }
    return s;
}

client *test5(client *head, int n){
    while(head!=NULL && n>0){
        if(head->nr_produse <= n){
            n -= head->nr_produse;
            client *tmp = head;
            free(tmp);
            head = head->next;
        }
        else{
            head->nr_produse -= n;
            n = 0;
        }
    }
    return head;
}

int main(){
    int test, n, nr_produse;
    char nume[16];
    
    client *c = NULL;
    
    scanf("%d%d", &test,&n);
    while(scanf("%s%d", nume,&nr_produse) != EOF){
        c = adaugare(c,nume,nr_produse);
    }
    
    if(test == 1){
        afisare(c);
    }
    
    else if(test == 2){
        printf("%d", nr_total_produse(c));
    }
    
    else if(test == 3){
        int k = 1;
        
        client *c1 = NULL;
        client *c2 = NULL;
        client *nod = c;
        
        while(nod != NULL){
            if(k%2 != 0)
                c1 = adaugare(c1,nod->nume,nod->nr_produse);
            else
                c2 = adaugare(c2,nod->nume,nod->nr_produse);
            k++;
            nod = nod->next;
        }
        
        afisare_test3(c1);
        afisare_test3(c2);
    }
    
    else if(test == 4){
        client *c1 = NULL;
        client *c2 = NULL;
        client *nod = c;
        
        while(nod != NULL){
            if(nr_total_produse(c1) <= nr_total_produse(c2))
                c1 = adaugare(c1,nod->nume,nod->nr_produse);
            else
                c2 = adaugare(c2,nod->nume,nod->nr_produse);
            nod = nod->next;
        }
        
        afisare_test3(c1);
        afisare_test3(c2);
    }
    
    else if(test == 5){
        client *c1 = NULL;
        client *c2 = NULL;
        client *nod = c;
        
        while(nod != NULL){
            if(nr_total_produse(c1) <= nr_total_produse(c2))
                c1 = adaugare(c1,nod->nume,nod->nr_produse);
            else
                c2 = adaugare(c2,nod->nume,nod->nr_produse);
            nod = nod->next;
        }
        
        c1 = test5(c1,n);
        c2 = test5(c2,n);
        
        afisare_test3(c1);
        afisare_test3(c2);
        
    }
    
    return 0;
}
