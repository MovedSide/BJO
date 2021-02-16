#include<bits/stdc++.h>

using namespace std;

const int MAX = 300000;

int N, K;
pair<int, int> jw[MAX];
int bag[MAX];
priority_queue<int> qu;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> jw[i].first >> jw[i].second;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}
	sort(jw, jw + N);
	sort(bag, bag + K);
	int t = 0;
	long long cnt = 0;
	for (int i = 0; i < K; i++)
	{
		while (t < N && jw[t].first <= bag[i])
		{
			qu.push(jw[t++].second);
		}
		if (!qu.empty())
		{
			cnt += qu.top();
			qu.pop();
		}
	}
	cout << cnt;
	return 0;
}
