#include <stdlib.h>
#include <stdio.h>

struct LISTA
{
    int data;
    struct LISTA *nod_urmator;
};

struct LISTA *adaugare_nod(struct LISTA *prim);
void parcurgere_noduri_pare(struct LISTA *prim);

int main()
{
    int nr_noduri, i;
    struct LISTA *prim = NULL;
    scanf("%d", &nr_noduri);

    for (i = 0; i < nr_noduri; i++)
    {
        prim = adaugare_nod(prim);
    }
    // Inceput apelare functie parcurgere_noduri_pare(...):
    parcurgere_noduri_pare(prim);
    // Sfarsit apelare functie parcurgere_noduri_pare(...):
    
    return 0;
}

struct LISTA *adaugare_nod(struct LISTA *prim)
{
    struct LISTA *curent = prim;

    // creare nod nou:
    struct LISTA *nod_nou = (struct LISTA *)malloc(sizeof(struct LISTA));
    scanf("%d", &nod_nou->data); // stocarea continutului pentru ultimul nod
    nod_nou->nod_urmator = NULL; // legatura ultimului nod catre NULL

    // plasare pe ultimul nod:
    if (prim != NULL)
    {
        while (curent->nod_urmator != NULL)
        {
            curent = curent->nod_urmator;
        }
        curent->nod_urmator = nod_nou; // ultimul nod din lista este legat la noul nod
    }
    else
    {
        prim = nod_nou; // lista este goala; noul nod devine primul nod din lista
    }

    return prim;
}

////////////////////////////////////////////////////////////////////////////////

void parcurgere_noduri_pare(struct LISTA *prim){
    struct LISTA *nod_curent=prim;
    while(nod_curent!=NULL){
        printf("%d\n", nod_curent->data);
        nod_curent=nod_curent->nod_urmator;
        if(nod_curent!=NULL)
            nod_curent=nod_curent->nod_urmator;
    }
}
