#include "librarie.h"

/* Initializare lista cu un element */
TLD InitLD(void *node)
{
    TLD aux = malloc(sizeof(TCelula));
    if(!aux)
        return NULL;

    aux->urm = aux;
    aux->pre = aux;

    aux->info = node;
    return aux;
}

/* Inserare in lista */
int InsLD(TLD *L, void *el, TF fe, CompDNS c)
{
    TLD p1 = *L, p2;
    
    TLD aux = InitLD(el);
    if(!aux)
        return 0;

    if(*L == NULL) // Lista este goala
    {
        *L = aux;
        return 1;
    }

    else if(p1 == p1->urm) // Lista are un element
    {
        if(c(p1->info, el) == 0) // Daca DNS-ul este deja inserat
        {    
            fe(aux->info);
            free(aux);
            return 0;
        }

        else if(c(p1->info, el) < 0) // Inserare dupa prima pozitie
        {
            aux->urm = p1;
            aux->pre = p1;
            p1->urm = aux;
            p1->pre = aux;
            return 1;
        }

        else // Inserare inainte de prima pozitie
        {
            aux->urm = p1;
            aux->pre = p1;
            p1->urm = aux;
            p1->pre = aux;
            *L = aux;
            return 1;
        }
        
    }
            
    else // Lista are mai multe elemente
    {        
        if(c(p1->info, el) == 0) // Daca DNS-ul este deja inserat
        {   
            fe(aux->info);
            free(aux);
            return 0;
        }
        
        else if(c(p1->info, el) > 0) // Inserare inceput de lista
        {
            aux->urm = p1;
            aux->pre = p1->pre;
            p1->pre->urm = aux;
            p1->pre = aux;
            *L = aux;
        }

        else // Inserare in lista
        {
            for(p2 = p1->urm; p2 != p1; p2 = p2->urm)
            {
                if(c(p2->info, el) == 0) // Daca DNS-ul este deja inserat
                {
                    fe(aux->info);
                    free(aux);
                    return 0;
                }
                
                else if(c(p2->info, el) < 0) // Parcurgere pana in momentul inserarii
                    continue;
                
                else
                {   
                    aux->urm = p2;
                    aux->pre = p2->pre;
                    p2->pre->urm = aux;
                    p2->pre = aux;
                    return 1;
                }
            }
            
            // Inserare la final de lista
            p2 = p1->pre;
            aux->pre = p2;
            aux->urm = p1;
            p2->urm->pre = aux;
            p2->urm = aux;
            return 1;
        }
    }
    return 0;
}

/* Elimina elementul DNS din lista */
void ElimLD(TLD *L, char *key, TF fe, CompStr c)
{
    TLD p = *L, aux;
    
    if(p == NULL) // Lista este goala
        return;

    else if(p == p->urm) // Lista are un singur element
    {
        if(c(p->info, key) == 0)
        {   
            fe(p->info);
            free(p);
            *L = NULL;
            return;
        } 
    }
    
    else // Lista are mai multe elemente
    {
        if(c(p->info, key) == 0) // Elementul este pe prima pozitie
        {
            p->urm->pre = p->pre;
            p->pre->urm = p->urm;
            *L = p->urm;
            fe(p->info);
            free(p);
            return;
        }

        else // Elementul se afla pe alta pozitie
        {
            for(aux = p->urm; aux != p; aux = aux->urm)
            {
                if(c(aux->info, key) == 0)
                {   
                    aux->pre->urm = aux->urm;
                    aux->urm->pre = aux->pre;
                    fe(aux->info);
                    free(aux);
                    return;
                }
            }
        }
    }
}
