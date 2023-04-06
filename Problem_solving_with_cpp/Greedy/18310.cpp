#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    if (N % 2) cout << v[N / 2] << '\n';
    else cout << v[N / 2 - 1] << '\n';   
    return 0;
}