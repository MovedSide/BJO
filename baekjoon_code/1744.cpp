#include<bits/stdc++.h>

using namespace std;


int num[10000];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num, num + N);
	int i = 0;
	int sum = 0;
	while (num[i] <= 0 && i + 1 < N)
	{
		if (num[i + 1] <= 0)
		{
			sum += num[i] * num[i + 1];
			i += 2;
		}
		else break;
	}
	int index1 = i;
	i = N - 1;
	while (num[i] > 0 && i >= 1)
	{
		if (num[i - 1] > 0 && num[i - 1] > 1)
		{
			sum += num[i] * num[i - 1];
			i -= 2;
		}
		else break;
	}
	int index2 = i;
	for (int x = index1; x <= index2; x++)
	{
		sum += num[x];
	}


	cout << sum;
}
