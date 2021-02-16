#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	int num[50];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	int a = 101;
	int b = 101;
	if (N > 2)
	{
		int x1, x2, y1, y2;
		x1 = num[1];
		x2 = num[2];
		if (num[1] == num[0])
		{
			a = 1;
			b = 0;
		}
		else
		{
			if ((num[2] - num[1]) % (num[1] - num[0]))
			{
				cout << "B";
				exit(0);
			}
			a = (num[2] - num[1]) / (num[1] - num[0]);
			b = num[1] - a * num[0];
		}
		for (int i = 1; i < N - 1; i++)
		{
			if (num[i] * a + b != num[i + 1])
			{
				cout << "B";
				exit(0);
			}
		}
		cout << num[N - 1] * a + b;

	}
	else if (N == 1 || (N == 2 && num[0] != num[1]))
		cout << "A";
	else if (N == 2)
	{
		cout << num[0];
	}
	else if (num[0] == num[1] && num[1] != num[2])
	{
		cout << "B";
	}
	return 0;
}
