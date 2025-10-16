#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

// --- Iterativa ---
int busqueda_iterativa(int arr[], int n, int x) {
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int mid = (inicio + fin) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) inicio = mid + 1;
        else fin = mid - 1;
    }
    return -1;
}

// --- Recursiva ---
int busqueda_recursiva(int arr[], int inicio, int fin, int x) {
    if (inicio > fin) return -1;
    int mid = (inicio + fin) / 2;
    if (arr[mid] == x) return mid;
    else if (arr[mid] > x) return busqueda_recursiva(arr, inicio, mid - 1, x);
    else return busqueda_recursiva(arr, mid + 1, fin, x);
}

// Medición de memoria
long memoria_usada() {
    struct rusage uso;
    getrusage(RUSAGE_SELF, &uso);
    return uso.ru_maxrss;
}

int main() {
    int arr[100], n, x;
    printf("Tamaño del arreglo: ");
    scanf("%d", &n);
    printf("Ingrese los elementos (ordenados): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Elemento a buscar: ");
    scanf("%d", &x);

    clock_t start, end;
    double tiempo;
    int posI, posR;

    // --- Iterativa ---
    start = clock();
    posI = busqueda_iterativa(arr, n, x);
    end = clock();
    tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n[Iterativa] Posición: %d | Tiempo = %f s | Memoria = %ld KB\n", 
           (posI != -1 ? posI + 1 : -1), tiempo, memoria_usada());

    // --- Recursiva ---
    start = clock();
    posR = busqueda_recursiva(arr, 0, n - 1, x);
    end = clock();
    tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n[Recursiva] Posición: %d | Tiempo = %f s | Memoria = %ld KB\n", 
           (posR != -1 ? posR + 1 : -1), tiempo, memoria_usada());

    return 0;
}
