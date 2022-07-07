#include <bits/stdc++.h>


using namespace std;



bool is_prime[4000001];
int n;
vector<int> prime_num;


void set_prime()
{
	for (int i = 2; i*i <= n; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i])
			prime_num.push_back(i);
	}
}


int main()
{
	cin >> n;
	int cnt = 0;
	memset(is_prime, true, sizeof(is_prime));
	set_prime();
	for (int i = prime_num.size() - 1; i >= 0; i--)
	{
		int sum = 0;
		int j = i;
		while (j>=0)
		{
			sum += prime_num[j];
			if (sum == n)
			{
				cnt++;
				break;
			}
			if (sum > n) break;
			j--;
		}
	}
	cout << cnt;
	return 0;
}