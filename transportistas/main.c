#include <stdio.h>
#include "ivector.h"
#include "imatriz2d.h"

#define N 7

int costeMin = 1e9;
ivector vecSolucion;

void transportistas(int n, int costeActual, imatriz2d mat, ivector destinos);

void llamarTransportistas();

int main() {

     llamarTransportistas();

    return 0;
}

void transportistas(int n, int costeActual, imatriz2d mat, ivector destinos) {
    if (n == N) {
        if (costeActual < costeMin) {
            costeMin = costeActual;
            ifreevector(&vecSolucion);
            vecSolucion = icreavector(N);
            for (int i = 0; i < N; i++) {
                vecSolucion[i] = destinos[i];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!destinos[i]) {
            destinos[i] = 1;
            transportistas(n + 1, costeActual + mat[n][i], mat, destinos);
            destinos[i] = 0;
        }
    }
}

void llamarTransportistas() {
    imatriz2d mat = icreamatriz2d(N, N);

    ivector destinos = icreavector(N);
    transportistas(0, 0, mat, destinos);
    printf("Solucion:\n");
    printf("Costo minimo: %d\n", costeMin);
    printf("Asignacion de destinos:\n");
    for (int i = 0; i < N; i++) {
        printf("Transportista %d -> Destino %d\n", i, vecSolucion[i] + 1);
    }
    ifreevector(&destinos);
    ifreematriz2d(&mat);
    ifreevector(&vecSolucion);
}
