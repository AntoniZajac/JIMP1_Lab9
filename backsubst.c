#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int r = mat->r;
	int c = mat->c;
	
	int i, j, k;
	double sum;
        double v, g;

	// sprawdz rozmiar macierzy b i mat
	if (b->c > 1 || b->r != r || r != c) {
		return 2;
	}

	j = r - 1;
	while (j >= 0) {
		i = c - 1;
		sum = 0;
		while (i >= j) {
			sum += b->data[j][0] / mat->data[j][i];
			x->data[j];
		}
		
	}

	
	return 0;
}


