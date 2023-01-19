#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;
queue<int> q;
vector<int> v(1000000, 0);

int bfs()
{
    q.push(S);
    v[S] = 1;

    while (!q.empty())
    {
        int p;
        if ((p = q.front()) == G)
            return v[p] - 1;

        q.pop();

        for (int i = 0; i < 2; i++)
        {
            int next = p + (i == 0 ? U : -D);
            if (next <= F && next >= 1 && v[next] == 0)
            {
                q.push(next);
                v[next] = v[p] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    int value = bfs();
    if (value == -1)
        cout << "use the stairs";
    else
        cout << value;

    return 0;
}