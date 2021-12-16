#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int i, j, c, h;
	double a, k, u, g;

	if (mat->r != b->r)
	{
		return 1;
	}

	for (i = 0; i < mat->c; i++)
	{
		j = i;
		h = i;
		k = mat->data[j][i];
		while (++j < mat->r)
		{
			
			a = mat->data[j][i];
			u = a / k;
			c = i;
			while ( c < mat->c)
			{
				mat->data[j][c] -= u*mat->data[h][c];
				c++;
			}
			b->data[j][0] -= u*b->data[h][0];	
		}
				
	}
	return 0;
}

