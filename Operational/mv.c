#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <arquivo_origem1> [<arquivo_origem2> ...] <destino>\n", argv[0]);
        return 1;
    }

    // Verificar se o destino é um diretório
    char *dest = argv[argc - 1];
    int is_dir = access(dest, F_OK) == 0 && access(dest, W_OK) == 0;

    // Iterar sobre todos os arquivos de origem
    for (int i = 1; i < argc - 1; i++) {
        // Obter o nome do arquivo de origem
        char *src = argv[i];

        // Se o destino for um diretório, construir o caminho de destino
        char *dst;
        if (is_dir) {
            char *file_name = strrchr(src, '/');
            if (file_name != NULL) {
                dst = malloc(strlen(dest) + strlen(file_name) + 2);
                sprintf(dst, "%s/%s", dest, file_name + 1);
            } else {
                dst = malloc(strlen(dest) + strlen(src) + 2);
                sprintf(dst, "%s/%s", dest, src);
            }
        } else {
            // Se o destino não for um diretório, o destino é o próprio destino
            dst = dest;
        }

        // Renomear ou mover o arquivo de origem para o destino
        if (rename(src, dst) == -1) {
            perror("Erro ao renomear ou mover arquivo");
            return 1;
        }

        // Liberar memória alocada se o destino foi construído
        if (is_dir) {
            free(dst);
        }
    }

    return 0;
}
