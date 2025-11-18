#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};
enum Mes{ENERO, FEBERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

struct Persona{
    char nombre[30];
    // apellido
    // mes de nacimiento
    // dia de nacimiento
    // tipo contacto
    // numero de telefono
    // tipo de numero
};

typedef struct Persona Contacto;

typedef struct Agenda{
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos; //Lleva la cuenta de cuantos contactos están en la agenda
} Agenda;


void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto);
void leer_contacto(Contacto *c);
void cargar_contactos(char *filename);
void guardar_contactos(char *filename);

#endif // __AGENDA_H_

#ifndef __AGENDA_H__
#define __AGENDA_H__
#include<stdio.h>
#define MAX_CONTACTOS 10

struct Contacto{
    char nombre[15];
    char apellido[15];
    char oficio[20];
    char telefono[11];
    char tipo[11];
    char correo[50];
    char cumple[20];
};

typedef struct Contacto Contacto;

void leer_contacto(Contacto *c); 
void leer_contacto_archivo(Contacto *c, FILE *archivo); 
void imprimir_contacto(Contacto c);
void buscar_contacto(Contacto *c, int n);
void ordenar_contactos(Contacto *c, int n);

#endif //__AGENDA_H__ 
