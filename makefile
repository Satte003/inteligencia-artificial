all: cancion ejecutorLista

cancion: cancion.c cancion.h
	gcc -g cancion.c -c

listaCancion: listaCancion.c listaCancion.h
	gcc -g listaCancion.c -c

ejecutorLista: listaCancion.o cancion.o
	gcc -g ejecutorLista.c listaCancion.o cancion.o -o ejecutorLista