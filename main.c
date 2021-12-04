#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librarie.h"

int main(int argc, char *argv[])
{
    /* Variabile declarate */
    FILE *in, *out;
    char *fisier_in, *fisier_out, *bucket, *function, *line = NULL;
    int size_bucket, n_bucket;
    size_t len = 0;
    THash *h = NULL;

    /* Citire argumente linia de comanda */
    bucket = argv[1]; 
    fisier_in = argv[2];
    fisier_out = argv[3];
    size_bucket = atoi(bucket);

    /* Initializare tabela hash */
    h = InitH(size_bucket, codHash);

    in = fopen(fisier_in, "rt");
    out = fopen(fisier_out, "wt");

    /* Citire linie cu linie din fisierul in */
    while(getline(&line, &len, in) != -1)
    {   
        function = strtok(line, " \n"); // Functia citita 

        if(function == NULL) // In caz sunt mai multe linii '\n' in fisier
        {
            fclose(in);
            fclose(out);
            free(line);
            DistrTH(&h, ElibDNS);
            return 0;
        }

        if(strcmp(function, "put") == 0)  // Apelare functia 'put'
        {
            char *key = strtok(NULL, " ");
            char *value = strtok(NULL, " \n");
            put(h, key, value);
        }

        else if(strcmp(function, "get") == 0) // Apelare functia 'get'
        {
            char *key = strtok(NULL, " \n");
            get(h, key, out);
        }

        else if(strcmp(function, "remove") == 0)  // Apelare functia 'remove'
        {
            char *key = strtok(NULL, "  \n");
            remove_key(h, key);
        }

        else if(strcmp(function, "find") == 0) // Apelare functia 'find'
        {
            char *key = strtok(NULL, " \n");
            find(h, key, out);
        }

        else if(strcmp(function, "print") == 0) // Apelare functia 'print'
        {
            print(h, out);
        }

        else if(strcmp(function, "print_bucket") == 0) // Apelare functia 'print_bucket'
        {
            n_bucket = atoi(strtok(NULL, " \n"));
            print_bucket(h, n_bucket, out);
        }
    }

    /* Inchidere fisiere + Eliberare memorie */
    fclose(in);
    fclose(out);
    
    free(line);
    DistrTH(&h, ElibDNS);
    return 0;
}