#include <bits/stdc++.h>
using namespace std;
int T, n;
string p;
char ch;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> p;
        cin >> n;
        deque<int> d;
        int num = 0;
        int x = 10;
        while (1)
        {
            cin >> ch;
            if (ch == ']')
            {
                if (num)
                    d.push_back(num);
                break;
            }
            else if (ch == '[')
                continue;
            else if (ch == ',')
            {
                d.push_back(num);
                num = 0;
                continue;
            }
            else
            {
                num *= x;
                num += (ch - '0');
            }
        }
        int Size = p.size();
        int r = 1;
        bool err = false;
        for (int i = 0; i < Size; i++)
        {
            if (p[i] == 'R')
                r++;
            else if (p[i] == 'D')
            {
                if (n)
                {
                    if (r % 2)
                        d.pop_front();
                    else
                        d.pop_back();
                    n--;
                }
                else
                {
                    err = true;
                    break;
                }
            }
        }
        if (err)
        {
            cout << "error" << '\n';
            continue;
        }
        else if (r % 2)
        {
            cout << '[';
            for (int i = 0; i < n - 1; i++)
            {
                cout << d.front() << ',';
                d.pop_front();
            }
            if (!d.empty())
                cout << d.front() << "]\n";
            else
                cout << "]\n";
        }
        else
        {
            cout << '[';
            for (int i = 0; i < n - 1; i++)
            {
                cout << d.back() << ',';
                d.pop_back();
            }
            if (!d.empty())
                cout << d.back() << "]\n";
            else
                cout << "]\n";
        }
    }
    return 0;
}