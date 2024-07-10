#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Abrir o arquivo para leitura
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    // Buffer para ler dados do arquivo
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Ler e escrever o conteúdo do arquivo no terminal
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            perror("Erro ao escrever no terminal");
            close(fd);
            return 1;
        }
    }

    // Verificar se houve erro na leitura
    if (bytes_read == -1) {
        perror("Erro ao ler do arquivo");
        close(fd);
        return 1;
    }

    // Fechar o arquivo
    close(fd);

    return 0;
}
