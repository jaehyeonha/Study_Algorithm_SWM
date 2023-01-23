#include <bits/stdc++.h>

using namespace std;
int N;

void rec(int i, int j, int n)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
    {
        cout << ' ';
        return;
    }

    if (n / 3 == 0)
    {
        cout << '*';
        return;
    }

    rec(i, j, n / 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            rec(i, j, N);
        cout << '\n';
    }

    return 0;
}