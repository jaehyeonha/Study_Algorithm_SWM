#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {0, 1, -1, 0};
vector<int> dy = {1, 0, 0, -1};

typedef vector<vector<char>> matrix_t;

int main()
{
    int N, M;
    cin >> N >> M;

    int ts = 0, tw = 0;

    matrix_t W(N, vector<char>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> W[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (W[i][j] != '#' && visited[i][j] == 0)
            {
                int wolf = 0, sheep = 0;
                queue<pair<int, int>> q;

                q.push({i, j});
                visited[i][j] = 1;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;

                    if (W[x][y] == 'k')
                    {
                        sheep++;
                    }
                    else if (W[x][y] == 'v')
                    {
                        wolf++;
                    }

                    for (int i = 0; i < 4; i++)
                    {
                        int xx = x + dx[i];
                        int yy = y + dy[i];
                        if (xx >= 0 && xx < N && yy >= 0 && yy < M)
                            if (W[xx][yy] != '#' && visited[xx][yy] == 0)
                            {
                                visited[xx][yy] = 1;
                                q.push({xx, yy});
                            }
                    }
                    q.pop();
                }
                if (sheep > wolf)
                    ts += sheep;
                else
                    tw += wolf;
            }
        }
    }

    cout << ts << " " << tw << endl;

    return 0;
}