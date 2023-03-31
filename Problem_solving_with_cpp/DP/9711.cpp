#include <bits/stdc++.h>
using namespace std;
long long dp[10001];
long long T, P, Q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> T;
    for(int j = 1; j <= T; j++)
    {
        cin >> P >> Q;
        dp[1] = 1 % Q;
        dp[2] = 1 % Q;
        for (int i = 3; i <= P; i++) dp[i] = (dp[i - 2] + dp[i - 1])%Q;
        cout << "Case #" << j << ": " << dp[P] << '\n';
    }
    
    return 0;
}

