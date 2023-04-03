#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
int n;
int dp[2000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    dp[999999] = 1;
    dp[1000000] = 0;
    dp[1000001] = 1;
    dp[1000002] = 1;
    for (int i = 1000003; i <= 2000000; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    for (int i = 999999; i >= 0; i--)
    {
        if (i % 2) dp[i] = (dp[i + 2] - dp[i + 1]) % MOD;
        else dp[i] = -((-dp[i + 2] + dp[i + 1]) % MOD);
    }
    if (dp[n + 1000000] > 0)
    {
        cout << 1 << '\n';
        cout << dp[n + 1000000] << '\n';
    }
    else if (dp[n + 1000000] == 0)
    {
        cout << 0 << '\n';
        cout << 0 << '\n';
    }
    else
    {
        cout << -1 << '\n';
        cout << -dp[n+1000000] << '\n';
    }
    return 0;
}