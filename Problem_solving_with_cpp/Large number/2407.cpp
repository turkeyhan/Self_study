#include <bits/stdc++.h>
using namespace std;
int n, m;
string cb[101][101];

string large_plus(string A, string B)
{
    int N1[50] = {0};
    int N2[50] = {0};
    if (A.size() < B.size())
        swap(A, B);
    string res = "";
    for (int i = 0; i < A.size(); i++)
        N1[i + 1] = A[i] - '0';
    for (int i = 0; i < B.size(); i++)
        N2[i + 1 + A.size() - B.size()] = B[i] - '0';

    for (int i = A.size(); i > 0; i--)
    {
        int sum = N1[i] + N2[i];
        if (sum >= 10)
        {
            N1[i - 1]++;
            sum -= 10;
        }
        string tmp = "0";
        tmp[0] += sum;
        res += tmp;
    }
    string ans = "";
    if (N1[0] == 1)
        ans += "1";
    for (int i = res.size() - 1; i >= 0; i--)
        ans += res[i];
    return ans;
}
void make_combination()
{
    cb[0][0] = "1";
    cb[1][1] = "1";
    cb[1][0] = "1";
    for (int i = 2; i < 101; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j)
                cb[i][j] = "1";
            else if (i == j)
                cb[i][j] = "1";
            else
                cb[i][j] = large_plus(cb[i - 1][j - 1], cb[i - 1][j]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    make_combination();
    cin >> n >> m;
    cout << cb[n][m] << '\n';
    return 0;
}