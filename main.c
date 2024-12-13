#include <stdio.h>
#include "funciones.h"

int main() {
    struct Libro libros[20] = {0};
    int opc;
    int i = 0;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibros(libros, i);
                i++;
                break;
            case 2:
                mostrarLibros(libros);
                break;
            case 3: {
                int id;
                printf("Ingrese el ID del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroId(libros, id);
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el titulo del libro a buscar: ");
                getchar();
                fgets(titulo, 100, stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                buscarLibroTitulo(libros, titulo);
                break;
            }
            case 5: {
                int id;
                printf("Ingrese el ID del libro que desea eliminar: ");
                scanf("%d", &id);
                eliminarLibro(libros, id);
                break;
            }
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
                break;
        }
    } while (opc != 6);

    return 0;
}