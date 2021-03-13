#include<bits/stdc++.h>

using namespace std;

const int MAX = 987654321;
long long A, B;
int an = MAX;
void func(long long x, int cnt)
{
    if (x > B) return;
    if (x == B)
    {
        an = min(an, cnt);
    }
    func(x * 2, cnt + 1);
    func(x * 10 + 1, cnt + 1);
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> A >> B;
    func(A, 1);
    if (an == MAX) cout << "-1";
    else cout << an;
    return 0;
}