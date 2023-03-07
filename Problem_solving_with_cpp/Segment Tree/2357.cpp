#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
int Max_Tree[MAX];
int Min_Tree[MAX];
int N, M, tmp;
int s, e;
int arr[100001];
int Make_MAX_segment_Tree(int start, int end, int Node)
{
    if (start == end)
        return Max_Tree[Node] = arr[start];
    int mid = (start + end) / 2;
    int a = Make_MAX_segment_Tree(start, mid, 2 * Node);
    int b = Make_MAX_segment_Tree(mid + 1, end, 2 * Node + 1);
    return Max_Tree[Node] = max(a, b);
}
int Make_Min_segment_Tree(int start, int end, int Node)
{
    if (start == end)
        return Min_Tree[Node] = arr[start];
    int mid = (start + end) / 2;
    int a = Make_Min_segment_Tree(start, mid, 2 * Node);
    int b = Make_Min_segment_Tree(mid + 1, end, 2 * Node + 1);
    return Min_Tree[Node] = min(a, b);
}
int Find_MAX(int start, int end, int left, int right, int Node)
{
    if (left > end  || right < start) return 0;
    if (left <= start && end <= right) return Max_Tree[Node];
    int mid = (start + end) / 2;
    return max(Find_MAX(start, mid, left, right, 2 * Node), Find_MAX(mid + 1, end, left, right, 2 * Node + 1));
}
int Find_Min(int start, int end, int left, int right, int Node)
{
    if (left > end || right < start) return 1e9;
    if (left <= start && end <= right) return Min_Tree[Node];
    int mid = (start + end) / 2;
    return min(Find_Min(start, mid, left, right, 2 * Node), Find_Min(mid + 1, end, left, right, 2 * Node + 1));
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    Make_MAX_segment_Tree(1, N, 1);
    Make_Min_segment_Tree(1, N, 1);
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e;
        int Mi = Find_Min(1, N, s, e, 1);
        int Ma = Find_MAX(1, N, s, e, 1);
        cout << Mi << ' ' << Ma << '\n';
    }
    return 0;
}