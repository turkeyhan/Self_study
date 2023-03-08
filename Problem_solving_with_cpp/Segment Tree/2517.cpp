#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> arr[500001];
int Tree[2000001];
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
void Update(int start, int end, int node, int cur)
{
    if (cur < start || cur > end)
        return;
    Tree[node]++;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    Update(start, mid, 2 * node, cur);
    Update(mid + 1, end, 2 * node + 1, cur);
}
int Find_Grade(int start, int end, int node, int cur)
{
    if (cur > end)
        return Tree[node];
    if (start > cur || start == end)
        return 0;
    int mid = (start + end) / 2;
    return Find_Grade(start, mid, 2 * node, cur) + Find_Grade(mid + 1, end, 2 * node + 1, cur);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++)
        arr[i].first = i;
    sort(arr + 1, arr + N + 1, compare);

    for (int i = 1; i <= N; i++)
    {
        cout << i - Find_Grade(1, N, 1, arr[i].first) << '\n';
        Update(1, N, 1, arr[i].first);
    }
    return 0;
}