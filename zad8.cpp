#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

// Funkcja obliczająca sumę elementów na przekątnych spełniających warunki
double suma_przekatnych(int n, double** B) {
    double suma = 0.0;

    for (int i = 0; i < n; i++) {
        // Główna przekątna (i == j)
        if (sin(B[i][i]) >= 0) {
            suma += B[i][i];
        }

        // Druga przekątna (j = n - i - 1)
        if (i != n - i - 1 && sin(B[i][n - i - 1]) >= 0.5) {
            suma += B[i][n - i - 1];
        }
    }

    return suma;
}

int main() {
    int n;

    // Wczytanie rozmiaru macierzy
    printf("Podaj rozmiar macierzy (n): ");
    scanf("%d", &n);

    // Alokacja pamięci dla macierzy
    double** B = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        B[i] = (double*)malloc(n * sizeof(double));
    }

    // Wczytanie elementów macierzy
    printf("Podaj elementy macierzy %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%lf", &B[i][j]);
        }
    }

    // Obliczenie sumy
    double wynik = suma_przekatnych(n, B);

    // Wyświetlenie wyniku
    printf("Suma elementów spełniających warunki: %.2lf\n", wynik);

    // Zwolnienie pamięci
    for (int i = 0; i < n; i++) {
        free(B[i]);
    }
    free(B);

    return 0;
}
