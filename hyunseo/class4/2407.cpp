#include <bits/stdc++.h>

int n, m;
using namespace std;

vector<vector<string>> dp(101, vector<string>(101, "0"));

string bigAdd(string n1, string n2)
{
    int sum = 0;
    string result;
    while (!n1.empty() || !n2.empty() || sum)
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string comb(int n, int r)
{
    if (n == r || r == 0)
        return "1";

    string &tmp = dp[n][r];
    if (tmp != "0")
        return tmp;

    tmp = bigAdd(comb(n - 1, r - 1), comb(n - 1, r));
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    cout << comb(n, m);

    return 0;
}