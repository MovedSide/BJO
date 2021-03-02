#include<bits/stdc++.h>

using namespace std;


int num[1000000];
pair<int, int> cp[1000000];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int inp;
		cin >> inp;
		cp[i].first = inp;
		cp[i].second = i;
	}
	sort(cp, cp + n);
	int cnt = 0;
	num[cp[0].second] = cnt;
	for (int i = 1; i < n; i++)
	{
		if (cp[i - 1].first != cp[i].first) cnt++;
		num[cp[i].second] = cnt;
	}
	for (int i = 0; i < n; i++) cout << num[i] << " ";
	return 0;
}