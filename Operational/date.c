#include <stdio.h>
#include <sys/time.h>
#include <time.h>   // O código não estava compilando ao utilizar apenas a bibliotaca <sys/time.h>, por isso precisei utilizar <time.h> também.

int main() {
    struct timeval tv;
    struct tm *timeinfo;
    
    // Obter a hora atual do sistema
    gettimeofday(&tv, NULL);
    
    // Converter o tempo em um formato legível
    timeinfo = localtime(&tv.tv_sec);
    
    // Imprimir a hora atual
    printf("A hora atual é: %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    return 0;
}
