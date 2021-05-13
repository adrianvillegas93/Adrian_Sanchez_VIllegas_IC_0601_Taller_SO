
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int arrayint [5];
	
	int i;
	for(i = 0; i <= 5, i++){
		arrayint [i];	
	}
	
	
	int *punteroint;
	
	punteroint = &arrayint;
	
	printf("EL valor del arrayint es: %d", arrayint);
	printf("EL valor del punteroint es: %d", *punteroint);
	
	
	int *punteroint2;
	punteroint2 = &arrayint[0];
	
	printf("EL valor del punteroint2 es: %d", *punteroint2);
	printf("EL valor del arrayint2 en la posicion 0 es: %d", arrayint[0]);
	
	
	punteroint = &arrayint[5];
	
	printf("EL valor del arrayint es: %d", arrayint[5]);
	
	
	int *ptr;
	ptr = &arrayint[0];
	ptr += 10;
	
	for(i = 0; i <= 10; i++){
		*ptr = 1;
		ptr++
	}
	
	
}