#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, sum = 0;
    vector<int> P_i(1000, 0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> P_i[i];

    sort(P_i.begin(), P_i.begin() + N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            sum += P_i[j];

    cout << sum << endl;
    return 0;
}