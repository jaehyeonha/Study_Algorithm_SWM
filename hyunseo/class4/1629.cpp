#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int rec(int a, int b, int c)
{
    if (b == 1)
        return a % C;

    long long temp = rec(a, b / 2, c);

    if (b % 2 == 1)
        return ((temp * temp) % C * a) % C;
    else
        return (temp * temp) % C;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    cout << rec(A, B, C);

    return 0;
}