## Ejercicio: Huelga de transportistas 

Los transportistas siguen en huelga. Para tener más visibilidad en una ciudad, la Unión de Transportistas ha decidido que cada uno de los `n` transportistas vaya a uno de los `n` destinos diferentes.

En la celda `(i, j)` de una matriz de `n x n` (número de transportistas x número destinos) se han almacenado los litros de combustible que gasta el transportista `i` si va al destino `j`.

Implementa un algoritmo de Vuelta Atrás para decidir el lugar al que debe ir cada transportista de manera que se minimice el número total de litros de diésel consumidos.

Ejemplo de una tabla para 7 transportistas y 7 destinos diferentes:

|      | Destino 0 | Destino 1 | Destino 2 | Destino 3 | Destino 4 | Destino 5 | Destino 6 |
|------|----------|----------|----------|----------|----------|----------|----------|
| Transportista 0 | 17       | 45       | 90       | 51       | 55       | 58       | 83       |
| Transportista 1 | 40       | 38       | 73       | 77       | 83       | 29       | 11       |
| Transportista 2 | 51       | 56       | 14       | 86       | 22       | 75       | 37       |
| Transportista 3 | 41       | 24       | 67       | 49       | 19       | 91       | 12       |
| Transportista 4 | 28       | 26       | 56       | 33       | 67       | 32       | 62       |
| Transportista 5 | 38       | 68       | 53       | 73       | 83       | 21       | 43       |
| Transportista 6 | 52       | 76       | 44       | 10       | 42       | 31       | 12       | 

La solución se representará mediante un vector `S` de longitud `n`, donde `si` representa el destino asignado al transportista `i`.

El algoritmo de Vuelta Atrás comenzará con el primer transportista y avanzará en la construcción de la solución en cada etapa, asegurándose siempre de que el nuevo valor añadido a la solución es compatible con los valores anteriores.

Por cada solución encontrada, el algoritmo registrará su coste (litros consumidos) y lo comparará con el coste de la mejor solución encontrada hasta el momento.

Para mejorar el algoritmo de Vuelta Atrás, es recomendable realizar podas en el árbol implícito eliminando aquellos nodos que no van a llevar a la solución óptima.

Para ello, se puede implementar una función de factibilidad que haga uso de una cota que almacene los litros consumidos en la mejor solución encontrada hasta el momento. Además, se llevará la cuenta en cada nodo de los litros acumulados hasta ese momento.

Si este valor es mayor que el valor de la cota, no merece la pena continuar explorando los hijos de ese nodo, ya que nunca nos llevarán a una solución mejor de la que ya tenemos. De esta forma, se puede reducir significativamente el tiempo de ejecución del algoritmo y mejorar su eficiencia.

## Solución mía

```
void transportistas(int n, int costeActual, int mat[N][N], int destinos[]) {
    if (n == N) {
        if (costeActual < costeMin) {
            costeMin = costeActual;
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
```

```
void llamarTransportistas() {
    int mat[N][N] = {
            {17, 45, 90, 51, 55, 58, 83},
            {40, 38, 73, 77, 83, 29, 11},
            {51, 56, 14, 86, 22, 75, 37},
            {41, 24, 67, 49, 19, 91, 12},
            {28, 26, 56, 33, 67, 32, 62},
            {38, 68, 53, 73, 83, 21, 43},
            {52, 76, 44, 10, 42, 31, 12}
    };

    int destinos[N] = {0};
    transportistas(0, 0, mat, destinos);
    printf("Solucion:\n");
    printf("Costo minimo: %d\n", costeMin);
    printf("Asignacion de destinos:\n");
    for (int i = 0; i < N; i++) {
        printf("Transportista %d -> Destino %d\n", i, vecSolucion[i]);
    }
}

```