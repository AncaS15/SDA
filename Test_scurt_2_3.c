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

    scanf("%d", &n); // valoarea arbitrara ce va fi transmisa functiei eliminare_nod(...) care va dicta numarul de noduri ce vor fi sterse de la inceputul listei.

    for (i = 0; i < nr_noduri; i++)
    {
        prim = adaugare_nod(prim);
    }
    // Inceput apelare functie eliminare_nod(...):
    prim=eliminare_nod(prim,n);
    // Sfarsit apelare functie eliminare_nod(...):
    afisare_lista(prim);
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

void afisare_lista(struct LISTA *prim){
    while(prim){
        printf("%d\n", prim->data);
        prim = prim->nod_urmator;
    }
}

////////////////////////////////////////////////////////////////////////////////

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
