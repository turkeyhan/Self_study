#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long N, M, K;
long long arr[1000001];
long long Tree[5000001];
long long a, b, c;
long long Init(long long start, long long end, long long node)
{
    if (start == end)
        return Tree[node] = arr[start];
    long long mid = (start + end) / 2;
    return Tree[node] = ((Init(start, mid, 2 * node) % MOD) * (Init(mid + 1, end, 2 * node + 1) % MOD)) % MOD;
}
long long Find_mul(long long start, long long end, long long left, long long right, long long node)
{
    if (end < left || right < start)
        return 1;
    if (left <= start && end <= right)
        return Tree[node];
    long long mid = (start + end) / 2;
    return ((Find_mul(start, mid, left, right, 2 * node) % MOD) * (Find_mul(mid + 1, end, left, right, 2 * node + 1) % MOD)) % MOD;
}
long long Update(long long start, long long end, long long ojidx, long long value, long long node)
{
    if (ojidx < start || ojidx > end)
        return Tree[node];
    if (start == end)
    {
        if (start == ojidx)
            Tree[node] = value;
        return Tree[node];
    }
    long long mid = (start + end) / 2;
    return Tree[node] = ((Update(start, mid, ojidx, value, 2 * node) % MOD) * (Update(mid + 1, end, ojidx, value, 2 * node + 1) % MOD)) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (long long i = 1; i <= N; i++)
        cin >> arr[i];
    Init(1, N, 1);
    for (long long i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            Update(1, N, b, c, 1);
            arr[b] = c;
        }
        else if (a == 2)
            cout << Find_mul(1, N, b, c, 1) << '\n';
    }

    return 0;
}