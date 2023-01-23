#include <bits/stdc++.h>

using namespace std;
vector<int> v = {1, 2, 3, 4};
vector<bool> s(v.size(), false);

void dfs(int idx, int cnt)
{
    if (cnt == 2)
    {
        for (int i = 0; i < v.size(); i++)
            if (s[i])
                cout << v[i] << " ";
        cout << endl;
    }

    // bound를 높여가면서 해야 한다.
    for (int i = idx; i < v.size(); i++)
    {
        s[i] = true;
        dfs(i + 1, cnt + 1); // cnt가 3이 되는 순간 출력만 해주면 된다.
        s[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dfs(0, 0);

    return 0;
}

// 1 2 3 4 5
// 1 2 3
// 1 2 4
// 1 2 5