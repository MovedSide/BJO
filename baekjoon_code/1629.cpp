#include<bits/stdc++.h>

using namespace std;

long long A, B, C;


long long func(long long a, long long b)
{
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b % 2 == 1) return func(a, b - 1) * a;
	return (func(a, b / 2) % C) * (func(a, b / 2) % C) % C;

}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> A >> B >> C;
	cout << func(A, B) % C;
	return 0;
}