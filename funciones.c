#include <stdio.h>
#include <string.h>
#include "funciones.h"
int menu() {
    int opcion;
    printf("\n--- Menu Biblioteca ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar todos los libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por Titulo\n");
    printf("5. Eliminar libro\n");
    printf("6. Actualizar estado de libro\n");
    printf("7. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void registrarLibros(struct Libro libros[], int i) {
    if (i >= 20) {
        printf("\nNo se pueden registrar más libros. Límite alcanzado.\n");
        return;
    }

    printf("\nIngrese el ID del libro (único): ");
    int id;
    scanf("%d", &id);

    // Verificar unicidad del ID
    for (int j = 0; j < i; j++) {
        if (libros[j].id == id) {
            printf("\nError: ID ya existente. Intente nuevamente.\n");
            return;
        }
    }

    // Pedir título del libro
    printf("Ingrese el título: ");
    getchar(); // Consumir el salto de línea
    char titulo[100];
    fgets(titulo, 100, stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    // Verificar unicidad del título
    for (int j = 0; j < i; j++) {
        if (strcmp(libros[j].titulo, titulo) == 0) {
            printf("\nError: Título ya existente. Intente nuevamente.\n");
            return;
        }
    }

    libros[i].id = id;
    strcpy(libros[i].titulo, titulo);

    printf("Ingrese el autor: ");
    fgets(libros[i].autor, 50, stdin);
    libros[i].autor[strcspn(libros[i].autor, "\n")] = '\0';

    printf("Ingrese el año de publicación: ");
    scanf("%d", &libros[i].anio);

    strcpy(libros[i].estado, "Disponible");

    printf("\nLibro registrado exitosamente!\n");
}
void mostrarLibros(struct Libro libros[]) {
    printf("\n%-5s %-30s %-20s %-10s %-12s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    printf("----------------------------------------------------------------------------\n");

    for (int j = 0; j < 20; j++) {
        if (libros[j].id != 0) {
            printf("%-5d %-30s %-20s %-10d %-12s\n", libros[j].id, libros[j].titulo, libros[j].autor, libros[j].anio, libros[j].estado);
        }
    }
}

void buscarLibroId(struct Libro libros[], int id) {
    for (int j = 0; j < 20; j++) {
        if (libros[j].id == id) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n", libros[j].id, libros[j].titulo, libros[j].autor, libros[j].anio, libros[j].estado);
            return;
        }
    }
    printf("\nLibro con ID %d no encontrado.\n", id);
}

void buscarLibroTitulo(struct Libro libros[], char titulo[]) {
    for (int j = 0; j < 20; j++) {
        if (strcmp(libros[j].titulo, titulo) == 0) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n", libros[j].id, libros[j].titulo, libros[j].autor, libros[j].anio, libros[j].estado);
            return;
        }
    }
    printf("\nLibro con titulo '%s' no encontrado.\n", titulo);
}

void actualizarEstado(struct Libro libros[], int id) {
    for (int j = 0; j < 20; j++) {
        if (libros[j].id == id) {
            if (strcmp(libros[j].estado, "Disponible") == 0) {
                strcpy(libros[j].estado, "Prestado");
            } else {
                strcpy(libros[j].estado, "Disponible");
            }
            printf("\nEstado del libro con ID %d actualizado a %s.\n", id, libros[j].estado);
            return;
        }
    }
    printf("\nLibro con ID %d no encontrado.\n", id);
}
void eliminarLibro(struct Libro libros[], int id) {
    for (int j = 0; j < 20; j++) {
        if (libros[j].id == id) {
            libros[j].id = 0; // Marcar como eliminado
            printf("\nLibro con ID %d eliminado exitosamente.\n", id);
            return;
        }
    }
    printf("\nLibro con ID %d no encontrado.\n", id);
}