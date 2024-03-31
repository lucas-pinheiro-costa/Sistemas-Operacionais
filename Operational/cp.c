#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_origem> <arquivo_destino>\n", argv[0]);
        return 1;
    }

    char *src_file = argv[1];
    char *dst_file = argv[2];

    // Abrir o arquivo de origem para leitura
    int src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        perror("Erro ao abrir arquivo de origem");
        return 1;
    }

    // Abrir o arquivo de destino para escrita (criando-o se não existir e truncando-o)
    int dst_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("Erro ao abrir ou criar arquivo de destino");
        close(src_fd);
        return 1;
    }

    // Buffer para ler e escrever dados
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // Ler do arquivo de origem e escrever no arquivo de destino
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Erro ao escrever no arquivo de destino");
            close(src_fd);
            close(dst_fd);
            return 1;
        }
    }

    // Verificar se houve erro na leitura
    if (bytes_read == -1) {
        perror("Erro ao ler do arquivo de origem");
        close(src_fd);
        close(dst_fd);
        return 1;
    }

    // Fechar os arquivos
    close(src_fd);
    close(dst_fd);

    return 0;
}
