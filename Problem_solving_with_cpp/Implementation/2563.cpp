#include <bits/stdc++.h>
using namespace std;
int N;
int ans;
int arr[101][101];
int a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        for (int j = a; j < a + 10; j++)
        {
            for (int k = b; k < b + 10; k++)
            {
                arr[j][k]++;
            }
        }
    }
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (arr[i][j])
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}