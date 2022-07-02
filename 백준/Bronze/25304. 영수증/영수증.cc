#include<bits/stdc++.h>
using namespace std;




int main()
{
	int x;
	cin >> x;
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}
	if (sum == x) cout << "Yes";
	else cout << "No";
}