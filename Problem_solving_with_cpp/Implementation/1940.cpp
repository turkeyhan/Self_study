#include <bits/stdc++.h>
using namespace std;
int N, M;
int num[15001];
int ans;
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (num[i] + num[j] == M)
                ans++;
    cout << ans << '\n';
    return 0;
}