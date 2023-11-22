#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"

int creaVacia(Lista *l){
    if (l == NULL) return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda)))) return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}

int anula(Lista *l){
	l->ultimo = NULL;
	l->raiz = NULL;
	return 0;
}

int vacia(Lista *l){
    if (l == NULL || l->raiz == NULL) return -1;
    else if (l->raiz->sig == NULL) return 1;
    else return 0;
}



int inserta(tipoElemento x, tipoPosicion p, Lista *l){
    tipoCelda *nuevo;
    
    if (l == NULL){
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return -1;
    } else if (l->raiz == NULL){
        fprintf(stderr,"Fallo precondicion nodo ficticio no existente!\n");
        return -2;
    } else if (p == NULL){
        fprintf(stderr,"Fallo precondicion posicion no valida!\n");
        return -3;
    } else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) {
        fprintf(stderr,"Fallo reserva memoria!\n");
        return -4;
    } else {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo) l->ultimo = nuevo;
        return 0;
    }
}

int suprime (tipoPosicion p, Lista *l){
	tipoCelda *aBorrar;
	
	if (l == NULL){
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return -1;
    } else if (l->raiz == NULL){
        fprintf(stderr,"Fallo precondicion nodo ficticio no existente!\n");
        return -2;
    } else if (p == NULL){
        fprintf(stderr,"Fallo precondicion posicion no valida!\n");
        return -3;
    } else {
    	aBorrar = p->sig;
		p->sig = aBorrar->sig;
		free(aBorrar);
		return 0;
	}
}

tipoPosicion localiza (tipoElemento x, Lista *l){
	tipoPosicion p;
	
	if (l == NULL){
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return NULL;
    } else if (l->raiz == NULL){
        fprintf(stderr,"Fallo precondicion nodo ficticio no existente!\n");
        return NULL;
    } else {
		p = l->raiz;
		while (p->sig != NULL){
			if (p->sig->elemento == x) return p->sig;
			else p = p->sig;
		}
		return p->sig;
	}
}

tipoElemento recupera(tipoPosicion p, Lista *l){
	if (l == NULL){
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return -1;
    } else if (l->raiz == NULL){
        fprintf(stderr,"Fallo precondicion nodo ficticio no existente!\n");
        return -2;
    } else if (p == NULL){
        fprintf(stderr,"Fallo precondicion posicion no valida!\n");
        return -3;
    } else return p->sig->elemento;
}



tipoPosicion primero(Lista *l){
	if (l == NULL) {
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return NULL;
    } else if (l->raiz == NULL){
        fprintf(stderr,"Fallo precondicion lista no inicializada!\n");
        return NULL;
    } else return l->raiz; 
}

tipoPosicion siguiente (tipoPosicion p, Lista *l){
    if (l == NULL || l->raiz == NULL || p == NULL) return NULL;
    else if (p == fin(l)) return l->ultimo;
    else return p->sig;
}

tipoPosicion anterior(tipoPosicion p, Lista *l){
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) return NULL;
    else if (p == l->raiz) return l->raiz;
    else {
        anterior = l->raiz;
        while (anterior->sig != p) anterior = anterior->sig;
        return anterior;
    }
}

tipoPosicion fin(Lista *l){
    if (l == NULL) {
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return NULL;
    } else if (l->ultimo == NULL){
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return NULL;
    } else return l->ultimo;
}



void imprime(Lista *l){
	tipoCelda *aImprimir;
	
	if (l == NULL || l->raiz == NULL) return;
	else {
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf(" %d ", aImprimir->elemento);
            aImprimir = aImprimir->sig;
        }
	}
}

int destruye(Lista *l){
    if (l == NULL || l->raiz == NULL) return -1;
    else if (l->raiz->sig != NULL) return -2;
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
		return 0;
	}
}

int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb){
	tipoCelda *aux;
	
	if (la == NULL || lb == NULL){
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return -1;
	} else if (la->raiz == NULL || lb->raiz == NULL){
        fprintf(stderr,"Fallo precondicion nodo ficticio no existente!\n");
        return -2;
	} else if (p == NULL || q == NULL){
        fprintf(stderr,"Fallo precondicion posicion no valida!\n");
        return -3;
	} else {
		aux = p->sig;
		p->sig = aux->sig;
		if(p->sig == NULL) la->ultimo = p;
		aux->sig = q->sig;
		q->sig = aux;
		if(q == lb->ultimo) lb->ultimo = aux;
		return 0;
	}
}

int concatenarListas(Lista *la, Lista *lb){
	tipoPosicion p;
	
	if (la == NULL || lb == NULL){
        fprintf(stderr,"Fallo precondicion lista no existente!\n");
        return -1;
	} else if (la->raiz == NULL || lb->raiz == NULL){
        fprintf(stderr,"Fallo precondicion nodo ficticio no existente!\n");
        return -2;
	} else {
		/*
		la->ultimo->sig = lb->raiz->sig;
    	la->ultimo = lb->ultimo;
    	anula(lb);
    	return 0;
    	*/
    	p = primero(lb);
    	while (vacia(lb) == 0) traspasarNodo(p, lb, fin(la), la);
		return 0;
	}
}
