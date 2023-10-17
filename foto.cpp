#include <fstream>
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
int main()
{
	int n, m;
	fin >> n >> m;
	int i, j, a[n+2][m+2], nrmax, nrz, nr, inc, sf, d;
	punct cd[n*m], p, v;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			fin >> a[i][j];
		}
	}
	fin.close();
	for (j = 0; j <= m+1; j++)
	{
		a[0][j] = a[n+1][j] = 1;
	}
	for (i = 0; i <= n+1; i++)
	{
		a[i][0] = a[i][m+1] = 1;
	}
	nrmax = nrz = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == 0)
			{
				nrz++;
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
// scor 100
