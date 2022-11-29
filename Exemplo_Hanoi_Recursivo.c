/**************************************************************************

   This C program is to solve the towers of hanoi problem.
   Implemented using recursion.

***************************************************************************/

#include <stdio.h>


void move(int n, int o, int i, int d) {
// o para pino de origem
// d para pino de destino
// i para pino intermediário
    if (n > 0) {
	move(n - 1, o, d, i);
	/* move n-1 discos do pino de origem para o
	 * pino de destino */
	printf("mover %i para %i\n", n, d);
	/* move o disco do pino de origem para o
	 * pino de destino */
	move(n - 1, i, o, d);
	/* move n-1 discos do pino intermediário
	 * para o pino de destino */
    }
}

int main() {
    printf("Entre com o número de discos\n");
    int n;
    scanf("%i", &n);
    move(n, 1, 2, 3);		/* pino origem:        1
				 * pino destino:       3
				 * pino intermediário: 2 */
    return 0;
}
