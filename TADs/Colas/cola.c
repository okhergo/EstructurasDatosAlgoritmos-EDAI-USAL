#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

int colaCreaVacia(Cola *c){
    if(c == NULL) return -1;
    else {
    	c->frente = c->fondo = NULL;
    	return 0;
	}
}

int colaVacia(Cola *c){
    if(c == NULL) return -1;
    else if(c->frente == NULL && c->fondo == NULL) return 1;
    else return 0;
}

int colaInserta(Cola *c,tipoElemento elemento){
	tipoCelda *nuevo;
	
    if(c == NULL){
    	fprintf(stderr,"Fallo precondicion cola no existente!\n");
    	return -1;
	}
    else if(NULL == (celda = malloc(sizeof(tipoCelda)))){
    	fprintf(stderr,"Fallo reserva de memoria!\n");
    	return -2;
	} else {
    	nuevo->elemento = elemento;
    	nuevo->sig = NULL;
    	if(c->fondo == NULL) c->frente = c->fondo = nuevo;
    	else c->fondo = c->fondo->sig = nuevo;
    	return 0;
	}
}

tipoElemento colaSuprime(Cola *c){
    tipoCelda *aBorrar;
    tipoElemento aux;
    
    if(c == NULL){
    	fprintf(stderr,"Fallo precondicion cola no existente!\n");
    	return -1;
	} else if(c->frente == NULL){
		fprintf(stderr,"Fallo precondicion cola vacia!\n");
    	return -2;
	} else {
		aBorrar = c->frente;
		aux = aBorrar->elemento;
		c->frente = aBorrar->sig;
		if(aBorrar == c->fondo) c->fondo = c->frente;
		free(aBorrar);
		return aux;
	}
}
