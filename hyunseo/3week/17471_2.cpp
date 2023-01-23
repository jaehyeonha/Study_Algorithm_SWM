#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

template <typename T>
void cpout(T v) { cout << v << '\n'; }

int n;
#define INF 2e9

vvi adjac_list(11);
vb visited(11, false);
vi people(11);
vi tmp;

int cost = 0;
int s_cost = 0;
int ans = INF;

bool isConnect(bool isA)
{
    tmp.erase(tmp.begin(), tmp.end());

    for (int i = 1; i <= n; i++)
    {
        if (isA && visited[i])
            tmp.push_back(i);

        if (!isA && !visited[i])
            tmp.push_back(i);
    }

    queue<int> q;
    vb visited2(11, false);
    int checker = 0;

    q.push(tmp[0]);
    visited2[tmp[0]] = true;
    checker++;

    while (!q.empty())
    {
        int nx = q.front();
        q.pop();

        for (auto next_ : adjac_list[nx])
        {
            if (isA)
                // next_를 방문했거나, visited에 next_가 false라면 continue
                if (visited2[next_] || !visited[next_])
                    continue;
            if (!isA)
                if (visited2[next_] || visited[next_])
                    continue;

            q.push(next_);
            visited2[next_] = true;
            checker++;
        }
    }

    // for (auto i : tmp)
    //     cout << i << ' ';
    // cout << '\n';

    // cout << "checker: " << checker << ", "
    //      << "tmp.size(): " << tmp.size() << endl;
    if (checker == tmp.size())
        return true;

    return false;
}

bool isTwoBothPartySameParent()
{
    return (isConnect(true) && isConnect(false));
}

void compareAndRenew(int cost1, int cost2)
{
    if (ans > abs(cost1 - cost2))
        ans = abs(cost1 - cost2);
}

void rec_dfs(int index, int count)
{
    if (count >= 1)
    {
        if (isTwoBothPartySameParent())
        {
            cost = 0;
            for (int i = 1; i <= n; i++)
            {
                if (visited[i])
                    cost += people[i];
            }

            compareAndRenew(s_cost - cost, cost);
            // cout << "ans: " << ans << endl;
        }
    }

    for (int i = index; i <= n; i++)
    {
        visited[i] = true;
        rec_dfs(i + 1, count + 1);
        visited[i] = false;
    }
}

int main()
{
    fastio;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> people[i];
        s_cost += people[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int a;
            cin >> a;
            adjac_list[i].push_back(a);
        }
    }

    rec_dfs(1, 0);

    if (ans == INF)
        cout << "-1";
    else
        cout << ans;

    return 0;
}