#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nome_do_diretorio>\n", argv[0]);
        return 1;
    }

    char *dir_name = argv[1];

    // Criar o diretório com permissões padrão (0777)
    if (mkdir(dir_name, 0777) == -1) {
        perror("Erro ao criar diretório");
        return 1;
    }

    printf("Diretório '%s' criado com sucesso.\n", dir_name);

    return 0;
}
