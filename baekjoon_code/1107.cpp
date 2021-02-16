#include<bits/stdc++.h>

using namespace std;


bool num[10];



bool is_num(int x)
{
	if (x == 0)
	{
		if (num[x] == false) return false;
		else return true;
	}
	while (x != 0)
	{
		if (!num[x % 10]) return false;
		x /= 10;
	}
	return true;

}
int cal_s(int x)
{
	int cnt = 1;
	while (x >= 10)
	{
		x /= 10;
		cnt++;
	}
	return cnt;
}

int main()
{

	int N;
	cin >> N;
	int T;
	cin >> T;
	for (int i = 0; i < 10; i++) num[i] = true;
	int K = T;
	while (T--)
	{
		int x;
		cin >> x;
		num[x] = false;
	}
	if (K == 10)
	{
		cout << abs(100 - N);
		return 0;
	}
	int x = N;
	while (x <= 1000000)
	{
		if (is_num(x)) break;
		x++;
	}
	int min_num = min(abs(100 - N), abs(N - x) + cal_s(x));
	x = N;
	while (x >= 0)
	{
		if (is_num(x)) break;
		x--;
	}
	if (x != -1) min_num = min(min_num, abs(N - x) + cal_s(x));
	cout << min_num;

	return 0;
}
