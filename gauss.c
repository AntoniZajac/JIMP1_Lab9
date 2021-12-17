#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b)
{
	int i, j, c, h, maxr, y, f;
	double a, k, u, g, max, tmp;

	if (mat->r != b->r)
	{
		return 1;
	}

	for (i = 0; i < mat->c; i++)
	{

		j = i;
		y = i + 1;
		max = mat->data[j][i];
		maxr = j;
		while (y < mat->r)
		{
			if (mat->data[y][i] > max)
			{
				max = mat->data[y][i];
				maxr = y;
			}
			y++;
		}
		
		if (maxr != j)
		{
			for (f = i; f < mat->c; f++)
			{
				tmp = mat->data[maxr][f];
			       	mat->data[maxr][f] = mat->data[j][f];
				mat->data[j][f] = tmp;
			}

			tmp = b->data[maxr][0];
			b->data[maxr][0] = b->data[j][0];
			b->data[j][0] = tmp;
		}


		/*
		// wybor pivota (k)
		int k_j = j;
		int k_j_max = k_j;
		double k_max = mat->data[k_j][i];

		while (++k_j < mat->r)
		{	
			
			if (mat->data[k_j][i] > k_max)
			{
				k_max = mat->data[k_j][i];
				k_j_max = k_j;
			}
		}		
		
		double tmp;
		if (k_j_max != j) {
			for (int f = i; f < mat->c; f++) {
				tmp = mat->data[k_j_max][f];
				mat->data[k_j_max][f] = mat->data[j][f];
				mat->data[j][f] = tmp;		
			}

			tmp = b->data[k_j_max][0];
			b->data[k_j_max][0] = b->data[j][0];
			b->data[j][0] = tmp;
		}
		*/		
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

