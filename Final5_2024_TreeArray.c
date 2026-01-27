#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cuvinte{
    char c[21];
    int frecv;
    struct cuvinte *next;
} cuv;

typedef struct cuv_tree{
    char c[21];
    int frecv;
    struct cuv_tree *stanga;
    struct cuv_tree *dreapta;
} tree;

cuv *creare(char c[21]){
    cuv *nod = malloc(sizeof(cuv));
    strcpy(nod->c, c);
    nod->frecv = 1;
    nod->next = NULL;
    return nod;
}

cuv *adaugare(cuv *head, char c[21]){
    cuv *nod = head;
    if(head ==  NULL)
        return creare(c);
    while(nod->next != NULL)
        nod = nod->next;
    nod->next = creare(c);
    return head;
}

void afisare_cuv(cuv *head){
    cuv *nod = head;
    while(nod!=NULL){
        printf("%s\n", nod->c);
        nod = nod->next;
    }
}

cuv *adaugare_frecv(cuv *head, char c[21]){
    cuv *nod = head;
    while(nod != NULL){
        if(strcmp(nod->c, c) == 0){
            nod->frecv++;
            return head;
        }
        nod = nod->next;
    }
    return adaugare(head,c);
}

void afisare_frecv(cuv *head){
    cuv *nod = head;
    while(nod!=NULL){
        printf("%s %d\n", nod->c, nod->frecv);
        nod = nod->next;
    }
}

tree *creare_tree(char c[21]){
    tree *nod = malloc(sizeof(tree));
    strcpy(nod->c, c);
    nod->frecv = 1;
    nod->stanga = NULL;
    nod->dreapta = NULL;
    return nod;
}

tree *adaugare_tree(tree *head, char c[21]){
    if(head == NULL)
        return creare_tree(c);
    if(strcmp(head->c, c) == 0){
        head->frecv++;
        return head;
    }
    if(strcmp(head->c, c) < 0)
        head->dreapta = adaugare_tree(head->dreapta, c);
    if(strcmp(head->c, c) > 0)
        head->stanga = adaugare_tree(head->stanga, c);
    return head;
}

void afisare_tree(tree *head){
    if(head == NULL)
        return;
    
    afisare_tree(head->stanga);
    printf("%s\n", head->c);
    afisare_tree(head->dreapta);
}

void afisare_post(tree *head){
    if(head == NULL)
        return;
    
    afisare_post(head->stanga);
    afisare_post(head->dreapta);
    printf("%s\n", head->c);
}

void descendenti(tree *head, char cuv_index[21]){
    if(head == NULL)
        return;
    if(strcmp(head->c, cuv_index) != 0){
        descendenti(head->stanga, cuv_index);
        descendenti(head->dreapta, cuv_index);
    }
    
    else if(strcmp(head->c, cuv_index) == 0){
        afisare_post(head);
        return;
    }
}

void frecv_max(tree *head, int f1, int f2, char c1[21], char c2[21]){
    if(head == NULL)
        return;
    if(head->frecv > f1){
        f1 = head->frecv;
        strcpy(c1, head->c);
    }
    else if(head->frecv > f2){
        f2 = head->frecv;
        strcpy(c2, head->c);
    }
    frecv_max(head->stanga, f1, f2, c1, c2);
    frecv_max(head->dreapta, f1, f2, c1, c2);
}

void descendenti_frecventi(tree *head, char cuv_index[21]){
    if(head == NULL)
        return;
    if(strcmp(head->c, cuv_index) != 0){
        descendenti_frecventi(head->stanga, cuv_index);
        descendenti_frecventi(head->dreapta, cuv_index);
    }
    
    else if(strcmp(head->c, cuv_index) == 0){
        int f1 = 0, f2 = 0;
        char c1[21], c2[21];
        frecv_max(head, f1, f2, c1, c2);
        printf("%s\n%s\n", c1, c2);
    }
}

int main(){
    int test, index;
    char cuvant[21];
    char cuv_index[21];
    
    cuv *list_cuv = NULL;
    cuv *list_frecv = NULL;
    
    tree *arb = NULL;
    
    scanf("%d%d", &test, &index);
    while(scanf("%s", cuvant) != EOF){
        list_cuv = adaugare(list_cuv, cuvant);
        list_frecv = adaugare_frecv(list_frecv, cuvant);
        arb = adaugare_tree(arb, cuvant);
        if(index > 0)
            index--;
        else if(index == 0){
            strcpy(cuv_index, cuvant);
            index--;
        }
    }
    
    if(test == 1)
        afisare_cuv(list_cuv);
    
    else if(test == 2)
        afisare_frecv(list_frecv);

    else if(test == 3)
        afisare_tree(arb);
    
    else if(test == 4)
        descendenti(arb, cuv_index);
    
    else if(test == 5)
        descendenti_frecventi(arb, cuv_index);
    
    return 0;
}
