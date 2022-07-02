#include<bits/stdc++.h>
using namespace std;




int main()
{
	int a, b;
	cin >> a >> b;
	int an;
	if (b == 0)
	{
		an = a;
	}
	else an = a * (100- b) / 100;
	if (an >= 100) cout << 0;
	else cout << 1;
}