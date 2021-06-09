#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAL 40


//CREAMOS LAS ESTRUCTURAS 
typedef struct elemento{
  char palabra[PAL];
  //char *palabra;
  struct elemento *siguiente;
}Lista;

typedef struct{
  char palabra[PAL];
}String;

//FUNCIONES
Lista *crear_list(Lista *list);
Lista *agregar_elemento(Lista *list, char *palabra);
void ordenamiento_palabras(Lista *list);

//VARIABLES GLOBALES
String array_ordenado[1000];
int h = 0;

//FUNCION PRINCIPAL
int main(int argc, char *argv[]){
  Lista *list_enlazada = crear_list(list_enlazada);
  char palabra[PAL];
  Lista *aux;

  FILE *f1,*f2;
  f1 = fopen(argv[1],"r");
  if(f1 == NULL){
    puts("No existe el fichero");
    fclose(f1);
  }else{
    puts("Fichero encontrado");
	  //feof retorna el final del archivo
    while(!feof(f1)){
      fscanf(f1,"%s",palabra);
      if(strcmp(palabra,"") != 0){
	list_enlazada = agregar_elemento(list_enlazada,palabra);
      
   		}
		//memset para que corrija a "feof" y no imprima 2 veces la ultima palabra
		memset(palabra,0,PAL);
	}
  }
    //auxi = list_enlazada;
	ordenamiento_palabras(list_enlazada);
    fclose(f1);
    f2 = fopen(argv[2],"w");
	printf("\tSe creo el archivo llamado: %s\n",argv[2]);
	for(int i=0; i<=h; i++){
		strcpy(palabra,array_ordenado[i].palabra);	
		if(strcmp(palabra,"") != 0){
			fprintf(f2, "%s\n", palabra);

		}
	}
	printf("\tEl archivo \"%s\" fue ordenado correctamente\n",argv[2]);
	fclose(f2);
  }
/*
  for(int i=0; i<5; i++){
    gets(palabra);
    list_enlazada = agregar_elemento(list_enlazada,palabra);
  }
  list_enlazada = agregar_elemento(list_enlazada,"adrian");
  list_enlazada = agregar_elemento(list_enlazada,"sanchez");
*/
	
//FUNCIONES CREADAS--

Lista *crear_list(Lista *list){
  list = NULL;
  return list;
};

Lista *agregar_elemento(Lista *list, char *palabra){
  Lista *nuevo_elemento, *aux;
  nuevo_elemento = (Lista*)malloc(sizeof(Lista));
  strcpy(nuevo_elemento->palabra,palabra);
  //nuevo_elemento->palabra = palabra;
  nuevo_elemento->siguiente = NULL;
  
  if(list == NULL){
    list = nuevo_elemento;
  }else{
    aux = list;
    while(aux->siguiente != NULL){
      aux = aux->siguiente;
    }
    aux->siguiente = nuevo_elemento;
  }

  return list;
};

	
void ordenamiento_palabras(Lista *list){
  String array[1000];
  //int h=0;
   while(list->siguiente != NULL){
    printf("Elemento de la lista [ %s ]\n",list->palabra);
    strcpy(array[h].palabra,list->palabra); //Se copia lo que contiene la lista y se pasa al arreglo
    list = list->siguiente;
    h++;
  }

	
	
	strcpy(array[h].palabra,list->palabra);
	char vartemp[PAL];
	//MÉTODO DE ORDENAMIENTO DE BURBUJA
	for(int i=0; i<h; i++){
		for(int j=0; j<h; j++){
			if(strcmp(array[j].palabra,array[j+1].palabra) >= 0){
				strcpy(vartemp, array[j].palabra);
				strcpy(array[j].palabra,array[j+1].palabra);
				strcpy(array[j+1].palabra,vartemp);
			}
			
		}
		
	}
	
	for(int i=0; i<=h; i++){
		printf("\tLos elementos ordenados quedan de la siguiente manera: [ %s ]\n",array[i].palabra);
		strcpy(array_ordenado[i].palabra,array[i].palabra);
	}
	
};






