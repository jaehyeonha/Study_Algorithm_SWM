#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, S;
vector<int> sequence(20, 0);
int counter = 0;

void subset_sum(int n, int sum)
{
    // 백트래킹으로 하나씩 sequence를 타고 들어가야 한다.
    // n은 sequence의 index이다.

    // sum은 백트래킹 하면서 구한 각 과정마다의 합이다.

    if (n >= N)
    {
        if (sum == S)
            counter++;

        return;
    }

    subset_sum(n + 1, sum);
    subset_sum(n + 1, sum + sequence[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> sequence[i];

    subset_sum(0, 0);

    // 싹다 0인 경우는 제외해야함.

    if (S == 0)
        counter--;

    cout << counter;

    return 0;
}