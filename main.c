#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argc > 1 ? argv[1] : "A.txt" );
	Matrix * b = readFromFile(argc > 2 ? argv[2] : "b.txt" );
	Matrix * x;
				     
	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);					 
	
	res = eliminate(A, b);

	if (res != 0) {
		fprintf(stderr, "Błąd! Powstała macierz jest osobliwa - dzielnie przez 0.\n");
		return -3;
	}
	x = createMatrix(b->r, 1);
	
	printToScreen(A);
	printToScreen(b);
	printf("program dziala!!!!");

	return 0;
	
	if (x != NULL) {
		res = backsubst(x,A,b);											    
		printToScreen(x);
		freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}
										 
	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
