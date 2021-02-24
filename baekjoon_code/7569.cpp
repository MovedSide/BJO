#include<bits/stdc++.h>

using namespace std;



int to[100][100][100];
queue<tuple<int, int, int>> qu;
int M, N, H;

bool is_valid(int x, int y, int z)
{
	if (x<0 || y<0 || z<0 || x>=H || y>=N || z>=M) return false;
	if (to[x][y][z] !=0) return false;

	return true;
}
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };



int main()
{

	cin >> M >> N >> H;
	for (int x = 0; x < H; x++)
		for (int y = 0; y < N; y++)
			for (int z = 0; z < M; z++)
			{
				cin >> to[x][y][z];
				if (to[x][y][z] == 1)
				{
					qu.push(make_tuple(x, y, z));
				}
			}
	int an;
	while (!qu.empty())
	{
		auto el = qu.front();
		qu.pop();
		int xel = get<0>(el);
		int yel = get<1>(el);
		int zel = get<2>(el);
		for(int i=0;i<6;i++)
		{ 
			int mx, my, mz;
			mx = xel + dx[i];
			my = yel + dy[i];
			mz = zel + dz[i];
			if (is_valid(mx, my, mz))
			{
				qu.push(make_tuple(mx, my, mz));
				to[mx][my][mz] = to[xel][yel][zel]+1;
			}
		}
		if (qu.empty())
		{
			bool print = true;
			for (int x = 0; x < H; x++)
				for (int y = 0; y < N; y++)
					for (int z = 0; z < M; z++)
					{
						if (to[x][y][z] == 0) print = false;
					}
			if (print)
				an = to[xel][yel][zel]-1;
			else an = -1;
		}
	}
	cout << an;
	return 0;
}
