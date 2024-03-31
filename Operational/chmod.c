#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <permissões> <arquivo ou diretório>\n", argv[0]);
        return 1;
    }

    char *mode_str = argv[1];
    char *path = argv[2];

    // Converter a string de permissões para um número octal
    mode_t mode = strtol(mode_str, NULL, 8);

    // Alterar as permissões do arquivo ou diretório
    if (chmod(path, mode) == -1) {
        perror("Erro ao alterar as permissões");
        return 1;
    }

    printf("Permissões do arquivo ou diretório alteradas com sucesso.\n");

    return 0;
}
