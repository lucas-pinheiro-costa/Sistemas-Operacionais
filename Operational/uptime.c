#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    long uptime_seconds;

    // Obter informações do sistema
    sysinfo(&info);

    // Calcular o tempo de atividade em segundos
    uptime_seconds = info.uptime;

    // Converter o tempo de atividade em dias, horas, minutos e segundos
    int days = uptime_seconds / (60 * 60 * 24);
    int hours = (uptime_seconds % (60 * 60 * 24)) / (60 * 60);
    int minutes = (uptime_seconds % (60 * 60)) / 60;
    int seconds = uptime_seconds % 60;

    // Imprimir o tempo de atividade
    printf("Tempo de atividade deste computador: %d dias, %dh:%02dmin:%02dseg\n", days, hours, minutes, seconds);

    return 0;
}
