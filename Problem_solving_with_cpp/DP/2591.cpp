#include <bits/stdc++.h>
using namespace std;
string str;
int dp[41][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str;
    int Size = str.size();
    dp[0][0] = 1;
    if (str[0] - '0' <= 3)
        dp[0][1] = 1;
    for (int i = 1; i < Size; i++)
    {
        if (str[i] - '0' >= 1 && str[i] - '0' <= 3)
            dp[i][1] = dp[i - 1][0];
        if (str[i] - '0' == 0)
            dp[i][0] = dp[i - 1][1];
        else
        {
            if ((str[i - 1] - '0' <= 2) || ((str[i - 1] - '0' == 3) && (str[i] - '0' <= 4)))
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            else
                dp[i][0] = dp[i - 1][0];
        }
    }

    cout << dp[Size - 1][0] << '\n';
    return 0;
}