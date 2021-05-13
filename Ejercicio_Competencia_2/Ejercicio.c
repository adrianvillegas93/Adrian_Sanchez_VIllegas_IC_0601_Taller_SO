
#include <stdio.h>
#include <stdlib.h>



int main(){



	int x = 10;
	int *p;
	
	int y = 20;
	int *puntero;
	
	p = &x;
		
	printf("El valor de x es: %d. \nEl valor del puntero *p es: %d. \n",x,*p);
	
	p += 2;
	printf("El valor de x es: %d. \nEl valor del puntero *p es: %d. \n",x,*p);
	
	
	
	puntero = &y;
		
	printf("El valor de y es: %d. \nEl valor del puntero *puntero es: %d. \n",y,*puntero);
	


}