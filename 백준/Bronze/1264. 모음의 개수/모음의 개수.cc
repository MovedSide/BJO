#include<bits/stdc++.h>
using namespace std;




int main()
{
	while (1)
	{
		string a;
		getline(cin, a);
		if (a[0] == '#') break;
		int cnt = 0;
		for (char c : a)
		{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
				|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}