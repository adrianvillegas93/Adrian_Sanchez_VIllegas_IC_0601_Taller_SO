#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int tiempo;
	int terminado;
}Proceso;

int main(){
	int numProceso,procesoT;
	printf("Ingresa el numero de procesos: ");
	scanf("%i",&numProceso);
	if(numProceso%2==1){
		Proceso procesos[numProceso+1];
		procesos[numProceso].tiempo=0;
	}	

	Proceso procesos[numProceso];
	for(int i=0;i<numProceso;i++){
		printf("Ingresa el tiempo de ejecucion del proceso %i (milisegundos): ",i+1);
		fflush(stdin);
		scanf("%i",&procesoT);
		procesos[i].tiempo=procesoT;
		if(procesoT=!0){
			procesos[i].terminado=1;
		}else{
			procesos[i].terminado=0;
		}
	}
	
	
	int valorte;
	printf("Ingresa el valor del tiempo equitativo: ");
	scanf("%i",&valorte);
	fflush(stdin);
	
	//Oredenamos el arreglo (de mayor a menor).
	Proceso valor;
	for(int i=0 ; i<numProceso ; i++){
		for(int j=0 ; j<numProceso-i ; j++){
			if(procesos[j].tiempo < procesos[j+1].tiempo){
				valor=procesos[j];
				procesos[j]=procesos[j+1];
				procesos[j+1]=valor;
				
			}
		}
	}
	
	printf("\nOrdenando los procesos de mayor a menor (su nuevo orden renombra el proceso): \n");
	for(int k=0;k<numProceso;k++){
		printf("%i, ",procesos[k].tiempo);
	}
	printf("\n");
	int procesosR=numProceso,aux=0,vueltas=0;
	while(procesosR!=0){
	for(int i=0;i<numProceso;i++){
		if(procesos[i].terminado==1){
			if(procesos[i].tiempo<=valorte){
			procesos[i].tiempo=0;
			procesos[i].terminado=0;
			printf("Proceso %i termino su ejecucion\n",i+1);
			}else{
				procesos[i].tiempo=procesos[i].tiempo-valorte;
			}
		}	
	}	
		
	vueltas++;
	printf("\nvuelta %i\n\n",vueltas);
		
	aux=0;
	for(int i=0 ; i<numProceso ; i++){
		if(procesos[i].terminado==0){
		aux++;
		}
	}
	if(aux==numProceso){
		procesosR=0;
	}
	
	}
	printf("Vueltas totales: %i\n", vueltas);
	return 0;
}
