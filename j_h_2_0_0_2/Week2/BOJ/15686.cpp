#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

vector<pair<int, int>> Chicken, House;
vector<int> visited;

int N, M;
int min_sum = 99999999;

void find()
{
    int sum = 0;
    for (int i = 0; i < House.size(); i++)
    {
        int x = House[i].first;
        int y = House[i].second;
        int min_dist = 99999999;

        for (int j = 0; j < Chicken.size(); j++)
        {
            if (visited[j] == 1)
            {
                int xx = Chicken[j].first;
                int yy = Chicken[j].second;
                int dist = abs(xx - x) + abs(yy - y);

                min_dist = min(dist, min_dist);
            }
        }

        sum += min_dist;
    }
    min_sum = min(sum, min_sum);
}

void dfs(int x, int depth)
{
    if (depth == M)
    {   
        find();
    }

    for (int i = x; i < Chicken.size(); i++)
    {
        visited[i] = 1;
        dfs(i + 1, depth + 1);

        visited[i] = 0;
    }
}

int main()
{
    cin >> N >> M;

    matrix_t W(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
            if (W[i][j] == 1)
            {
                House.push_back({i, j});
            }
            else if (W[i][j] == 2)
            {
                Chicken.push_back({i, j});
                visited.push_back(0);
            }
        }
    }

    dfs(0, 0);

    cout << min_sum << endl;

    return 0;
}