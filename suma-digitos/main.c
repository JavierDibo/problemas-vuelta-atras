#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

void sumaDigitos(int n, int sumaActual, ivector digitos, int pos);

void llamarSuma();

int main() {

     llamarSuma();

    return 0;
}

void sumaDigitos(int n, int sumaActual, ivector digitos, int pos) {
    if (pos == n) {
        if (sumaActual == 0) {
            for (int i = 0; i < n; i++) {
                printf("%d", digitos[i]);
            }
            printf("\n");
        }
    } else {
        for (int i = 1; i <= 5; i++) {
            digitos[pos] = i;
            if (pos % 2 == 0) {
                sumaActual += i;
            } else {
                sumaActual -= i;
            }
            if (abs(sumaActual) <= (5 * (n - pos - 1))) {
                sumaDigitos(n, sumaActual, digitos, pos + 1);
            }
            if (pos % 2 == 0) {
                sumaActual -= i;
            } else {
                sumaActual += i;
            }
        }
    }
}

void llamarSuma() {
    int n = 5;
    ivector digits = icreavector(n);
    sumaDigitos(n, 0, digits, 0);
    ifreevector(&digits);
}