//LIBRERIAS
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h> //complemento para TCP
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h> //para mover cadenas

#define MAXA 300
#define MAXB 915

//Variables globales
int SERVER_PORT=0;

int main(int argc, char *argv[]){ //obtendremos el servidor
  if(argc < 2){
    printf("Falta el puerto, ingrese el puerto:");
    char Puerto[4];
    gets(Puerto);
    //atoi para convertir de char a entero
    SERVER_PORT = atoi(Puerto);
  }else{
    SERVER_PORT = atoi(argv[1]);
  }
  //printf("Puerto: %d\n",SERVER_PORT);

  int FD,FD2,largoCliente;
  int socketServidor;

  struct sockaddr_in servidor;
  struct sockaddr_in cliente;

  //Configuración del servidor
  servidor.sin_family = AF_INET; //Declaramos la naturaleza del Socket ( TCP/IP )
  servidor.sin_port = htons(SERVER_PORT); //Declaramos el puerto del servidor
  servidor.sin_addr.s_addr = INADDR_ANY; //Para que cualquier cliente pueda conectarse
  bzero(&(servidor.sin_zero),8); //Se rellena con 0 el arreglo
  
  //sock_stream para que ocupe el protocolo de transporte TCP
  socketServidor = socket(AF_INET, SOCK_STREAM,0);
  FD = socketServidor;
  if(socketServidor < 0){
    perror("(Error) No se pudo abrir el socket");
    return -1;
  }else{
    perror("(Exito) al abrir el socket");
  }
  
  //Creamos el servidor Bind
  if(bind(socketServidor,(struct sockaddr*)&servidor, sizeof(struct sockaddr)) == -1){
    perror("Hubo un error con el BIND");
    return -1;
  }else{
    printf("Bind asignado correctamente\n");
  }
  if(listen(socketServidor,5) == -1){
    perror("Hubo un error en escucha");
    return -1;
  }
  //aceptamos conexiones
  printf("En escucha...\n");
  while(1){
    largoCliente = sizeof(struct sockaddr_in);
    if((FD2 = accept(socketServidor,(struct sockaddr*)&cliente,&largoCliente)) == -1){
      perror("(Error) en las conexiones");
      return -1;
    }
    //puts("-->En espera...");
    send(FD2,"BIENVENIDO AL SERVIDOR\n",MAXB,0);
    char NUM1[MAXA],NUM2[MAXA];
    int Bytes=0;
    Bytes = recv(FD2,NUM1,MAXB,0);
    NUM1[Bytes] = '\0';
    send(FD2,NUM1,MAXA,0);
    Bytes = recv(FD2,NUM2,MAXB,0);
    NUM2[Bytes] = '\0';
    send(FD2,NUM2,MAXB,0);

    //Algoritmo de suma
    char aa[202],bb[202];
    int a[202],b[202],c[203];
    int i,j,k,ki;
    strcpy(aa,NUM1);
    strcpy(bb,NUM2);
    int m,n,len;
    m=strlen(aa);
    n=strlen(bb);
    len = ( m > n)? m:n ;
    for ( i=0; i<m; i++)
      a[i]=aa[i]-'0'; //i=m;
    for ( j=0; j<n; j++)
      b[j]=bb[j]-'0'; //j=n;
    for( i=m-1,j=n-1,k=len-1; i>=0 && j>=0; i--,j--,k--){
      c[k] = a[i] + b[j];
    }
    for( ;i>=0; i--,k--)
      c[k] = a[i];
    for( ;j>=0; j--,k--)
      c [k] = b [j]; // Alto guardado
         // Cada décimo
    for( k=len-1; k>0; k--){
      if( c[k] >9 ){
	c[k] = c[k]%10;
        c[k-1] += 1;
      }
    }
    char resultado[MAXA];
    for( k=0; k<len; k++)
      sprintf(&resultado[strlen(resultado)],"%d",c[k]);
    send(FD2,resultado,MAXB,0);


    close(FD2);
  }
  close(socketServidor);
  
  
  return 0;
} 
