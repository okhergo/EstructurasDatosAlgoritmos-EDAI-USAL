#include <stdio.h>
#include <stdlib.h>
#include "Listas/lista.h"
#include "radixSort.h"
#include <time.h>

long int contadorInterno, contadorExterno;

int main(int argc, char *argv[]){
	double tiempoInicial , tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC ;
	Lista miLista;
	tipoPosicion p;
	double tiempo;

	int rango = 100000, n = 10000, i, repeticiones = 0;
        
 	FILE *f;  
 	
	if (argc != 2) {
		printf("\n Uso: ./medirTyContarV <nombre fichero resultados>\n\n");
		return -1;
	}

	f = fopen(argv[1], "w+");
	fprintf(f,"n;tiempoMedio;Externo;Interno\n");


	for (n = 5000; n <= 15000; n = 5000+n){
		repeticiones = contadorInterno = contadorExterno=0;

		tiempoInicial = tiempoFinal= (double)clock();
		
		while ((tiempoFinal - tiempoInicial < tiempoMinimo) || (repeticiones < 5)){
			creaVacia(&miLista);	
			p = primero(&miLista);
			for (i = 0; i < n; i++) { 
				inserta(rand() % rango, p, &miLista);
				p = siguiente(p, &miLista);
			}
			radixSort(&miLista, 10, 5);
			anula(&miLista);
			destruye(&miLista);
	
			repeticiones++;
			tiempoFinal = (double) clock();
		}

		tiempo = (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC /repeticiones;
		printf("\n %d \t %e \t %ld \t %ld", n, tiempo, contadorExterno/repeticiones, contadorInterno/repeticiones);
		fprintf(f,"\n %d \t %e \t %ld \t %ld", n, tiempo, contadorExterno/repeticiones, contadorInterno/repeticiones);
	}
	
	fclose(f);
	return 0;
}


