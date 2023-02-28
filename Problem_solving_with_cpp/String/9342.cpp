#include <bits/stdc++.h>
using namespace std;
int T;
string str;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> str;
        int Size = str.size();
        int Cond = 0;
        bool b = true;

        for (int i = 0; i < Size; i++)
        {
            if (!Cond)
            {
                if (str[i] == 'A')
                    Cond = 2;
                else if ('A' < str[i] && str[i] <= 'F')
                    Cond = 1;
                else
                {
                    b = false;
                    break;
                }
            }
            else if (Cond == 1 && str[i] == 'A')
                Cond = 2;
            else if (Cond == 2)
            {
                if (str[i] == 'A')
                    continue;
                else if (str[i] == 'F')
                    Cond = 3;
                else
                {
                    b = false;
                    break;
                }
            }
            else if (Cond == 3)
            {
                if (str[i] == 'F')
                    continue;
                else if (str[i] == 'C')
                    Cond = 4;
                else
                {
                    b = false;
                    break;
                }
            }
            else if (Cond == 4)
            {
                if (str[i] == 'C')
                    continue;
                else if ('A' <= str[i] && str[i] <= 'F')
                    Cond = 5;
                else
                {
                    b = false;
                    break;
                }
            }
            else
            {
                b = false;
                break;
            }
        }
        if (b)
            cout << "Infected!" << '\n';
        else
            cout << "Good" << '\n';
    }
    return 0;
}