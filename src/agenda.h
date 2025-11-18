#ifndef __AGENDA_H__
#define __AGENDA_H__
#include <stdio.h>

#define MAX_CONTACTOS 100

typedef struct {
    char nombre[20];
    char apellido[20];
    int dia;
    int mes;
    char telefono[15];
    char tipo[15];
} Contacto;

void leer_contacto(Contacto *c);
void leer_contacto_archivo(Contacto *c, FILE *archivo);
void imprimir_contacto(Contacto c);
void buscar_contacto_nombre(Contacto *c, int n);
void buscar_contacto_telefono(Contacto *c, int n);
void ordenar_contactos(Contacto *c, int n);
int agregar_contacto(Contacto *agenda, int num);

#endif
