#include <bits/stdc++.h>
using namespace std;
long long A, B;
int ans;
void dfs(long long cur, int cnt)
{
    if (cur > B)
        return;
    else if (cur == B)
    {
        if (ans == -1 || ans > cnt)
            ans = cnt;
        return;
    }
    else
    {
        dfs(cur * 2, cnt + 1);
        dfs(cur * 10 + 1, cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    ans = -1;
    dfs(A, 1);
    cout << ans << '\n';
    return 0;
}