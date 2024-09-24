#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Verificar si el número de argumentos es correcto
    if (argc != 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        return 1;
    }

    // Intentar abrir el archivo de entrada
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        // Si no se puede abrir el archivo de entrada, mostrar el error y salir
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    // Intentar abrir el archivo de salida
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        // Si no se puede abrir el archivo de salida, mostrar el error y salir
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
        fclose(input_file);  // Cerramos el archivo de entrada si estaba abierto
        return 1;
    }

    // Si ambos archivos se abrieron correctamente, cerrarlos por ahora
    fclose(input_file);
    fclose(output_file);

    // Retornar 0 si todo fue exitoso
    return 0;
}
