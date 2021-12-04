build: 
	gcc -Wall -g -o tema1 functiiLD.c functiiDNS.c functiiTema.c functiiHash.c main.c
clean:
	rm -rf tema1
valgrind:
	valgrind --leak-check=yes --vgdb=no --track-origins=yes ./tema1 in_file out_file