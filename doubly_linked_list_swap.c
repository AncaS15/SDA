typedef struct lista{
    int date;
    struct lista *next;
    struct lista *prev;
} lista_t;

lista_t *creare(){
    lista_t *nod_nou=malloc(sizeof(lista_t));
    scanf("%d", &nod_nou->date);
    nod_nou->next=NULL;
    nod_nou->prev=NULL;
    return nod_nou;
}

lista_t *adaugare(lista_t *head){
    lista_t *nod_curent=head;
    lista_t *nod_nou=creare();
    if(head==NULL)
        return nod_nou;
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=nod_nou;
    nod_nou->prev=nod_curent;
    return head;
}

void afisare(lista_t *head){
    lista_t *nod=head;
    while(nod!=NULL){
        printf("%d\n", nod->date);
        nod=nod->next;
    }
}

lista_t *interschimbare(lista_t *head){
    lista_t *prim=head, *ultim=head;
    while(ultim->next!=NULL)
        ultim=ultim->next;
    
    if(prim->next==ultim){
        prim->next=NULL;
        ultim->prev=NULL;
        prim->prev=ultim;
        ultim->next=prim;
        return ultim;
    }
    
    if(prim->next!=NULL)
        prim->next->prev=ultim;
    if(ultim->prev!=NULL)
        ultim->prev->next=prim;
    
    lista_t *aux=prim->next;
    prim->next=ultim->next;
    ultim->next=aux;
    
    aux=prim->prev;
    prim->prev=ultim->prev;
    ultim->prev=aux;
    
    return ultim;
}

int main(){
    int n;
    lista_t *list=NULL;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        list=adaugare(list);
    
    afisare(list);
    list=interschimbare(list);
    afisare(list);
    
    return 0;
}
