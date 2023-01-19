#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<vector<char>> shelter(251, vector<char>(251, ' '));
vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> visited(251, vector<bool>(251, false));

int R, C;
int total_wolf = 0, total_sheep = 0;

void find_wolf_sheep()
{
    queue<pair<int, int>> queue;
    int sheep, wolf;

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            // 늑대 아니면 양인데
            if ((shelter[i][j] == 'v' || shelter[i][j] == 'o') && !visited[i][j])
            {
                if (shelter[i][j] == 'v')
                    wolf = 1, sheep = 0;
                else if (shelter[i][j] == 'o')
                    sheep = 1, wolf = 0;

                queue.push(make_pair(i, j));
                visited[i][j] = true;

                while (!queue.empty())
                {
                    int x = queue.front().first, y = queue.front().second;
                    queue.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> nextPos = make_pair(x + dir[k][0], y + dir[k][1]);

                        if (nextPos.first >= 1 && nextPos.first <= R &&
                            nextPos.second >= 1 && nextPos.second <= C &&
                            // 또한 울타리가 아니여야 한다.
                            shelter[nextPos.first][nextPos.second] != '#' &&
                            // 방문했으면 안된다.
                            !visited[nextPos.first][nextPos.second])
                        {
                            if (shelter[nextPos.first][nextPos.second] == 'v')
                                wolf++;
                            else if (shelter[nextPos.first][nextPos.second] == 'o')
                                sheep++;

                            visited[nextPos.first][nextPos.second] = true;
                            queue.push(nextPos);
                        }
                    }
                }

                if (wolf >= sheep)
                    total_wolf += wolf;
                else
                    total_sheep += sheep;

                // std::cout << "total_wolf << " << total_wolf << " total_sheep << " << total_sheep << std::endl;
            }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> shelter[i][j];

    find_wolf_sheep();

    cout << total_sheep << " " << total_wolf << endl;

    return 0;
}