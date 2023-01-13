#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename P>
void fibonacci(T n, vector<P> &fibo)
{
    if (n == 0)
        fibo[0];
    else if (n == 1)
        fibo[1];
    else
        for (int i = 2; i <= n; i++)
            fibo[i] = make_pair(fibo[i - 1].first + fibo[i - 2].first,
                                fibo[i - 1].second + fibo[i - 2].second);
}

int main()
{
    int test_num, N;
    vector<pair<int, int>> fibo(41, make_pair(0, 0));
    fibo[0] = make_pair(1, 0), fibo[1] = make_pair(0, 1);

    cin >> test_num;
    for (int i = 0; i < test_num; i++)
    {
        cin >> N;
        fibonacci(N, fibo);
        cout << fibo[N].first << " " << fibo[N].second << endl;
    }

    return 0;
}