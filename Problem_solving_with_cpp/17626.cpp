#include <bits/stdc++.h>
using namespace std;
int dp[51000];
queue<int> q;
int n;
void four_squares(int num, int cnt)
{
    if (cnt == 4)
        return;
    for (int i = 1; i < 225; i++)
    {
        if (num + i * i > 50000)
            break;
        else if (!dp[num + i * i] || dp[num + i * i] > cnt + 1)
        {
            dp[num + i * i] = cnt + 1;
            four_squares(num + i * i, cnt + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    for (int i = 1; i < 225; i++)
        four_squares(0, 0);

    cout << dp[n] << '\n';
    return 0;
}