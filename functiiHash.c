#include "librarie.h"

/* Calculeaza codul corespunzator fiecarui DNS */
int codHash(int size, char *key)
{
    char *copy;
    int suma = 0;

    for(copy = key; *copy != '\0'; copy++)
    {
        suma += *copy;
    }

    return suma % size;
}

/* Initializare Tabela Hash cu: M = dimensiune, fh = functie de codificare */
THash *InitH(int M, TFHash fh)
{
    THash *h;
    h = (THash *)calloc(1, sizeof(THash));
    if(!h)
    {
        printf("Eroare la alocare tabela hash.\n");
        return NULL;
    }

    h->v = (TLD *)calloc(M, sizeof(TLD));
    if(!h->v)
    {
        printf("Eroare la alocare bucket.");
        free(h);
        return NULL;
    }
    
    h->M = M;
    h->fh = fh;

    return h;
}

/* Eliberare memorie Tabela Hash */
void DistrTH(THash **h, TF fe)
{
    TLD *p, el, aux;
    for(p = (*h)->v; p < (*h)->v + (*h)->M; p++)
    {   
        if(*p == NULL)
            continue;
        
        for(el = (*p)->urm; el != *p;)
        {
            aux = el;
            el = el->urm;
            fe(aux->info);
            free(aux);
        }
        aux = *p;
        fe(aux->info);
        free(aux);
    }
    free((*h)->v);
    free(*h);
    *h = NULL;
}