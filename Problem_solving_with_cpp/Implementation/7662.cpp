#include <bits/stdc++.h>
using namespace std;
int T, k, n;
char c;
map<pair<int, int>, bool> m;
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq_top;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_down;

        cin >> k;
        int cnt = 0;
        int minus = 0;
        while (k--)
        {
            cin >> c >> n;

            if (c == 'I')
            {
                cnt++;
                pq_top.push({n, cnt});
                pq_down.push({n, cnt});
                m[{n, cnt}] = true;
            }
            else if (cnt - minus && c == 'D')
            {
                if (n == 1)
                {
                    while (!m[pq_top.top()])
                        pq_top.pop();
                    m[pq_top.top()] = false;
                    pq_top.pop();
                }
                else if (n == -1)
                {
                    while (!m[pq_down.top()])
                        pq_down.pop();
                    m[pq_down.top()] = false;
                    pq_down.pop();
                }
                minus++;
            }
        }
        if (cnt - minus)
        {
            while (!m[pq_top.top()])
                pq_top.pop();
            while (!m[pq_down.top()])
                pq_down.pop();
            cout << pq_top.top().first << ' ' << pq_down.top().first << '\n';
        }
        else
            cout << "EMPTY" << '\n';
    }
    return 0;
}