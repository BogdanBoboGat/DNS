=============================================================================
Nume: Butnariu Bogdan Mihai
Grupa: 312CB

init. Tema1 SD......
=============================================================================
librarie.h

  Sunt definite structurile pentru:
* Lista Dublu Inlantuita Generica
* Elementul DNS, compus din cheie (www.google.com) si valoarea
* Tabela Hash

  Sunt definite functiile din cele 3 fisiere '.c'
* functiiTema.c, functiile din cerinta
* functiiHash.c, functiile pentru tabela Hash
* functiiDNS.c, functiile pentru elementele DNS
* functiiLD.c, functiile pentru lista dublu inlantuita Generica
=============================================================================
main.c

1. Initializare variabile
2. Argumente linia de comanda
3. Citire linie cu linie din fisierul in, folosind getline()
4. In caz ca sunt 2 linii goale consecutive, programul se opreste
5. If-urile pentru fiecare functie in parte
6. Inchidere fisiere + Eliberare memorie
=============================================================================
functiiHash.c

1. codHash():
    * calculeaza suma Ascii a literelor din key
    * returneaza suma modulo nr. liste

2. InitTH():
    * initializeaza pointer catre Tabela Hash

3. DistrTH():
    * elibereaza memoria alocata de Tabela Hash
=============================================================================
functiiLD.c

1. InitLD():
    * initializare pointer catre o lista cu un singur element

2. InsLD():
    * este impartita pe mai multe cazuri:
      lista este goala;
      lista are un singur element;
      lista are mai multe elemente;
    * daca gaseste elementul DNS in orice caz, se opreste

3. ElimLD():
    * este impartita pe mai multe cazuri:
      lista este goala;
      lista are un singur element;
      lista are mai multe elemente;
    * daca gaseste elementul DNS in orice caz, elimina si reface lista
=============================================================================
functiiDNS.c

1. ElibTDNS():
    * elibereaza memoria alocata de un element DNS

2. InitDNS():
    * creaza un element DNS nou si il returneaza ca 'void *'
=============================================================================
functiiTema.c

1. ComparareEl():
    * compara 2 elemente de tip DNS

2. ComparareEl():
    * compara 2 siruri DNS->key si key

3. put():
    * calculeaza codul hash pentru DNS si apeleaza InsLD

4. get():
    * calculeaza codul hash pentru DNS
    * parcurge listele hash si returneaza valoarea cautata

5. remove_key():
    * calculeaza codul hash pentru DNS si apeleaza ElimLD

6. find():
    * parcurge lista si returneaza True/False daca gaseste elementul DNS

7. print():
    * printeaza listele din tabela hash

8. print_bucket():
    * printeaza lista coresp. din tabela hash
=============================================================================
exit() - code 0