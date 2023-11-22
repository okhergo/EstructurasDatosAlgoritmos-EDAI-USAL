# Proyecto para entrega Tipos Abstractos de Datos 2022

#Prueba Radix Sort
pruebaRadixSort: pruebaRadixSort.c Listas/lista.h Listas/lista.o radixSort.o
	gcc -g pruebaRadixSort.c radixSort.o Listas/lista.o -o pruebaRadixSort

#Analisis Radix Sort
medirTyContarV: medirTyContarV.c Listas/lista.h Listas/lista.o radixSort.o
	gcc -g medirTyContarV.c radixSort.o Listas/lista.o -o medirTyContarV

radixSort.o: radixSort.c radixSort.h Listas/lista.h 
	gcc -g -c radixSort.c 

listas/lista.o: Listas/lista.c Listas/lista.h 
	gcc -g -c Listas/lista.c -o Listas/lista.o 
	
limpiar:
	rm *.o Listas/lista.o	