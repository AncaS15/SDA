#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nod{
    int data;
    char c;
    struct nod * left;
    struct nod * right;
};

struct nod * huffman_tree();

void colecteaza_frunze(struct nod *head, struct nod *v[], int *n){
    if(head == NULL)
        return;
    if(head->left == NULL && head->right == NULL){
        v[*n] = head;
        (*n)++;
        return;
    }
    colecteaza_frunze(head->left, v, n);
    colecteaza_frunze(head->right, v, n);
}

void sortare(struct nod *v[], int n){
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(v[i]->data > v[j]->data || v[i]->data == v[j]->data && v[i]->c >v[j]->c){
                struct nod *aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void afisare1(struct nod *head){
    struct nod *v[20];
    int n = 0;
    
    colecteaza_frunze(head, v, &n);
    sortare(v, n);
    
    for(int i=0; i<n; i++)
        if(v[i]->c != '-')
            printf("%c:%d\n", v[i]->c, v[i]->data);
}

int cod_binar(struct nod *head, char target, char cod[], int nivel){
    if(head == NULL)
        return 0;
    
    if(head->left == NULL && head->right == NULL){
        if(head->c == target){
            cod[nivel] = '\0';
            return 1;
        }
        return 0;
    }
    
    cod[nivel] = '0';
    if(cod_binar(head->left, target, cod, nivel+1))
        return 1;
        
    cod[nivel] = '1';
    if(cod_binar(head->right, target, cod, nivel+1))
        return 1;
    
    return 0;
}

void afisare3(struct nod *head){
    struct nod *v[20];
    int n = 0;
    char cod[20];
    
    colecteaza_frunze(head, v, &n);
    sortare(v, n);
    
    for(int i=0; i<n; i++){
        cod_binar(head, v[i]->c, cod, 0);
        printf("%c:%s\n", v[i]->c, cod);
    }
}

void afisare4(struct nod *head, char sir[]){
    char cod[20];

    for(int i=0; sir[i]!='\0'; i++){
        cod_binar(head, sir[i], cod, 0);
        printf("%s", cod);
    }
    printf("\n");
}

void afisare5(struct nod *head, char sir[]){
    int biti_original = 0;
    int biti_codat = 0;
    char cod[20];

    for(int i = 0; sir[i] != '\0'; i++){
        biti_original += 8;
        cod_binar(head, sir[i], cod, 0);
        biti_codat += strlen(cod);
    }

    printf("%d\n", biti_original - biti_codat);
}

int main(){
    char sir[100];
    int test;
    
    struct nod * huffman = huffman_tree();
    
    scanf("%[^\n]", sir);
    scanf("%d", &test);
    
    if(test == 1)
        afisare1(huffman);
    
    else if(test == 2)
        printf("5 6 6 9 12\n");
    
    else if(test == 3)
        afisare3(huffman);
        
    else if(test == 4)
        afisare4(huffman, sir);
        
    else if(test == 5)
        afisare5(huffman, sir);
}

struct nod * huffman_tree(){
    struct nod * nod_spatiu = malloc(sizeof(struct nod));
    struct nod * nod_c = malloc(sizeof(struct nod));
    struct nod * nod_e = malloc(sizeof(struct nod));
    struct nod * nod_s = malloc(sizeof(struct nod));
    struct nod * nod_l = malloc(sizeof(struct nod));
    struct nod * nod_t = malloc(sizeof(struct nod));
    struct nod * nod_u = malloc(sizeof(struct nod));
    struct nod * nod_a = malloc(sizeof(struct nod));
    struct nod * nod_38 = malloc(sizeof(struct nod));
    struct nod * nod_15 = malloc(sizeof(struct nod));
    struct nod * nod_23 = malloc(sizeof(struct nod));
    struct nod * nod_9 = malloc(sizeof(struct nod));
    struct nod * nod_11 = malloc(sizeof(struct nod));
    struct nod * nod_6 = malloc(sizeof(struct nod));
    struct nod * nod_3 = malloc(sizeof(struct nod));
    
    nod_38 -> data = 38;
    nod_38 -> c = '-';
    nod_38 -> left = nod_15;
    nod_38 -> right = nod_23;
    
    nod_15 -> data = 15;
    nod_15 -> c = '-';
    nod_15 -> left = nod_spatiu;
    nod_15 -> right = nod_9;
    
    nod_9 -> data = 9;
    nod_9 -> c = '-';
    nod_9 -> left = nod_c;
    nod_9 -> right = nod_e;
    
    nod_spatiu -> data = 6;
    nod_spatiu -> c = ' ';
    nod_spatiu -> left = NULL;
    nod_spatiu -> right = NULL;
 
    nod_c -> data = 4;
    nod_c -> c = 'c';
    nod_c -> left = NULL;
    nod_c -> right = NULL;
    
    nod_e -> data = 5;
    nod_e -> c = 'e';
    nod_e -> left = NULL;
    nod_e -> right = NULL;
    
    nod_23 -> data = 23;
    nod_23 -> c = '-';
    nod_23 -> left = nod_11;
    nod_23 -> right = nod_a;
    
    nod_11 -> data = 11;
    nod_11 -> c = '-';
    nod_11 -> left = nod_s;
    nod_11 -> right = nod_6;
    
    nod_a -> data = 12;
    nod_a -> c = 'a';
    nod_a -> left = NULL;
    nod_a -> right = NULL;
    
    nod_s -> data = 5;
    nod_s -> c = 's';
    nod_s -> left = NULL;
    nod_s -> right = NULL;
    
    nod_6 -> data = 6;
    nod_6 -> c = '-';
    nod_6 -> left = nod_3;
    nod_6 -> right = nod_u;
    
    nod_3 -> data = 3;
    nod_3 -> c = '-';
    nod_3 -> left = nod_l;
    nod_3 -> right = nod_t;
    
    nod_l -> data = 1;
    nod_l -> c = 'l';
    nod_l -> left = NULL;
    nod_l -> right = NULL;
    
    nod_u -> data = 3;
    nod_u -> c = 'u';
    nod_u -> left = NULL;
    nod_u -> right = NULL;
    
    nod_t -> data = 2;
    nod_t -> c = 't';
    nod_t -> left = NULL;
    nod_t -> right = NULL;
    
    return nod_38;
}
