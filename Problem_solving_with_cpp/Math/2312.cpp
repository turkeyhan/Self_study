#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N;
        int tmp = N;
        for (int i = 2; i <=tmp; i++)
        {
            while (!(tmp % i))
            {
                tmp /= i;
                arr[i]++;
            }
        }
        for (int i = 2; i <= N; i++)
        {
            if (arr[i])
            {
                cout << i << ' ' << arr[i] << '\n';
                arr[i] = 0;
            }
        }
        
    }
    return 0;
}