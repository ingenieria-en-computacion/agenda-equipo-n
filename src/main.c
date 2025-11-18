#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main(int argc, char *argv[]){
    FILE *archivo;
    Contacto agenda[MAX_CONTACTOS];
    int num = 0;
    char opcion;

    if(argc < 2){
        printf("Uso: %s archivo.txt\n", argv[0]);
        return 1;
    }

    archivo = fopen(argv[1], "r");
    if(archivo){
        while(num < MAX_CONTACTOS){
            leer_contacto_archivo(&agenda[num], archivo);
            if(agenda[num].nombre[0] == '\0') break;
            num++;
        }
        fclose(archivo);
    }

    printf("Contactos cargados: %d\n", num);

    do{
        printf("\nMenu:\n");
        printf("a - Agregar contacto\n");
        printf("b - Buscar por nombre\n");
        printf("c - Buscar por telefono\n");
        printf("d - Mostrar contactos ordenados\n");
        printf("s - Salir\n");
        printf("Opcion: ");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
                num = agregar_contacto(agenda, num);
                break;
            case 'b':
                buscar_contacto_nombre(agenda, num);
                break;
            case 'c':
                buscar_contacto_telefono(agenda, num);
                break;
            case 'd':
                ordenar_contactos(agenda, num);
                for(int i = 0; i < num; i++)
                    imprimir_contacto(agenda[i]);
                break;
            case 's':
                printf("Guardando cambios...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while(opcion != 's');

    archivo = fopen(argv[1], "w");
    for(int i = 0; i < num; i++){
        fprintf(archivo, "%s %s %d %d %s %s\n",
            agenda[i].nombre, agenda[i].apellido,
            agenda[i].dia, agenda[i].mes,
            agenda[i].telefono, agenda[i].tipo);
    }
    fclose(archivo);

    printf("Datos guardados.\n");
    return 0;
}