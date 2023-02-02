#include <bits/stdc++.h>
using namespace std;
long long N, T;
long long P[101];
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    for (int i = 5; i < 101; i++)
        P[i] = P[i - 1] + P[i - 5];
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << P[N] << '\n';
    }

    return 0;
}