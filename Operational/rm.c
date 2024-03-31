#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo1> [<arquivo2> ...]\n", argv[0]);
        return 1;
    }

    // Iterar sobre todos os argumentos (arquivos) fornecidos
    for (int i = 1; i < argc; i++) {
        // Remover o arquivo
        if (unlink(argv[i]) == -1) {
            perror("Erro ao remover arquivo");
            return 1;
        }
    }

    return 0;
}
