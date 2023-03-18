#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {0, 1, -1, 0};
vector<int> dy = {1, 0, 0, -1};

int R, C;
vector<int> visited(26, 0);
int answer = 0;

typedef vector<vector<char>> matrix_t;

int cnt = 1;

void dfs(int x, int y, matrix_t& W){
	
	answer = max(answer,cnt);

	for (int i = 0; i < 4; i++)
    {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < R && yy >= 0 && yy < C)
                if (visited[W[xx][yy]-65] == 0)
                {  
                    visited[W[xx][yy]-65] = 1;
					cnt++;
                    dfs(xx, yy, W);

					visited[W[xx][yy]-65] = 0;
					cnt--;
                }
    }
}

int main()
{
    cin >> R >> C;
	matrix_t W(R, vector<char>(C, 0));

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> W[i][j];
		}
	}

	visited[W[0][0]-65] = 1;
	dfs(0,0, W);

	cout << answer << endl;
}