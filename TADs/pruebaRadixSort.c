#include <stdio.h>
#include <stdlib.h>
#include "Listas/lista.h"
#include "radixSort.h"

int purga(Lista *l);

int main(int argc, char *argv[]){
    Lista miLista;
    tipoPosicion p;
    int numElementos = 20, codigoError, i;

	if (argc > 2) {
        printf("\n Uso: ./pruebaRadixSort <num de elementos de la lista>\n\n");
        return -1;
    }
    
    if (argc == 2) numElementos = atoi(argv[1]); 

    printf("Creando lista vacia: %d\n", creaVacia(&miLista));

    printf("Se crea una lista de %d elementos\n", numElementos);
    
    p = primero(&miLista);
    
    for (i = 0; i < numElementos; i++) {
    	codigoError = inserta(rand()%100000, p, &miLista);
    	p = siguiente(p, &miLista);
    }
    
    imprime(&miLista);
    radixSort(&miLista, 10, 5);
    printf("\nLista Ordenada!\n");
    imprime(&miLista);
    anula(&miLista);
    
    destruye(&miLista); 
    return 0;
}

