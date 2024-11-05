all: cancion

cancion: cancion.c cancion.h
	gcc -g cancion.c -c

listaCancion: listaCancion.c listaCancion.h
	gcc -g listaCancion.c -c