#include <fstream>
#define NMAX 100
#define MMAX 100
#define ND 4
using namespace std;
ifstream fin("foto.in");
ofstream fout("foto.out");
struct punct
{
	int x, y;
};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void citesteDateIntrare(int &, int &, int [NMAX+2][MMAX+2]);
void bordeazaMatricea(int [NMAX+2][MMAX+2], int, int, int);
int nrPuncteLuminoase(int [NMAX+2][MMAX+2], int, int, int);
int main()
{
	int n, m, a[NMAX+2][MMAX+2], i, j, nrz, nr, nrmax;
	citesteDateIntrare(n, m, a);
	bordeazaMatricea(a, n, m, 1);
	nrz = nrmax = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == 0)
			{
				nrz++;
				nr = nrPuncteLuminoase(a, i, j, nrz);
				if (nr > nrmax)
				{
					nrmax = nr;
				}
			}
		}
	}
	fout << nrmax;
	fout.close();
	return 0;
}
void citesteDateIntrare(int & n, int & m, int a[NMAX+2][MMAX+2])
{
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			fin >> a[i][j];
		}
	}
	fin.close();
}
void bordeazaMatricea(int a[NMAX+2][MMAX+2], int n, int m, int k)
{
	for (int j = 0; j <= m+1; j++)
	{
		a[0][j] = a[n+1][j] = k;
	}
	for (int i = 0; i <= n+1; i++)
	{
		a[i][0] = a[i][m+1] = k;
	}
}
int nrPuncteLuminoase(int a[NMAX+2][MMAX+2], int i, int j, int nrz)
{
	int nr, inc, sf, d;
	punct cd[NMAX*MMAX], p, v;
	nr = 1;
	inc = sf = 0;
	cd[sf].x = i;
	cd[sf].y = j;
	a[i][j] = nrz+1;
	while (inc <= sf)
	{
		p = cd[inc++];
		for (d = 0; d < ND; d++)
		{
			v.x = p.x + dx[d];
			v.y = p.y + dy[d];
			if (a[v.x][v.y] == 0)
			{
				nr++;
				cd[++sf] = v;
				a[v.x][v.y] = nrz+1;
			}
		}
	}
	return nr;
}
// scor 100
