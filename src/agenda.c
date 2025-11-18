#include "agenda.h"
#include <stdio.h>
#include <string.h>

void leer_contacto(Contacto *c){
    printf("Nombre: ");
    scanf("%s", c->nombre);

    printf("Apellido: ");
    scanf("%s", c->apellido);

    printf("Dia de nacimiento: ");
    scanf("%d", &c->dia);

    printf("Mes de nacimiento: ");
    scanf("%d", &c->mes);

    printf("Telefono: ");
    scanf("%s", c->telefono);

    printf("Tipo de telefono: ");
    scanf("%s", c->tipo);
}

void leer_contacto_archivo(Contacto *c, FILE *archivo){
    if(fscanf(archivo, "%s %s %d %d %s %s",
        c->nombre, c->apellido, &c->dia, &c->mes,
        c->telefono, c->tipo) != 6)
    {
        c->nombre[0] = '\0';
        return;
    }
}

void imprimir_contacto(Contacto c){
    printf("\n--- CONTACTO ---\n");
    printf("Nombre: %s %s\n", c.nombre, c.apellido);
    printf("Nacimiento: %02d/%02d\n", c.dia, c.mes);
    printf("Telefono: %s (%s)\n", c.telefono, c.tipo);
}

void buscar_contacto_nombre(Contacto *c, int n){
    char buscado[20];
    printf("Nombre a buscar: ");
    scanf("%s", buscado);

    for(int i = 0; i < n; i++){
        if(strcmp(c[i].nombre, buscado) == 0){
            imprimir_contacto(c[i]);
            return;
        }
    }
    printf("No encontrado.\n");
}

void buscar_contacto_telefono(Contacto *c, int n){
    char buscado[20];
    printf("Telefono a buscar: ");
    scanf("%s", buscado);

    for(int i = 0; i < n; i++){
        if(strcmp(c[i].telefono, buscado) == 0){
            imprimir_contacto(c[i]);
            return;
        }
    }
    printf("No encontrado.\n");
}

void ordenar_contactos(Contacto *c, int n){
    Contacto temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(strcmp(c[j].apellido, c[j+1].apellido) > 0){
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
}

int agregar_contacto(Contacto *agenda, int num){
    if(num >= MAX_CONTACTOS){
        printf("Agenda llena.\n");
        return num;
    }

    printf("\n--- Agregar contacto ---\n");
    leer_contacto(&agenda[num]);
    printf("Contacto agregado.\n");
    return num + 1;
}
