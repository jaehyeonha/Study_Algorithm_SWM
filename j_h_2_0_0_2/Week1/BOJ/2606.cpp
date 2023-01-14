#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> matrix_t;

int main()
{
    int T, count = 0;
    cin >> T;

    vector<int> visited(T + 1, 0);
    matrix_t W(T + 1, vector<int>(T + 1, 0));
    queue<int> q;

    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int u, v;
        cin >> u >> v;
        W[u][v] = W[v][u] = 1;
    }

    int com = 1;
    q.push(com);
    visited[com] = 1;

    while(!q.empty()){
        int virus = q.front();
        for(int i = 1; i <= T; i++){
            if(W[virus][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                count++;
            }
        }
        q.pop();
    }

    cout << count << endl;

}