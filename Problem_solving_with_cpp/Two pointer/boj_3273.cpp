#include <bits/stdc++.h>
using namespace std;
int n, x;
int arr[100001];
int cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    sort(arr, arr + n);
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int sum = arr[s] + arr[e];
        if (sum == x) cnt++;
        if (sum <= x) s++;
        else e--;
    }
    cout << cnt << '\n';
    return 0;
}

