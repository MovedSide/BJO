#include<bits/stdc++.h>

using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int an = 1;
		int a = min(M, N);
		int b = max(M, N);
		while (b != 0)
		{
			int r = a % b;
			a = b;
			b = r;
		}
		int sv = M * N / a;
		while (1)
		{
			int min_num = min(x, y) - 1;
			x -= min_num;
			y -= min_num;
			an += min_num;
			if (x == 1 && y == 1) break;
			if (x == 1)
			{
				x = M;
				y--;
				an++;
			}
			else if (y == 1)
			{
				x--;
				y = N;
				an++;
			}
			if (an > sv) { an = -1; break; }
		}
		cout << an << endl;
	}
	return 0;
}