#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> psi;

#define INF 1e9

int N;
vector<int> number(11);
vector<psi> op = {make_pair("+", 0),
                  make_pair("-", 0),
                  make_pair("*", 0),
                  make_pair("/", 0)};

// 연산자들
int max_r = -INF, min_r = INF;

void dfs(int ans, int depth)
{
    if (depth == N)
    {
        if (ans > max_r)
            max_r = ans;
        if (ans < min_r)
            min_r = ans;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i].second > 0)
        {
            op[i].second--;
            if (op[i].first == "+")
                dfs(ans + number[depth], depth + 1);
            else if (op[i].first == "-")
                dfs(ans - number[depth], depth + 1);
            else if (op[i].first == "*")
                dfs(ans * number[depth], depth + 1);
            else if (op[i].first == "/")
                dfs(ans / number[depth], depth + 1);
            op[i].second++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> number[i];

    int a;
    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        op[i].second = a;
    }

    dfs(number[0], 1);

    cout << max_r << endl
         << min_r;

    return 0;
}