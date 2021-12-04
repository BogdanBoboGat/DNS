#include "librarie.h"

/* Comparare pentru inserare */
int ComparareEl(void *el1, void *el2)
{
    return strcmp(((TDNS *)el1)->key, ((TDNS *)el2)->key);
}

/* Comparare pentru stergere/gasire/ */
int ComparareStr(void *el, char *key)
{
    return strcmp(((TDNS *)(el))->key, key);
}

/* Introduce DNS in tabela hash */
void put(THash *h, char *key, char *value)
{
    int cod = h->fh(h->M, key);
    void *node = InitDNS(key, value);  
    
    InsLD(h->v + cod, node, ElibDNS, ComparareEl); // Insereaza element in lista
}

/* Afla valoarea cheii din tabela hash */
void get(THash *h, char *key, FILE *out)
{
    int cod = h->fh(h->M, key);
    TLD p = h->v[cod], aux;

    if(p == NULL) // Caz in care lista este goala
    {
        fprintf(out, "NULL\n");
        return;
    }
    
    else if(strcmp(((TDNS *)(p->info))->key, key) == 0) // Caz in care primul element este cel cautat
    {
        fprintf(out, "%s\n", ((TDNS *)(p->info))->value);
        return;
    }
    
    for(aux = p->urm; aux != p; aux = aux->urm) // Elementul se afla pe alta pozitie
    {
        if(strcmp(((TDNS *)(aux->info))->key, key) == 0)
        {
            fprintf(out, "%s\n", ((TDNS *)(aux->info))->value);
            return;
        }
    }

    fprintf(out, "NULL\n"); // Nu intra in niciun if => nu s-a gasit
    return;
}

/* Sterge DNS din tabela hash */
void remove_key(THash *h, char *key)
{
    int cod = h->fh(h->M, key);
    
    ElimLD(h->v + cod, key, ElibDNS, ComparareStr);
}

/* Returneaza True/False daca gaseste sau nu DNS in tabela hash */
void find(THash *h, char *key, FILE *out)
{
    int cod = h->fh(h->M, key);
    TLD p = h->v[cod], aux;

    if(p == NULL) // Lista este goala
    {
        fprintf(out, "False\n");
        return;
    }

    else if(strcmp(((TDNS *)(p->info))->key, key) == 0) // Elementul cautat se afla pe prima pozitie
    {
            fprintf(out, "True\n");
            return;
    }   

    else // Elementul se afla pe alte pozitii
    {
        for(aux = p->urm; aux != p; aux = aux->urm) 
            if(strcmp(((TDNS *)(aux->info))->key, key) == 0)
            {
                fprintf(out, "True\n");
                return;
            }
    }

    fprintf(out, "False\n");
}

/* Printeaza tabela hash */
void print(THash *h, FILE *out)
{
    TLD p, aux;
    int i;
    for(i = 0; i < h->M; i++)
    {
        p = h->v[i]; // Inceputul listei
        
        if(p) // Verificare lista goala
        {
            fprintf(out, "%d: ", i);
            fprintf(out, "%s ", ((TDNS *)(p->info))->value);
            
            for(aux = p->urm; aux != p ; aux = aux->urm)
                fprintf(out, "%s ", ((TDNS *)(aux->info))->value);
            fprintf(out, "\n");
        }
    }

}

/* Printeaza lista specifica codului hash */
void print_bucket(THash *h, int bucket, FILE *out)
{
    if(bucket >= h->M) // Cazul in care se da un numar mai mare
        return;

    TLD aux, p = h->v[bucket];
    if(p)
    {
        fprintf(out, "%s ", ((TDNS *)(p->info))->value);

        for(aux = p->urm; aux != p; aux = aux->urm)
            fprintf(out, "%s ", ((TDNS *)(aux->info))->value);
        
        fprintf(out, "\n");
    }
    
    else
        fprintf(out, "VIDA\n");
}
