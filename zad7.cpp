#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
    int n, a, b;
    printf("Podaj rozmiar macierzy (n): ");
    scanf("%d", &n);

    // Dynamiczne przydzielenie pamięci dla macierzy
    int** B = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        B[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Podaj elementy macierzy:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    printf("Podaj przedział [a, b]:\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    int suma = 0;

    // Iteracja poniżej głównej przekątnej (i > j)
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (B[i][j] >= a && B[i][j] <= b) {
                suma += B[i][j];
            }
        }
    }

    printf("Suma elementów poniżej głównej przekątnej w przedziale [%d, %d] wynosi: %d\n", a, b, suma);

    // Zwolnienie pamięci
    for (int i = 0; i < n; i++) {
        free(B[i]);
    }
    free(B);

    return 0;
}
