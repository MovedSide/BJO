#include<bits/stdc++.h>

using namespace std;


int num[1000101] = { false, };
int an[1000001] = { false, };
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	vector<long long> prime;
	for (long long i = 2; i <= sqrt(m); i++)
	{
		if (!num[i])
		{
			prime.push_back(i);
			for (long long j = 2; i * j <= sqrt(m); j++)
			{
				num[i * j] = true;
			}
		}
	}
	int cnt = 0;
	for (long long el : prime)
	{
		long long snum = n / (el * el);
		if (n % (el * el) != 0) snum++;
		for (long long j = snum; el * el * j <= m; j++)
		{
			an[el * el * j - n] = true;
		}
	}
	for (int i = 0; i < m - n + 1; i++)
	{
		if (!an[i]) cnt++;
	}
	cout << cnt;
	return 0;
}