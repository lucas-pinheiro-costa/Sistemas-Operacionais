#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <usuário> <grupo> <arquivo ou diretório>\n", argv[0]);
        return 1;
    }

    char *user = argv[1];
    char *group = argv[2];
    char *path = argv[3];

    // Obter IDs numéricos do usuário e do grupo
    struct passwd *user_info = getpwnam(user);
    if (user_info == NULL) {
        fprintf(stderr, "Usuário não encontrado: %s\n", user);
        return 1;
    }
    uid_t uid = user_info->pw_uid;

    struct group *group_info = getgrnam(group);
    if (group_info == NULL) {
        fprintf(stderr, "Grupo não encontrado: %s\n", group);
        return 1;
    }
    gid_t gid = group_info->gr_gid;

    // Alterar o proprietário e o grupo do arquivo ou diretório
    if (chown(path, uid, gid) == -1) {
        perror("Erro ao alterar o proprietário ou grupo");
        return 1;
    }

    printf("Proprietário e grupo do arquivo ou diretório alterados com sucesso.\n");

    return 0;
}
