#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/* Pointer la functie de codificare */
typedef int (*TFHash)(int, char *);

/* Pointer la functia de eliberare */
typedef void (*TF)(void *);

/* Pointer la functia de comparare a 2 elementele */
typedef int (*CompDNS)(void *, void*);

/* Pointer la functia de comparat siruri */
typedef int (*CompStr)(void *, char *);

/* Struct de date din lista */
typedef struct
{
    char *key;
    char *value;
}TDNS;

/* Lista Dublu Inlantuita Generica */
typedef struct celula
{
    void *info;
    struct celula *pre, *urm;
}TCelula, *TLD;

/* Tabela Hash */
typedef struct
{
    int M;
    TFHash fh;
    TLD *v;
}THash;

/* Functii tema */
void put(THash *h, char *key, char *value); // Inserare in hash
void get(THash *h, char *key, FILE *out); // Returneaza value din DNS
void remove_key(THash *h, char *key); // Sterge DNS
void find(THash *h, char *key, FILE *out); // Returneaza True/False daca gaseste DNS-ul
void print(THash *h, FILE *out); // Printeaza Tabela Hash
void print_bucket(THash *h, int bucket, FILE *out); // Printeaza lista dupa cod

/* Fuctii Tabela Hash (functiiHash.c) */
THash *InitH(int M, TFHash fh); // Initializare tabela
int codHash(int size, char *key); // Functie codificare
void DistrTH(THash **h, TF fe); // Eliberare memorie tab. hash

/* Functii lista inlantuita (functiiLD.c) */
TLD InitLD(void *node); // Initializeaza o lista cu un element
int InsLD(TLD *L, void *el, TF fe, CompDNS c); // Inserare in lista
void ElimLD(TLD *L, char *key, TF fe, CompStr c); // Eliminare din lista

/* Functii DNS (functiiDNS.c) */
void *InitDNS(char *key, char *value); // Initializeaza o structura DNS
void ElibDNS(void *info); // Eliberare memorie DNS