#include <bits/stdc++.h>


using namespace std;






int main()
{
	while (1)
	{
		string a;
		getline(cin, a);
		if (a[0] == 'E' && a[1] == 'N' && a[2] == 'D') break;
		reverse(a.begin(), a.end());
		cout << a << endl;
	}
	return 0;
}