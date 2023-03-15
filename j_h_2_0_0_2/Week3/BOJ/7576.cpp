#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {0, 1, -1, 0};
vector<int> dy = {1, 0, 0, -1};

typedef vector<vector<int>> matrix_t;

int main()
{
    int M, N;
    cin >> M >> N;

    int count = 0;
    matrix_t W(N, vector<int>(M, 0));
    matrix_t visited(N, vector<int>(M, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> W[i][j];
            if(W[i][j]==1){
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < N && yy >= 0 && yy < M)
                if (W[xx][yy] == 0 && visited[xx][yy] == 0)
                {   
                    visited[xx][yy] = visited[x][y] + 1;
                    q.push({xx, yy});
                }
        }
            
        q.pop();
    }

    bool tomato = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(W[i][j] != -1 && visited[i][j]==0)
            {
                tomato = false;
            }
            else
            {
                count = max(count, visited[i][j]);
            }
        }
    }

    if(tomato)
        cout << count-1 << endl;
    else
        cout << -1 << endl;
    return 0;
}