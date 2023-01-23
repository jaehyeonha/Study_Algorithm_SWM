#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;

    vector<int> input, fibo, result;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        input.push_back(n);
    }

    int max = *max_element(input.begin(), input.end());

    fibo.push_back(0);
    fibo.push_back(1);

    while (fibo.back() < max)
        fibo.push_back(fibo[fibo.size() - 1] + fibo[fibo.size() - 2]);

    for (int i = 0; i < T; i++)
    {
        for (int j = fibo.size() - 1; j > 0; j--)
        {
            if (input[i] >= fibo[j])
            {
                result.push_back(fibo[j]);
                input[i] -= fibo[j];
            }
        }

        for (int j = result.size() - 1; j >= 0; j--)
            cout << result[j] << ((j == 0) ? "" : " ");

        if (result.size() == 0)
            cout << 0 << endl;
        else
            cout << endl;

        result.clear();
    }

    return 0;
}