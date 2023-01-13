#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> matrix_t;

int main() {
	int N, T;
	cin >> N >> T;

    matrix_t DP(N+1, vector<int>(T+1 ,0));
    vector <int> W(N+1);
    vector <int> V(N+1);

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++){
        for (int j = 1; j <= T; j++)
        {
            if (j >= W[i])
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[N][T] << endl;
    return 0;

}