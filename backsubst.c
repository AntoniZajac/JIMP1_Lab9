#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int r = mat->r;
	int c = mat->c;
	
	int i, j;

	// sprawdz rozmiar macierzy b i mat
	if (b->c > 1 || b->r != r || r != c) {
		return 2;
	}

	j = r;
	while (--j >= 0) {
		i = c;
		
		double sum = 0;
		while (--i > j) {
			// dla macierzy x indeks kolumny jest indeksem aktywnego wiersza
			sum += x->data[i][0] * mat->data[j][i];
		}

		// sprawdz czy na diagonali nie ma 0
		if (mat->data[j][i] == 0) {
			return 1;
		}

		x->data[j][0] = ( b->data[j][0] - sum ) / mat->data[j][i];		
	}

	return 0;
}


