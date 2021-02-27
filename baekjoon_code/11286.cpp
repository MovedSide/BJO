#include<bits/stdc++.h>

using namespace std;


struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) > abs(b))
		{
			return true;
		}
		else if (abs(a) == abs(b))
		{
			if (a > b) return true;
			else return false;
		}
		else return false;
	}


};


int main()
{
	priority_queue<int, vector<int>, cmp> maxh;
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
