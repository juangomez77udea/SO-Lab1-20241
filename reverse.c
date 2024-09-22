#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}

int main(int argc, char *argv[]) {
    FILE *input = NULL;
    FILE *output = NULL;
    char *buffer = NULL;
    long file_size;

    // Verificación de que se pasen exactamente 2 argumentos
    if (argc != 3) {
        print_error("usage: reverse <input> <output>");
        return 1;
    }

    // Verificar si los archivos de entrada y salida son iguales
    if (strcmp(argv[1], argv[2]) == 0) {
        print_error("reverse: input and output file must differ");
        return 1;  // Retorna código de error 1
    }

    // Abrir archivo de entrada
    input = fopen(argv[1], "r");
    if (input == NULL) {
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    // Abrir archivo de salida
    output = fopen(argv[2], "w");
    if (output == NULL) {
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
        fclose(input);
        return 1;
    }

    // Determinar el tamaño del archivo de entrada
    fseek(input, 0, SEEK_END);
    file_size = ftell(input);
    rewind(input);

    // Reservar memoria para el contenido del archivo
    buffer = (char *)malloc(file_size * sizeof(char));
    if (buffer == NULL) {
        print_error("malloc failed");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Leer el archivo completo en el buffer
    fread(buffer, sizeof(char), file_size, input);

    // Escribir el contenido invertido en el archivo de salida
    for (long i = file_size - 1; i >= 0; i--) {
        fputc(buffer[i], output);
    }

    // Liberar memoria y cerrar archivos
    free(buffer);
    fclose(input);
    fclose(output);

    return 0;
}
