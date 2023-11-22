#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"

int pilaCreaVacia(Pila *p){
    if(p == NULL) return -1;
    *p = NULL;
    return 0;
}

int pilaVacia(Pila *p){
	if(p == NULL) return -1;
	else if(*p == NULL) return 1;
	else return 0;
}

int pilaInserta(Pila *p,tipoElemento elemento){
    tipoCelda *nuevo;
    
    if(p == NULL){
    	fprintf(stderr,"Fallo precondicion pila no existente!\n");
    	return -1;
	} else if(NULL == (nuevo = malloc(sizeof(tipoCelda)))){
		fprintf(stderr,"Fallo reserva de memoria!\n");
		return -2;
	} else {
		nuevo->elemento = elemento;
		nuevo->sig = NULL;
		if(*p == NULL) *p = nuevo;
		else {
			nuevo->sig = *p;
			*p = c;
		}
		return 0;
	}
}

tipoElemento pilaSuprime(Pila *p){
	tipoCelda *aBorrar;
	tipoElemento aux;
	
	if(p == NULL){
		
		return -1;
	} else if(*p == NULL){
		
		return -2;
	} else {
		aBorrar = *p;
		aux = aBorrar->aux;
		*p = (*p)->sig;
		free(aBorrar);
		return aux;
	}
}
