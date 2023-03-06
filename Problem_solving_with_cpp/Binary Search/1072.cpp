#include <bits/stdc++.h>
using namespace std;
double X, Y;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> X >> Y;
    double Z = Y * 100 / X;
    long long z = (long long)Z;
    if (z >= 99)
    {
        cout << -1 << '\n';
        return 0;
    }
    long long left = 0;
    long long right = 2000000000;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        double TMP = (Y + mid) * 100 / (X + mid);
        long long tmp = (long long)TMP;
        if (z < tmp)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left << '\n';
    return 0;
}