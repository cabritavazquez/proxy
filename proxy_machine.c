#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// ESTADOS
#define OCIOSO 0
#define FILTRANDO 1
#define BLOQUEO 2

// EVENTOS
#define NO_EVENTS 0
#define OFF 1
#define ON 2
#define FIN 3 
#define MENSAJE 4

// VARIABLES
int estado = OCIOSO;
int evento = NO_EVENTS;
int tacos = 0;
#define T 56
char buffer[T];

int espera_evento(){
	int leidos;
	leidos = read(0,buffer,T);
	buffer[leidos-1] = '\0';
	if ( strcmp(buffer,"on") == 0){
		return ON;
	}
	else if ( strcmp(buffer,"off") == 0){
		return OFF;
	}
	else if ( strcmp(buffer,"fin") == 0){
		printf("Fin de la maquina.\n");
		exit(1);
	}
	else{
		return MENSAJE;
	}
}

int main (){
	char *posicion;
	printf("WELCOME TO PROXY MACHINE.\n");
	printf("ESTADO -> OCIOSO.\n\n");
	while (1){
		printf("Introduzca comando [on/off/fin] o mensaje:\n");
		evento = espera_evento();
		switch(estado){
			case OCIOSO:
				printf("ESTADO -> OCIOSO.\n");
				switch(evento){
					case MENSAJE:
						evento = NO_EVENTS;
						// same state
					break;
					case ON:
						printf("Pasando a estado -> FILTRANDO.\n");
						evento = NO_EVENTS;
						estado = FILTRANDO;
					break;

				}
			break;
			case FILTRANDO:
				printf("ESTADO -> FILTRANDO.\n");
				switch(evento){
					case OFF:
						evento = NO_EVENTS;
						estado = OCIOSO;
					break;
					case MENSAJE:                                       
						posicion = strstr(buffer,"taco");
						while (posicion!=NULL){
							for(int i = 0; i < 4;i++){
								*(posicion+i) = '*';
							}
							tacos++;
							posicion = strstr(posicion, "taco");
						}

						printf("Mensaje: %s.\n",buffer);
						if (tacos >= 3){
								printf("Pasando a estado de bloqueo.\n");
								estado = BLOQUEO;
						}
						evento = NO_EVENTS;
					break;
				}		
			break;
			case BLOQUEO:
				printf("ESTADO -> BLOQUEO.\n");
				switch(evento){
					case OFF:
						estado = FILTRANDO;
						tacos = 0;
						evento = NO_EVENTS;
						printf("Pasando a estado de filtrado.\n");
					break;
					case MENSAJE:
						printf("usted ya no esta autorizado a leer contenido.\n");
						evento = NO_EVENTS;
					break;
				}		
			break;
		}
	}
	printf("FIN DE LA MAQUINA.\n");
	return 0;
}
