#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

// Recursión rápida (Exponentiation by squaring)
long long potencia_recursiva(int base, int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long half = potencia_recursiva(base, exp / 2);
        return half * half;
    } else {
        return base * potencia_recursiva(base, exp - 1);
    }
}

// Iterativa
long long potencia_iterativa(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) res *= base;
    return res;
}

// Medición de memoria
long memoria_usada() {
    struct rusage uso;
    getrusage(RUSAGE_SELF, &uso);
    return uso.ru_maxrss;
}

int main() {
    int base, exp;
    printf("Base: ");
    scanf("%d", &base);
    printf("Exponente: ");
    scanf("%d", &exp);

    if (exp < 0) {
        printf("Exponente negativo no soportado.\n");
        return 0;
    }

    clock_t start, end;
    double tiempo;
    long long resI = 0, resR = 0;
    int repeticiones = 10000;

    // Iterativa
    start = clock();
    for (int i = 0; i < repeticiones; i++) resI = potencia_iterativa(base, exp);
    end = clock();
    tiempo = ((double)(end - start) / CLOCKS_PER_SEC) / repeticiones;
    printf("\n[Iterativa] Resultado: %lld | Tiempo promedio = %e s | Memoria = %ld KB\n", 
           resI, tiempo, memoria_usada());

    // Recursiva
    start = clock();
    for (int i = 0; i < repeticiones; i++) resR = potencia_recursiva(base, exp);
    end = clock();
    tiempo = ((double)(end - start) / CLOCKS_PER_SEC) / repeticiones;
    printf("\n[Recursiva] Resultado: %lld | Tiempo promedio = %e s | Memoria = %ld KB\n", 
           resR, tiempo, memoria_usada());

    return 0;
}
