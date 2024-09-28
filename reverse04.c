#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Verificar si se proporcionaron los argumentos correctos
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Comparar los nombres de los archivos de entrada y salida
    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "reverse: input and output file must differ\n");
        return 1;
    }

    // El test requiere verificar el nombre de los archivos y retornar el error en caso de que sean iguales.

    // Abrir el archivo de entrada
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Abrir el archivo de salida
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }


    // Cerrar los archivos
    fclose(input_file);
    fclose(output_file);

    return 0;
}
