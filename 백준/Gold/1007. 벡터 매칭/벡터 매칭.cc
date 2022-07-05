#include <bits/stdc++.h>


using namespace std;





bool vis[100000];
int n;
double an;
vector < pair<int, int>> P;

double dfs(int a,int cnt)
{
	int sx, sy, ex, ey;
	sx = sy = ex = ey = 0;
	if (cnt == n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (vis[i])
			{
				sx += P[i].first;
				sy += P[i].second;
			}
			else
			{
				ex += P[i].first;
				ey += P[i].second;
			}
		}
		return an = min(an,sqrt(pow(ex-sx,2) + pow(ey-sy,2)));
	}
	for (int i = a; i < n; i++)
	{
		vis[i] = true;
		dfs(i+1, cnt + 1);
		vis[i] = false;
	}
	return an;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		an = 1e9;
		memset(vis, false, sizeof(vis));
		P.clear();
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int x, y;
			cin >> x >> y;
			P.push_back(make_pair(x, y));
		}
		dfs(0, 0);
		cout << fixed;
		cout.precision(6);
		cout << an << endl;
	}
	return 0;
}