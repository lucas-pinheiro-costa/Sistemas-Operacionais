#include <stdio.h>
#include <dirent.h>
#include <unistd.h> // Para a função getcwd()

int main(int argc, char *argv[]) {
    char *dir_name;

    // Verifica se o diretório foi especificado como argumento
    if (argc == 1) {
        // Se não for especificado, usa o diretório de trabalho atual
        dir_name = getcwd(NULL, 0);
    } else {
        // Se for especificado, usa o diretório fornecido
        dir_name = argv[1];
    }

    // Abrindo o diretório
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        perror("Erro ao abrir diretório");
        return 1;
    }

    // Lendo e imprimindo os arquivos dentro do diretório
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Fechando o diretório
    closedir(dir);

    return 0;
}