struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[20];
};

int menu();
void registrarLibros(struct Libro libros[], int i);
void mostrarLibros(struct Libro libros[]);
void buscarLibroId(struct Libro libros[], int id);
void buscarLibroTitulo(struct Libro libros[], char titulo[]);
void eliminarLibro(struct Libro libros[], int id);
void actualizarEstado(struct Libro libros[], int id);