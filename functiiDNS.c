#include "librarie.h"

/* Elibereaza memoria ocupada de un DNS */
void ElibDNS(void *info)
{
    free(((TDNS *)(info))->key);
    free(((TDNS *)(info))->value);
    free(((TDNS *)(info)));
}

/* Initializare element DNS */
void *InitDNS(char *key, char *value)
{
    TDNS *node = malloc(sizeof(TDNS));
    if(!node)
        return NULL;
    
    node->key = malloc(MAX);
    if(!node->key)
    {
        free(node);
        return NULL;
    }

    node->value = malloc(MAX);
    if(!node->value)
    {
        free(node->key);
        free(node);
        return NULL;
    }

    strcpy(node->key, key);
    strcpy(node->value, value);

    return (void *)node;
}