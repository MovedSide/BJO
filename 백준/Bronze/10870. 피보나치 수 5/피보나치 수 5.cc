#include<bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	cin >> n;
	int a, b;
	a = 0;
	b = 1;
	int an = 0;
	for (int i = 1; i < n; i++)
	{
		an = a + b;
		a = b;
		b = an;
	}
	if (n == 1) cout << 1;
	else cout << an;
	return 0;
}