#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "Listas/lista.h"
#include "radixSort.h"

void radixSort(Lista *l, tipoElemento numGrupos, tipoElemento numCifras){
	Lista arrayListas[numGrupos];
	int i, j, k, div = 1, codigoError;
	tipoPosicion p;
	
	for(i = 0; i < numCifras; i++){
		contadorExterno++;
		for(j = 0; j < numGrupos; j++) creaVacia(&arrayListas[j]);
		
		p = primero(l);
		while (vacia(l) == 0){
			contadorInterno++;
			k = ((recupera(p, l)) / div) % numGrupos;
			traspasarNodo(p, l, fin(&arrayListas[k]), &arrayListas[k]);
		}
		div = div * 10;
		
		for(j = 0; j < numGrupos; j++) concatenarListas(l, &arrayListas[j]);
	}
}