#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    vector<int> grd;
    grd.push_back(0);
    grd.push_back(1);
    int i = 2;

    while (1)
    {
        int num = grd[i - 1] + grd[i - 2];
        if (num > 1000000000)
        {
            break;
        }
        grd.push_back(num);
        i++;
    }

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int j = grd.size() - 1; j >= 1; j--)
        {
            if (grd[j] <= n)
            {
                n -= grd[j];
                v.push_back(grd[j]);
            }
        }
        for (int j = v.size() - 1; j >= 0; j--)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }
    return 0;
}