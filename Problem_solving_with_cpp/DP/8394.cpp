#include <bits/stdc++.h>
using namespace std;
int n;
int dp[10000001][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][0];
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 10;
    }
    cout << (dp[n][1] + dp[n][0]) % 10 << '\n';
    return 0;
}
