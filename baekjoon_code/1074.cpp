#include<bits/stdc++.h>

using namespace std;





int main()
{
	int N, x, y;
	cin >> N >> x >> y;
	int cnt = pow(2, N - 1);
	int an = 0;
	int index1 = 0;
	int index2 = 0;
	while (cnt != 0)
	{
		if (x >= index1 + cnt && y >= index2 + cnt)
		{
			an += pow(cnt, 2) * 3;
			index1 += cnt;
			index2 += cnt;
		}
		else if (y >= index2 + cnt)
		{
			an += pow(cnt, 2) * 1;
			index2 += cnt;
		}
		else if (x >= index1 + cnt)
		{
			an += pow(cnt, 2) * 2;
			index1 += cnt;
		}
		cnt /= 2;
	}
	cout << an;
	return 0;
}