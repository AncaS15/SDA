#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jucatori{
    char nume[31];
    struct jucatori *next;
} jucator;

jucator *creare(char nume[31]){
    jucator *nod = malloc(sizeof(jucator));
    strcpy(nod->nume, nume);
    nod->next = NULL;
    return nod;
}

jucator *adaugare(jucator *head, char nume[31]){
    jucator *nod = head;
    if(head == NULL)
        return creare(nume);
    while(nod->next != NULL)
        nod = nod->next;
    nod->next = creare(nume);
    return head;
}

void afisare(jucator *head){
    jucator *nod = head;
    int k=0;
    while(nod != NULL){
        k++;
        printf("%s\n", nod->nume);
        if(k%2 == 0)
            printf("\n");
        nod = nod->next;
    }
}

void test2(jucator *head, char nume1[31], char nume2[31]){
    jucator *nod = head;
    int index1, index2, k = 0;
    while(nod != NULL){
        k++;
        if(strcmp(nod->nume, nume1) == 0)
            index1 = k;
        else if(strcmp(nod->nume, nume2) == 0)
            index2 = k;
        nod = nod->next;
    }
    k = (index2-index1+1)/2;
    printf("%d", k+1);
}

jucator *castigator(jucator *jucator1, jucator *jucator2, int *scor1, int *scor2, int p){
    int set1 = 0, set2 = 0;
    for(int i=0; i<p; i++){
        if(scor1[i] > scor2[i])
            set1++;
        else if(scor1[i] < scor2[i])
            set2++;
    }
    
    if(set1 == 3)
        return jucator1;
    else if(set2 == 3)
        return jucator2;
}

int main(){
    int n, test;
    char nume[31];
    
    jucator *joc = NULL;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", nume);
        joc = adaugare(joc, nume);
    }
    scanf("%d", &test);
    
    if(test==1)
        afisare(joc);
    
    else if(test == 2){
        char nume1[31], nume2[31];
        scanf("%s%s", nume1, nume2);
        test2(joc, nume1, nume2);
    }
    
    else if(test == 3){
        jucator *nod = joc;
        jucator *lista2 = NULL;
        
        while(nod != NULL){
            int p;
            scanf("%d", &p);
            
            int *scor1 = malloc(p*sizeof(int));
            int *scor2 = malloc(p*sizeof(int));
            for(int i=0; i<p; i++)
                scanf("%d", &scor1[i]);
            for(int i=0; i<p; i++)
                scanf("%d", &scor2[i]);
                
            jucator *jucator_castigator = castigator(nod, nod->next, scor1, scor2, p);
            lista2 = adaugare(lista2, jucator_castigator->nume);
            nod = nod->next->next;
        }
        
        afisare(lista2);
    }
    
    else if(test == 4){
        jucator *nod = joc;
        jucator *jucator_max = NULL;
        int scor_maxim = 0;
        
        while(nod != NULL){
            int p;
            scanf("%d", &p);
            
            int *scor1 = malloc(p*sizeof(int));
            int *scor2 = malloc(p*sizeof(int));
            for(int i=0; i<p; i++)
                scanf("%d", &scor1[i]);
            for(int i=0; i<p; i++)
                scanf("%d", &scor2[i]);
                
            int scor_total = 0;
            for(int i=0; i<p; i++)
                scor_total += scor1[i] + scor2[i];
                    
            if(scor_total > scor_maxim){
                scor_maxim = scor_total;
                jucator_max = nod;
            }
            nod = nod->next->next;
        }
        printf("%s\n%s\n", jucator_max->nume, jucator_max->next->nume);
    }
    
    else if(test == 5){
        jucator *lista_curenta = joc;
        while(lista_curenta->next != NULL){
            jucator *nod = lista_curenta;
            jucator *lista2 = NULL;
            
            while(nod != NULL){
                int p;
                scanf("%d", &p);
                
                int *scor1 = malloc(p*sizeof(int));
                int *scor2 = malloc(p*sizeof(int));
                for(int i=0; i<p; i++)
                    scanf("%d", &scor1[i]);
                for(int i=0; i<p; i++)
                    scanf("%d", &scor2[i]);
                    
                jucator *jucator_castigator = castigator(nod, nod->next, scor1, scor2, p);
                lista2 = adaugare(lista2, jucator_castigator->nume);
                nod = nod->next->next;
            }
            lista_curenta = lista2;
        }
        printf("%s\n", lista_curenta->nume);
    }
    
    return 0;
}
