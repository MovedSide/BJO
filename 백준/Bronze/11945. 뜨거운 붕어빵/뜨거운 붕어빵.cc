#include <bits/stdc++.h>


using namespace std;



int main()
{
	int n, m;
	string a[10];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		reverse(a[i].begin(), a[i].end());
		cout << a[i] << endl;
	}
	return 0;
}