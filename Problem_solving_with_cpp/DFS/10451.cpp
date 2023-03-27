#include <bits/stdc++.h>
using namespace std;
int T, N, num;
bool is_cycle(int graph[], int cycle[], int n)
{
    int cur = graph[n];
    for (int i = 1; i <= N; i++)
    {
        if (cycle[cur]) return false;
        else if (cur == n) return true;
        cur = graph[cur];
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        int cnt = 0;
        cin >> N;
        int graph[1010] = { 0 };
        int cycle[1010] = { 0 };
        for (int i = 1; i <= N; i++)
        {
            cin >> num;
            graph[i] = num;
        }
        for (int i = 1; i <= N; i++)
        {
            if (is_cycle(graph, cycle, i))
            {
                cycle[i] = 1;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}

