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
	
	res = eliminate(A, b);
	if (res != 0) {
		fprintf(stderr, "Błąd! Powstała macierz jest osobliwa - dzielnie przez 0.\n");
		return -3;
	}

	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
	
		if (res == 1)
		{
			fprintf(stderr, "Błąd! Dzielenie przez 0!\n");
			return 1;
		}
		if (res == 2)
		{
			fprintf(stderr, "Błąd! Nieprawidłowe rozmiary macierzy\n");
			return 2;
		}
			
		printToScreen(x);
		freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}
										 
	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
