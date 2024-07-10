#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <diretorio>\n", argv[0]);
        return 1;
    }

    char *dir_name = argv[1];

    // Remover o diretório
    if (rmdir(dir_name) == -1) {
        perror("Erro ao remover diretório");
        return 1;
    }

    printf("Diretório '%s' removido com sucesso.\n", dir_name);

    return 0;
}
