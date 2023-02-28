#include <bits/stdc++.h>
using namespace std;
int N, L;
int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long sum = 0;
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    int cnt = 0;
    int left = 1, right = 1;
    while (right <= N)
    {
        if (right - left == L)
        {
            sum -= arr[left];
            sum += arr[right];
            left++;
            right++;
        }
        else
        {
            sum += arr[right];
            right++;
        }
        if (129 <= sum && sum <= 138)
            cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
