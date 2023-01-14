#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int N, Target;
using namespace std;

void dfs(vector<int> numbers, int target, int sum, int index, int &answer)
{
    if (index >= numbers.size())
    {
        if (sum == target)
            answer++;

        return;
    }

    dfs(numbers, target, sum + numbers[index], index + 1, answer);
    dfs(numbers, target, sum - numbers[index], index + 1, answer);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}

int main()
{
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    cin >> Target;

    cout << solution(numbers, Target) << endl;

    return 0;
}