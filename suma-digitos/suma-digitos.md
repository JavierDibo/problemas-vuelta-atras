# Suma de digitos

Dado un valor entero n, mostrar todos los números de n cifras que se pueden formar que cumplan la siguiente condición: “la suma de los dígitos que ocupan las posiciones pares es igual a la de los que ocupan las posiciones impares”

Nota: Para simplificar el problema, considerar que solamente se pueden utilizar los dígitos del 1 al 5.

Ejemplos:

- Si n=2, los posibles números serían: 11, 22, 33, 44 y 55
- Si n=3, los posibles números serían: 121, 132, 143, 154, 231, 242, 253, 341, 352 y 451
- Si n=4, algunos de los posibles números serían: 1111, 1122, 1133, 1144, 1155, 1221, 1232, 1243, 1331, 1342, 1441, 1551, etc.

Nota: se puede trabajar con un vector para almacenar cada uno de los dígitos y, antes de dar la salida, convertirlo a un valor numérico.

La función de factibilidad debe tener en cuenta los siguientes aspectos:

- La posición del dígito que se va completando en cada momento

- La suma de los dígitos de las posiciones pares y la de los impares