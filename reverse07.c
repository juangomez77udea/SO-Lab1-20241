#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 20 
#define MAX_LENGTH 20

int main() {
    char *lines[MAX_LINES];
    char buffer[MAX_LENGTH];
    int count = 0;

    // Leer las líneas de entrada
    while (fgets(buffer, MAX_LENGTH, stdin) != NULL && count < MAX_LINES) {
        // Detener si la línea está vacía (solo contiene \n)
        if (strcmp(buffer, "\n") == 0) {
            break;
        }

        // Eliminar el salto de línea al final de cada línea
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        lines[count] = strdup(buffer); // Guardar la línea sin el salto de línea
        if (lines[count] == NULL) {
            fprintf(stderr, "Error: fallo en la asignación de memoria\n");
            return 1;  // Retornar un código de error si falla
        }
        count++;
    }

    // Imprimir las líneas en orden inverso
    for (int i = count - 1; i >= 0; i--) {
        printf("%s\n", lines[i]);
        free(lines[i]);  // Liberar la memoria
    }

    return 0;  // Asegurar que el programa termine con éxito
}
