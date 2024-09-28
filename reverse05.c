#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    struct stat stat_in, stat_out;

    // Obtener información sobre los archivos de entrada y salida
    if (stat(argv[1], &stat_in) == -1) {
        perror("Error al acceder al archivo de entrada");
        return 1;
    }

    if (stat(argv[2], &stat_out) == -1) {
        perror("Error al acceder al archivo de salida");
        return 1;
    }

    // Verificar si los archivos de entrada y salida son el mismo
    if (stat_in.st_ino == stat_out.st_ino && stat_in.st_dev == stat_out.st_dev) {
        fprintf(stderr, "reverse: input and output file must differ\n");
        return 1;
    }

    // Abrir los archivos
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error al abrir el archivo de salida");
        fclose(input_file);
        return 1;
    }

    return 0;  // Terminar exitosamente
}
