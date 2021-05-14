
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int arrayint[5];
	
	int i;
	for(i=0;i<5;i++){
		arrayint[i]=i;	
	}
	
	
	int *punteroint;
	
	punteroint = arrayint;
	
	printf("\nEL valor del primer elemento del arrayint es: %d\n", arrayint[0]);
	printf("EL valor del primer elemento del punteroint es: %d\n", *punteroint);
	
	
	int *punteroint2;
	punteroint2 = &arrayint[0];
	
	printf("EL valor del primer elemento del  punteroint2 es: %d\n", *punteroint2);
	printf("EL valor del quinto elemento del arrayint es: %d\n", arrayint[4]);
	
	printf("EL valor del quinto elemento del punteroint es: %d\n", *punteroint +4);
	printf("EL valor del quinto elemento del punteroint2 es: %d\n\n", *punteroint2 +4);
	
	
	for(i=0;i<5;i++){
		punteroint[i]=i;
		printf("EL valor del puntero *punteroint %d es: %d\n", i, punteroint[i]);
	}
	
	for(i=0;i<5;i++){
		punteroint2[i]=i;
		printf("EL valor del puntero *punteroint2 %d es: %d\n", i, punteroint2[i]);
	}
	
	return 0;
}