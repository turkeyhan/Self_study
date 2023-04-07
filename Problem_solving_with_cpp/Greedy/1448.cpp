#include <bits/stdc++.h>
using namespace std;
int N;
int num;
vector <int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<>());
    int a = 0, b = 0, c = 0;
    bool flag = false;
    for (int i = 0; i < N - 2; i++)
    {
        a = v[i];
        b = v[i + 1];
        c = v[i + 2];
        if (a < b + c)
        {
            flag = true;
            break;
        }
    }
    if (flag) cout << a + b + c << '\n';
    else cout << -1 << '\n';
    return 0;
}