#include<bits/stdc++.h>

using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int inp;
		scanf("%d", &inp);
		if (inp == 0)
		{
			if (pq.empty()) printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(inp);
		}
	}
	return 0;
}