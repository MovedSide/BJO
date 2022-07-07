#include <bits/stdc++.h>


using namespace std;






int main()
{
	int T;
	cin >> T;
	int n, m;
	cin >> n;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a;
		v1.push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		v2.push_back(a);
	}
	vector<int> s1, s2;
	for (int i = 0; i < n; i++)
	{
		int sum = v1[i];
		s1.push_back(sum);
		for(int j=i+1;j<n;j++)
		{
			sum += v1[j];
			s1.push_back(sum);
		}
	}
	sort(s1.begin(), s1.end());
	for (int i = 0; i < m; i++)
	{
		int sum = v2[i];
		s2.push_back(sum);
		for (int j = i + 1; j < m; j++)
		{
			sum += v2[j];
			s2.push_back(sum);
		}
	}
	sort(s2.begin(), s2.end());
	long long an = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		auto x = upper_bound(s2.begin(), s2.end(), T - s1[i]);
		auto y = lower_bound(s2.begin(), s2.end(), T - s1[i]);
		an += x - y;
	}
	cout << an;
	return 0;
}