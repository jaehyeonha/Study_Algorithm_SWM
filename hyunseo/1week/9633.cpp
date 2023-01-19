#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> board(16);

bool is_good(int row, int i)
{
    for (int j = 0; j < row; j++)
        // 같은 행에 있지 않고, 대각선 상에 있지 않은 배치.
        if (board[j].second == i ||
            abs(board[j].second - i) ==
                abs(board[j].first - row))
            // 만약 놓은 판단이 맞았다면 다음 것도 놓아본다.
            return false;
    return true;
}

int N, counter = 0;
// row 행에서 nqueen을 넣은 곳을 판단하겠다.
void nqueen(int row)
{
    // nqueen의 row가 N이라면 끝내야 한다. 판을 넘어간 것이기 때문이다.
    if (row >= N)
    {
        counter++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        // 우선 row에 대해서 싹다 검사를 해보아야 한다.
        board[row] = make_pair(row, i);

        // 해당 (row, i)에 퀸을 둔 것이 가능한 일인가?
        if (is_good(row, i))
            nqueen(row + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    nqueen(0);

    cout << counter;

    return 0;
}