#include <stdio.h>

int main(int argc, char *argv[]) {
    // Verificar si hay demasiados argumentos
    if (argc != 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        return 1;
    }

    // Si todo está bien, retorna 0 (por ahora)
    return 0;
}
