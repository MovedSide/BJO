#include<bits/stdc++.h>

using namespace std;

const int MAX = 8;

int N, M;
int num[MAX];
int an[MAX];
bool vis[MAX] = { 0, };
void func(int x, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) cout << an[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = x; i < N; i++)
	{
		an[cnt] = num[i];
		func(i, cnt + 1);
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num, num + N);
	func(0, 0);
	return 0;
}