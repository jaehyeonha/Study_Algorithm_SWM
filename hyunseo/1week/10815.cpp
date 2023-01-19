#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;

    vector<int> N_C(N);
    for (int i = 0; i < N; i++)
        cin >> N_C[i];

    cin >> M;
    vector<int> M_C(M);
    for (int i = 0; i < M; i++)
        cin >> M_C[i];

    sort(N_C.begin(), N_C.end());

    for (int i = 0; i < M; i++)
    {
        if (binary_search(N_C.begin(), N_C.end(), M_C[i]))
            cout << (M_C[i] == M_C[M - 1] ? "1" : "1 ");
        else
            cout << (M_C[i] == M_C[M - 1] ? "0" : "0 ");
    }

    // for (const auto &M_element : M_C)
    // {
    //     if (any_of(N_C.begin(), N_C.end(), [=](int &N_C_i)
    //                { return N_C_i == M_element; }))
    //         cout << (M_element == M_C[M - 1] ? "1" : "1 ");
    //     else
    //         cout << (M_element == M_C[M - 1] ? "0" : "0 ");
    // }

    return 0;
}