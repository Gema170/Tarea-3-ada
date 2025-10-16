#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>

// Iterativa
void invertir_iterativa(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Recursiva
void invertir_recursiva(char str[], int inicio, int fin) {
    printf("Llamada recursiva: invertir_recursiva(%d, %d)\n", inicio, fin);
    if (inicio >= fin) return;
    char temp = str[inicio];
    str[inicio] = str[fin];
    str[fin] = temp;
    invertir_recursiva(str, inicio+1, fin-1);
}

// Memoria
long memoria_usada() {
    struct rusage uso;
    getrusage(RUSAGE_SELF, &uso);
    return uso.ru_maxrss;
}

int main() {
    char str[100];
    printf("Ingrese una cadena: ");
    scanf("%s", str);

    clock_t start, end;
    double tiempo;

    char copia1[100], copia2[100];
    strcpy(copia1, str);
    strcpy(copia2, str);

    // Iterativa
    start = clock();
    invertir_iterativa(copia1);
    end = clock();
    tiempo = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\n[Iterativa] Resultado: %s | Tiempo = %f s | Memoria = %ld KB\n", copia1, tiempo, memoria_usada());

    // Recursiva
    start = clock();
    invertir_recursiva(copia2, 0, strlen(copia2)-1);
    end = clock();
    tiempo = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\n[Recursiva] Resultado: %s | Tiempo = %f s | Memoria = %ld KB\n", copia2, tiempo, memoria_usada());

    return 0;
}
