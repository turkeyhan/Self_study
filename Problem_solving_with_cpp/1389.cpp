#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> graph[101];
int a, b;
int visited[101];
int ans = 1e9;
int ans_num;

void Bfs(int num)
{
    int cnt = 1;
    visited[num] = 1;
    queue<int> q;
    int Size = graph[num].size();
    for (int i = 0; i < Size; i++)
        q.push(graph[num][i]);
    int sum = Size;
    while (1)
    {
        Size = q.size();
        if (!Size)
            break;
        cnt++;
        for (int i = 0; i < Size; i++)
        {
            int idx = q.front();
            q.pop();
            visited[idx] = 1;
            int S = graph[idx].size();
            for (int j = 0; j < S; j++)
            {
                if (!visited[graph[idx][j]])
                {
                    q.push(graph[idx][j]);
                    sum += cnt;
                }
            }
        }
    }
    if (ans > sum)
    {
        ans = sum;
        ans_num = num;
    }
}
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        Bfs(i);
        for (int j = 0; j < 101; j++)
            visited[j] = 0;
    }
    cout << ans_num << '\n';
    return 0;
}