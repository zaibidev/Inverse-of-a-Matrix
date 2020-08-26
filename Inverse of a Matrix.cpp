#include<iostream>
using namespace std;
#include<math.h>
float determinant(float[][25], float);
void cf(float[][25], float);
void change(float[][25], float[][25], float);
int main()
{
	float a[25][25], k, d;
	int i, j;
	cout << " Enter the matrix order" << " ";
	cin >> k;
	cout << "Enter the elements of matrix" << endl;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			cin >> a[i][j];
		}
	}
	d = determinant(a, k);
	if (d == 0)


	{
		cout << "\nInverse of Entered Matrix is not possible\n" << endl;
		cout << " As its inverse is not possible so it is linerly dependent" << endl;
		cout << endl;
		cout << " inveerse is not possible This implies that it is not bijective" << endl;
	}
	else
		cf(a, k);
	system("pause");
}

float determinant(float a[25][25], float k)
{
	float s = 1, det = 0, b[25][25];
	int i, j, m, n, c;
	if (k == 1)
	{
		return (a[0][0]);
	}
	else
	{
		det = 0;
		for (c = 0; c < k; c++)
		{
			m = 0;
			n = 0;
			for (i = 0; i < k; i++)
			{
				for (j = 0; j < k; j++)
				{
					b[i][j] = 0;
					if (i != 0 && j != c)
					{
						b[m][n] = a[i][j];
						if (n < (k - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * determinant(b, k - 1));
			s = -1 * s;
		}
	}

	return (det);
}

void cf(float num[25][25], float f)
{
	float b[25][25], fac[25][25];
	int p, q, m, n, i, j;
	for (q = 0; q < f; q++)
	{
		for (p = 0; p < f; p++)
		{
			m = 0;
			n = 0;
			for (i = 0; i < f; i++)
			{
				for (j = 0; j < f; j++)
				{
					if (i != q && j != p)
					{
						b[m][n] = num[i][j];
						if (n < (f - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
		}
	}
	change(num, fac, f);
}

void change(float num[25][25], float fac[25][25], float r)
{
	int i, j;
	float b[25][25], inverse[25][25], d;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < r; j++)
		{
			b[i][j] = fac[j][i];
		}
	}
	d = determinant(num, r);
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < r; j++)
		{
			inverse[i][j] = b[i][j] / d;
		}
	}
	cout << "\n\n\nThe inverse of matrix is : \n" << endl;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < r; j++)
		{
			cout << inverse[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << " As it inverse is exiest so it is linerly independent" << endl;
	cout << " As pivots is equal to number of rows and colmns so matrix is bijective " << endl;
}