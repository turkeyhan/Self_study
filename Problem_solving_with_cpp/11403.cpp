#include <bits/stdc++.h>
using namespace std;
int N, tmp;
int ans[101][101];
vector<int> graph[101];
void search(int start, int cur)
{
    int Size = graph[cur].size();
    vector<int> v;
    for (int i = 0; i < Size; i++)
    {
        if (!ans[start][graph[cur][i]])
        {
            v.push_back(graph[cur][i]);
            ans[start][graph[cur][i]] = 1;
        }
    }
    Size = v.size();
    for (int i = 0; i < Size; i++)
        search(start, v[i]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            if (tmp)
                graph[i].push_back(j);
        }

    for (int i = 0; i < N; i++)
        search(i, i);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}