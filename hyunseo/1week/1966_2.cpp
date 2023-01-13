#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main()
{
    int testn;
    int n, m;
    int importance;
    int count;

    cin >> testn;

    for (int i = 0; i < testn; i++)
    {
        count = 0;
        cin >> n >> m;

        multiset<int, greater<int>> s;
        queue<pair<int, int>> q;

        for (int j = 0; j < n; j++)
        {
            cin >> importance;
            q.push(make_pair(j, importance));
            s.insert(importance);
        }

        // 큐가 비지 않을때까지.
        while (!q.empty())
        {
            int location = q.front().first;
            int value = q.front().second;
            q.pop();

            multiset<int>::iterator first = s.begin();
            if (*first == value)
            {
                s.erase(first);
                ++count;
                if (location == m)
                {
                    cout << count << endl;
                    break;
                }
            }
            else
                q.push(make_pair(location, value));
        }
    }
    return 0;
}