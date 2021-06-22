//Librerias
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAXA 300
#define MAXB 915

int main(int argc, char *argv[]){
  int PORT;
  char *IP;
  system("clear");
  if(argc < 3){
    printf("-->C: (Error), parametro del ip/puerto vacio. \n\t\tIngresa la ip: ");
    char portc[4];
    gets(IP);
    printf("\t\tIngresa el puerto: ");
    gets(portc);//EJ: 192.168.16.121
    PORT = atoi(portc);
  }else{
    IP = argv[1];
    PORT = atoi(argv[2]);
  }

  int FD, nBytes;
  char BUF[MAXA]; //Buf para guardar todas kas variables que tenemos

  struct hostent *host; //Entidad que recibira informacion del host
  struct sockaddr_in servidor; //Informacion sobre la direccion del servidor

  if((host=gethostbyname(IP)) == NULL){ //Llamamos al host Y comparamos la salida para la deteccion de errores
    perror("-->C: Error de gethostname().");
    return -1;
  }
  if((FD = socket(AF_INET, SOCK_STREAM, 0)) == -1){//Creamos el socket y detectamos errores
    perror("-->C: Error en la creacion del socket."); //perror - muestra el mensaje correspondiente
    return -1;
  }
  
  //Asignamos los datos al servidor
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(PORT);
  servidor.sin_addr = *((struct in_addr *)host->h_addr);
  bzero(&(servidor.sin_zero),8);

  //Nos conectamos al servidro con "connect"
  if(connect(FD, (struct sockaddr *)&servidor, sizeof(struct sockaddr)) == -1){
    perror("-->C: Error al conectarse con el servidor.");
    return -1;
  }
  //Llamamos a recv, que es el que recibe los datos 
  nBytes = recv(FD,BUF,MAXB,0);
  BUF[nBytes] = '\0';
  printf("Mensaje: -->S: %s\n",BUF);
  char num1[MAXA], num2[MAXA], *num = (char *)malloc(MAXA);
  printf("-->C: Envia primer numero:");
  scanf("%s",num);
  strcpy(num1,num);
  send(FD,num1,MAXB,0);
  nBytes = recv(FD,BUF,MAXB,0);
  BUF[nBytes] = '\0';
  printf("-->S: Recibio: %s\n",BUF);
  printf("-->C: Envia segundo numero:");
  scanf("%s",num);
  strcpy(num2,num);
  send(FD,num2,MAXB,0);
  nBytes = recv(FD,BUF,MAXB,0);
  BUF[nBytes] = '\0';
  printf("-->S: Recibio: %s\n",BUF);
  nBytes = recv(FD,BUF,MAXB,0);
  BUF[nBytes] = '\0';
  printf("\n-->S: El resultado de la suma es: %s\n",BUF);
  close(FD);
}
