#include <bits/stdc++.h>
using namespace std;
int N;
int M;
int arr[100001];
int Tree[500001];
int a, b;
int init(int start, int end, int node)
{
    if (start == end)
        return Tree[node] = arr[start];
    int mid = (start + end) / 2;
    return Tree[node] = min(init(start, mid, 2 * node), init(mid + 1, end, 2 * node + 1));
}
int Find_min(int start, int end, int left, int right, int node)
{
    if (end < left || right < start)
        return 1e9;
    if (left <= start && end <= right)
        return Tree[node];
    int mid = (start + end) / 2;
    return min(Find_min(start, mid, left, right, 2 * node), Find_min(mid + 1, end, left, right, 2 * node + 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    init(1, N, 1);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << Find_min(1, N, a, b, 1) << '\n';
    }
    return 0;
}