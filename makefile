all: cancion esExito normalizar cargarDatos ejecutorLista ejecutorCargarDatos

cancion: cancion.c cancion.h
	gcc -g cancion.c -c

listaCancion: listaCancion.c listaCancion.h
	gcc -g listaCancion.c -c

esExito: esExito.c esExito.h
	gcc -g esExito.c -c

normalizar: normalizar.c normalizar.h
	gcc -g normalizar.c -c

cargarDatos: cargarDatos.c cargarDatos.h
	gcc -g cargarDatos.c -c

ejecutorLista: cancion.o listaCancion.o
	gcc -g ejecutorLista.c cancion.o listaCancion.o -o ejecutorLista

ejecutorCargarDatos: cancion.o listaCancion.o esExito.o normalizar.o cargarDatos.o
	gcc -g ejecutorCargarDatos.c cancion.o listaCancion.o esExito.o normalizar.o cargarDatos.o -o ejecutorCargarDatos