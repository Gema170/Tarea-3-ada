#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

// --- Función iterativa ---
int suma_iterativa(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

// --- Función recursiva ---
int suma_recursiva(int n) {
    printf("Llamada recursiva: suma_recursiva(%d)\n", n);
    if (n == 0) return 0;
    return n % 10 + suma_recursiva(n / 10);
}

// --- Medición de memoria ---
long memoria_usada() {
    struct rusage uso;
    getrusage(RUSAGE_SELF, &uso);
    return uso.ru_maxrss; // KB
}

int main() {
    int n;
    printf("Ingrese un número: ");
    scanf("%d", &n);

    clock_t start, end;
    double tiempo;

    // Iterativa
    start = clock();
    int sumaI = suma_iterativa(n);
    end = clock();
    tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n[Iterativa] Suma de dígitos = %d | Tiempo = %f s | Memoria = %ld KB\n", sumaI, tiempo, memoria_usada());

    // Recursiva
    start = clock();
    int sumaR = suma_recursiva(n);
    end = clock();
    tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n[Recursiva] Suma de dígitos = %d | Tiempo = %f s | Memoria = %ld KB\n", sumaR, tiempo, memoria_usada());

    return 0;
}
