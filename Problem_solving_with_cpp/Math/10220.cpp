#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        if (N == 1 || N == 2 || N == 3 || N == 6)
            cout << "0" << endl;
        else if (N == 4)
            cout << "2" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}