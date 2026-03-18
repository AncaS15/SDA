#include <stdlib.h>
#include <stdio.h>

struct LISTA
{
    int data;
    struct LISTA *nod_urmator;
};

struct LISTA *adaugare_nod(struct LISTA *prim);
void afisare_lista(struct LISTA *prim);
struct LISTA *eliminare_nod(struct LISTA *prim, int n);

int main()
{
    int nr_noduri, i, n;
    struct LISTA *prim = NULL;
    scanf("%d", &nr_noduri);

    scanf("%d", &n);

    for (i = 0; i < nr_noduri; i++)
    {
        prim = adaugare_nod(prim);
    }
    prim=eliminare_nod(prim,n);
    afisare_lista(prim);
    return 0;
}

struct LISTA *adaugare_nod(struct LISTA *prim)
{
    struct LISTA *curent = prim;

    struct LISTA *nod_nou = (struct LISTA *)malloc(sizeof(struct LISTA));
    scanf("%d", &nod_nou->data); 
    nod_nou->nod_urmator = NULL; 

    if (prim != NULL)
    {
        while (curent->nod_urmator != NULL)
        {
            curent = curent->nod_urmator;
        }
        curent->nod_urmator = nod_nou;
    }
    else
    {
        prim = nod_nou;
    }

    return prim;
}

void afisare_lista(struct LISTA *prim){
    while(prim){
        printf("%d\n", prim->data);
        prim = prim->nod_urmator;
    }
}

struct LISTA *eliminare_nod(struct LISTA *prim, int n){
    struct LISTA *nod_curent;
    while(n>0 && prim!=NULL){
        nod_curent=prim;
        prim=prim->nod_urmator;
        free(nod_curent);
        n--;
    }
    return prim;
}
