#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    double X, Y, D, T;
    cin >> X >> Y >> D >> T;
    double r, dis;
    double cnt;
    dis = sqrt(pow(X, 2) + pow(Y, 2));
    r = dis;
    cnt = r;
    int jump = 0;
    while (r >= D)
    {
        r -= D;
        jump++;
    }
    if (jump == 0)
    {
        cnt = min(T + T, cnt);
        cnt = min(T + D - r, cnt);
    }
    else
    {
        cnt = min(jump * T + r, cnt);
        cnt = min(jump * T + T, cnt);
    }
    cout << fixed;
    cout.precision(13);
    cout << cnt;
    return 0;
}