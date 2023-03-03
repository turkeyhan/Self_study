#include <bits/stdc++.h>
using namespace std;
int N;
int ans;
string str;
vector<string> v[26];
bool compare(string a, string b)
{
    return a.size() < b.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        v[str[0] - 'a'].push_back(str);
    }
    for (int i = 0; i < 26; i++)
        sort(v[i].begin(), v[i].end(), compare);

    for (int i = 0; i < 26; i++)
    {
        int Size = v[i].size();
        if (!Size)
            continue;
        else if (Size == 1)
            ans++;
        else
        {
            ans += Size;
            for (int j = 0; j < Size - 1; j++)
            {
                bool b = true;
                bool check = true;
                int S = v[i][j].size();
                for (int k = j + 1; k < Size; k++)
                {
                    b = true;
                    if (!check)
                        break;
                    for (int m = 1; m < S; m++)
                    {
                        if (v[i][j][m] != v[i][k][m])
                        {
                            b = false;
                            break;
                        }
                    }
                    if (b)
                    {
                        check = false;
                        ans--;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}