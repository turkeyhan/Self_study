#include <bits/stdc++.h>
using namespace std;
int N;
vector <string> v;
string str;
bool cmp(string a, string b)
{
    if (a.size() == b.size())
    {
        int a_sum = 0;
        int b_sum = 0;
        for (int i = 0; i < a.size(); i++) if ('0' < a[i] && a[i] <= '9') a_sum += (a[i] - '0');
        for (int i = 0; i < b.size(); i++) if ('0' < b[i] && b[i] <= '9') b_sum += (b[i] - '0');
        if (a_sum == b_sum) return a < b;
        else return a_sum < b_sum;
    }
    else return a.size() < b.size();
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
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) cout << v[i] << '\n';
    return 0;
}

