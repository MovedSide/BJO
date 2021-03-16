#include<bits/stdc++.h>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string st, an;
	cin >> st;
	stack<char> sta;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] >= 'A' && st[i] <= 'Z') an += st[i];
		else if (st[i] == '(')
		{
			sta.push(st[i]);
		}
		else if (st[i] == '+' || st[i] == '-')
		{
			while (!sta.empty() && sta.top() != '(')
			{
				an += sta.top();
				sta.pop();
			}
			sta.push(st[i]);
		}
		else if (st[i] == '*' || st[i] == '/')
		{
			while (!sta.empty() && (sta.top() == '*' || sta.top() == '/'))
			{
				an += sta.top();
				sta.pop();
			}
			sta.push(st[i]);
		}
		else if (st[i] == ')')
		{
			while (!sta.empty() && sta.top() != '(')
			{
				an += sta.top();
				sta.pop();
			}
			sta.pop();
		}
	}
	while (!sta.empty())
	{
		an += sta.top();
		sta.pop();
	}
	cout << an;
	return 0;
}