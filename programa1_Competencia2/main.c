#include "scheduler.h"
#include <pthread.h>

//Funciones para crear los hilos
void h_reproducir_musica(void);
void h_abrir_youtube(void);
void h_escribir_texto_word(void);
void h_descargar_archivo(void);
void h_subiendo_archivo(void);
void h_compilando_programa(void);
void h_ejecutando_programa(void);
void h_usando_terminal(void);

//Acciones que van a realizar los hilos
void *reproducir_musica(void *pr);
void *abrir_youtube(void *pr);
void *escribir_texto_word(void *pr);
void *descargar_archivo(void *pr);
void *subiendo_archivo(void *pr);
void *compilando_programa(void *pr);
void *ejecutando_programa(void *pr);
void *usando_terminal(void *pr);

int main(int argc, char const *argv[]){
printf("\t...Se estan creando los procesos...\n\n");
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", h_reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", h_abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", h_escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", h_descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", h_subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", h_compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", h_ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", h_usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", h_usando_terminal, NO_ACTIVO);	//<--

	
	printf("\t...Se estan agreagando los procesos...\n\n");
	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	
	printf("\t...Se estan ejecutando los procesos...\n\n");
	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}

//Aqui se crean los hilos
void h_reproducir_musica(void){
	pthread_t accion1;
	pthread_create(&accion1,NULL,&reproducir_musica,"---Reproduciendo Musica---");
	pthread_join(accion1,NULL);
}

void h_abrir_youtube(void){
	pthread_t accion2;
	pthread_create(&accion2,NULL,&abrir_youtube,"---Usando Youtube---");
	pthread_join(accion2,NULL);
}

void h_escribir_texto_word(void){
	pthread_t accion3;
	pthread_create(&accion3,NULL,&escribir_texto_word,"---Escribiendo texto en Word---");
	pthread_join(accion3,NULL);
}

void h_descargar_archivo(void){
	pthread_t accion4;
	pthread_create(&accion4,NULL,&descargar_archivo,"---Descargando archivo---");
	pthread_join(accion4,NULL);
}

void h_subiendo_archivo(void){
	pthread_t accion5;
	pthread_create(&accion5,NULL,&subiendo_archivo,"---Subiendo archivo---");
	pthread_join(accion5,NULL);
}

void h_compilando_programa(void){
	pthread_t accion6;
	pthread_create(&accion6,NULL,&compilando_programa,"---Compilando programa---");
	pthread_join(accion6,NULL);
}

void h_ejecutando_programa(void){
	pthread_t accion7;
	pthread_create(&accion7,NULL,&ejecutando_programa,"---Ejecutando programa---");
	pthread_join(accion7,NULL);
}

void h_usando_terminal(void){
	pthread_t accion8;
	pthread_create(&accion8,NULL,&usando_terminal,"---Usando la terminal---");
	pthread_join(accion8,NULL);
}

//Acciones que realizaran los hilos

void *reproducir_musica(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Reproduciendo musica.mp3 ---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Reproduccion finalizada--");
	return NULL;
}

void *reproducir_musica(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Reproduciendo musica.mp3 ---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Reproduccion finalizada--");
	return NULL;
}

void *abrir_youtube(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Abriend youtube ---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Cerrando youtube--");
	return NULL;
}

void *escribir_texto_word(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Escribiendo texto en Word---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Cerrando Word--");
	return NULL;
}

void *descargar_archivo(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Descargando archivo---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Archivo descargado--");
	return NULL;
}

void *subiendo_archivo(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Subiendo archivo---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Archivo subido--");
	return NULL;
}

void *compilando_programa(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Compilando programa---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Programa compilado--");
	return NULL;
}

void *ejecutando_programa(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Ejecutando programa---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Programa ejecutado--");
	return NULL;
}

void *usando_terminal(void *pr){
	char *text= (char *) pr;
	printf("%s", text);
	int i = 0;
	printf("\t\t --Terminal abierto---\n\n");
	while(i<20){
			i++;
			
		}
	printf("\t\t --Cerrando terminal--");
	return NULL;
}
