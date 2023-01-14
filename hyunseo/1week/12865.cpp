#include <iostream>
#include <vector>

using namespace std;

class Object
{
    int weight;
    int value;

public:
    Object(int weight, int value) : weight(weight), value(value) {}

    int getWeight() { return weight; }
    int getValue() { return value; }

    friend ostream &operator<<(ostream &os, const Object &obj)
    {
        os << "[ " << obj.weight << ", " << obj.value << " ]";
        return os;
    }
};

template <typename T>
void print_table(T &table)
{
    for (int i = 1; i < table.size(); i++)
    {
        for (int j = 1; j < table[i].size(); j++)
            cout << table[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int N, K;
    int W, V;

    cin >> N >> K;
    vector<Object> objects(N + 1, Object(0, 0));
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        cin >> W >> V;
        objects[i] = Object(W, V);
        // cout << objects[i] << endl;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            int j_weight = objects[i].getWeight();
            int j_value = objects[i].getValue();
            if (j >= j_weight)
                dp[i][j] = max(dp[i - 1][j],
                               j_value + dp[i - 1][j - j_weight]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K] << endl;

    // print_table(dp);

    return 0;
}