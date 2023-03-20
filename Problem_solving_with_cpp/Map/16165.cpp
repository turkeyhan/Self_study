#include <bits/stdc++.h>
using namespace std;
int N, M;
int num;
int quiz;
string group, member, q;
map<string, string> m;
map<string, vector<string>> g;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> group;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> member;
            m[member] = group;
            g[group].push_back(member);
        }
        sort(g[group].begin(), g[group].end());
    }
    for (int i = 0; i < M; i++)
    {
        cin >> q;
        cin >> quiz;
        if (quiz)
            cout << m[q] << '\n';
        else
        {
            for (int i = 0; i < g[q].size(); i++)
                cout << g[q][i] << '\n';
        }
    }
    return 0;
}
