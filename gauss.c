#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int i, j, c;
	double a, k, u, g;

	if (mat->r != b->r)
	{
		return 1;
	}

	for (i = 0; i < mat->c; i++)
	{
		j = i;
		k = mat->data[j][i];
		while (j < mat->r)
		{
			j++;
			a = mat->data[j][i];
			u = a / k;
			c = i;
			while ( c < mat->c)
			{
				mat->data[j][c] -= u*k;
				c++;
			}
			b->data[j][0] -= u*b->data[j - 1][0];	
		}
				
	}
	return 0;
}

