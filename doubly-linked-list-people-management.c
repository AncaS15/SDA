#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persoane {
    char nume[16];
    int id;
    struct persoane *next;
    struct persoane *prev;
} pers;

pers *creare(char nume[16], int id){
    pers *nod = malloc(sizeof(pers));
    strcpy(nod->nume, nume);
    nod->id = id;
    nod->next = NULL;
    nod->prev = NULL;
    return nod;
}

pers *adaugare(pers *head, char nume[16], int id){
    pers *nod = creare(nume, id);
    if(head == NULL)
        return nod;
    nod->next = head;
    head->prev = nod;
    return nod;
}

void afisare(pers *head){
    pers *nod = head;
    while(nod != NULL){
        printf("%s %d\n", nod->nume, nod->id);
        nod = nod->next;
    }
}

void nume_id_maxim(pers *head){
    if(head == NULL)
        return;
    pers *nod = head->next;
    int id_max = head->id;
    char nume_id_max[16];
    strcpy(nume_id_max, head->nume);
    while(nod != NULL){
        if(nod->id > id_max){
            id_max = nod->id;
            strcpy(nume_id_max, nod->nume);
        }
        nod = nod->next;
    }
    printf("%s\n", nume_id_max);
}

pers *eliminare_persoana(pers *head, int index){
    pers *nod = head;
    while(nod != NULL){
        if(nod->id == index){
            if(nod->prev == NULL){
                head = nod->next;
                if(head != NULL)
                    head->prev = NULL;
            }
            else{
                nod->prev->next = nod->next;
                if(nod->next != NULL)
                    nod->next->prev = nod->prev;
            }
            free(nod);
            return head;
        }
        nod = nod->next;
    }
    return head;
}

int id_maxim(pers *head){
    if(head == NULL)
        return -1;
    pers *nod = head->next;
    int id_max = head->id;
    while(nod != NULL){
        if(nod->id > id_max)
            id_max = nod->id;
        nod = nod->next;
    }
    return id_max;
}

pers *sortare_crescator(pers *head){
    pers *lista_sortata = NULL;
    while(head != NULL){
        int max = id_maxim(head);
        pers *nod = head;
        while(nod != NULL){
            if(nod->id == max){
                lista_sortata = adaugare(lista_sortata, nod->nume, nod->id);
                if(nod->prev == NULL){
                    head = nod->next;
                    if(head != NULL)
                        head->prev = NULL;
                }
                else{
                    nod->prev->next = nod->next;
                    if(nod->next != NULL)
                        nod->next->prev = nod->prev;
                }
                free(nod);
                break;
            }
            nod = nod->next;
        }
    }
    return lista_sortata;
}

void afisare_impar(pers *head){
    pers *nod = head;
    while(nod != NULL){
        if(nod->id%2 == 1)
            printf("%s %d\n", nod->nume, nod->id);
        nod = nod->next;
    }
}

void afisare_par(pers *head){
    pers *nod = head;
    while(nod != NULL){
        if(nod->id%2 == 0)
            printf("%s %d\n", nod->nume, nod->id);
        nod = nod->next;
    }
}

int main(){
    int test, id, index;
    char nume[16];
    
    pers *p = NULL;
    pers *p2 = NULL;
    
    scanf("%d%d", &test, &index);
    while(scanf("%s", nume) != EOF){
        scanf("%d", &id);
        p = adaugare(p, nume, id);
    }
    
    if(test == 1)
        afisare(p);
        
    else if(test == 2)
        nume_id_maxim(p);
    
    else if(test == 3){
        p = eliminare_persoana(p, index);
        afisare(p);
    }
    else if(test == 4){
        p2 = sortare_crescator(p);
        afisare(p2);
    }
    else if(test == 5){
        p2 = sortare_crescator(p);
        afisare_impar(p2);
        afisare_par(p2);
    }
    
    return 0;
}
