#include <bits/stdc++.h>
using namespace std;
long long N;
long long tmp;
vector<long long> num;
map<long long, int> m;
map<long long, int> Count;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (long long i = 0; i < N; i++)
    {
        cin >> tmp;
        num.push_back(tmp);
    }
    for (long long i = 0; i < N; i++)
    {
        if (!Count.count(num[i]))
            Count[num[i]] = 1;
        else
            Count[num[i]]++;
    }
    for (long long i = 0; i < N - 1; i++)
    {
        for (long long j = i + 1; j < N; j++)
        {
            if (!num[i] || !num[j])
            {
                if (num[i] == num[j])
                {
                    if (Count[num[i]] >= 3)
                        m[0] = 1;
                    else
                        continue;
                }
                else if (!num[i])
                    if (Count[num[j]] >= 2)
                        m[num[j]] = 1;
                    else if (!num[j])
                        if (Count[num[i]] >= 2)
                            m[num[i]] = 1;
                        else
                            continue;
            }
            else
                m[num[i] + num[j]] = 1;
        }
    }
    for (long long i = 0; i < N; i++)
        if (m.count(num[i]))
            ans++;
    cout << ans << '\n';
    return 0;
}