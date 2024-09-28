#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
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

    // Leer las líneas del archivo de entrada
    char *lines[MAX_LINES];
    char buffer[MAX_LENGTH];
    int count = 0;

    while (fgets(buffer, MAX_LENGTH, input_file) != NULL && count < MAX_LINES) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Eliminar el salto de línea
        }
        lines[count] = strdup(buffer); // Guardar la línea
        if (lines[count] == NULL) {
            fprintf(stderr, "Error: fallo en la asignación de memoria\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
        count++;
    }

    // Escribir las líneas en orden inverso en el archivo de salida
    for (int i = count - 1; i >= 0; i--) {
        fprintf(output_file, "%s\n", lines[i]);
        free(lines[i]);  // Liberar la memoria
    }

    // Cerrar los archivos
    fclose(input_file);
    fclose(output_file);

    return 0;  // Terminar exitosamente
}
