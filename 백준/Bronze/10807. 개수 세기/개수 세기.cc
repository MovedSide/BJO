#include<bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	cin >> n;
	int v[100];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int num, cnt = 0;
	cin >> num;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == num) cnt++;
	}
	cout << cnt;
	return 0;
}