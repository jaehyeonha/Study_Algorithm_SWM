#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    int x1, y1, r1;
    int x2, y2, r2;
    double dis;
    vector<int> result;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x1 >> y1;
        cin >> r1;
        cin >> x2 >> y2;
        cin >> r2;

        dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        if (x1 == x2 && y1 == y2 && r1 == r2)
            result.push_back(-1);
        else
        {
            if (dis == abs(r1 - r2) || dis == r1 + r2)
                result.push_back(1);
            else if (dis < abs(r1 - r2) || dis > r1 + r2)
                result.push_back(0);
            else
                result.push_back(2);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (i == result.size() - 1)
            cout << result[i];
        else
            cout << result[i] << endl;
    }
    return 0;
}