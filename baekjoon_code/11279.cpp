#include<bits/stdc++.h>

using namespace std;



int main()
{
	priority_queue<int> maxh;
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
		{
			if (!maxh.empty())
			{
				printf("%d\n", maxh.top());
				maxh.pop();
			}
			else
				printf("0\n");
		}
		else
		{
			maxh.push(n);
		}
	}
	return 0;
}
