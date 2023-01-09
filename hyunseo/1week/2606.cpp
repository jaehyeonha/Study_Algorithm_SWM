#include <iostream>
#include <vector>

using namespace std;

#define MAX_COM_SIZE 100

vector<bool> visited(MAX_COM_SIZE + 1, false);
vector<vector<bool>> graph(MAX_COM_SIZE + 1, vector<bool>(MAX_COM_SIZE + 1, false));

int N, M;

void dfs(int x)
{
    visited[x] = true;

    for (int i = 1; i <= N; i++)
    {
        if (graph[x][i] && !visited[i])
            dfs(i);
    }
}

int main()
{
    cin >> N >> M;

    int N_1, N_2;

    for (int i = 0; i < M; i++)
    {
        cin >> N_1 >> N_2;
        graph[N_1][N_2] = true, graph[N_2][N_1] = true;
    }

    int virus_computer = 1;

    dfs(virus_computer);

    auto current = visited.begin();
    int i = 0, virus_counter = 0;

    while ((current + i++) != visited.begin() + N)
    {
        if (i != virus_computer && *(current + i))
            virus_counter++;
    }

    cout << virus_counter << endl;

    return 0;
}