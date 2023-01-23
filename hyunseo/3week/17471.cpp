#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

template <typename T>
void cpout(T v) { cout << v << '\n'; }

string s[5] = {
    "",
    "A+=A",
    "A+=B",
    "B+=A",
    "B+=B"};

vi v;
int cnt = 0;

/**
 * @brief v가 홀수가 될 때까지 계속 나누어 주는 함수 ( divide process )
 *
 * @param v
 * @param type type이 true면 A를, false면 B를 나누어 준다.
 *
 */
void divide_p(ll &v2, bool type)
{
    while (~v2 & 1)
    {
        cnt++;
        v2 >>= 1LL;
        if (type)
            v.push_back(4);
        else
            v.push_back(1);
    }
}

int main()
{
    fastio;

    ll a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << cnt;
        return 0;
    }

    divide_p(a, true);

    divide_p(b, false);

    while (a ^ b)
    {
        if (a > b)
        {
            a += b;
            cnt++;
            v.push_back(2);
        }
        else
        {
            b += a;
            cnt++;
            v.push_back(3);
        }

        divide_p(a, true);
        divide_p(b, false);
    }

    cout << cnt << '\n';
    for (auto i : v)
        cout << s[i] << '\n';

    return 0;
}