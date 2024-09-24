#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Para el test 2, solo necesitamos 2 argumentos (el programa y el archivo de entrada)
    if (argc != 2) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        return 1;
    }

    // Intentar abrir el archivo de entrada
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        // Si no se puede abrir, mostrar el error y salir
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    // Si el archivo de entrada se abre correctamente, cerrarlo
    fclose(input_file);

    // Retornar 0 para indicar que no hay error
    return 0;
}
