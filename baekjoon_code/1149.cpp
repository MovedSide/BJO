#include<bits/stdc++.h>

using namespace std;



int house[1000][3];
int vis[1000][3];
int an = 1000 * 1000 + 1;
int N;

int func(int house_index, int color, int next_color)
{
	if (vis[house_index][color]) return vis[house_index][color];
	if (house_index == N - 1) return min(house[house_index][color], house[house_index][next_color]);
	int x1, x2;
	vis[house_index][color] = min(house[house_index][color] + func(house_index + 1, (color + 2) % 3, (color + 1) % 3), house[house_index][color] + func(house_index + 1, (color + 1) % 3, (color + 2) % 3));
	return vis[house_index][color];
}



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}
	an = min(an, func(0, 0, -1));
	an = min(an, func(0, 1, -1));
	an = min(an, func(0, 2, -1));
	cout << an;
	return 0;
}