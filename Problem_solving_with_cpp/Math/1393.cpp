#include <bits/stdc++.h>
using namespace std;
int xs, ys;
int se, ye, dx, dy;
int ansx, ansy;
int amin;
int gcd(int a, int b)
{
    if (!b)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> xs >> ys;
    cin >> se >> ye >> dx >> dy;
    int tmpx, tmpy;
    if (!dx && !dy)
    {
        cout << se << ' ' << ye << '\n';
        return 0;
    }
    else if (!dx)
    {
        tmpx = dy;
        tmpy = dy;
    }
    else if (!dy)
    {
        tmpx = dx;
        tmpy = dx;
    }
    else
    {
        if (dx < 0)
            tmpx = -dx;
        else
            tmpx = dx;
        if (dy < 0)
            tmpy = -dy;
        else
            tmpy = dy;
    }
    if (tmpy > tmpx)
        swap(tmpx, tmpy);
    int GCD = gcd(tmpx, tmpy);
    dx /= GCD;
    dy /= GCD;
    amin = (se - xs) * (se - xs) + (ye - ys) * (ye - ys);
    ansx = se;
    ansy = ye;
    for (int i = 0; i < 500; i++)
    {
        se += dx;
        ye += dy;
        int tmp = (se - xs) * (se - xs) + (ye - ys) * (ye - ys);
        if (tmp < amin)
        {
            amin = tmp;
            ansx = se;
            ansy = ye;
        }
    }

    cout << ansx << ' ' << ansy << '\n';
    return 0;
}