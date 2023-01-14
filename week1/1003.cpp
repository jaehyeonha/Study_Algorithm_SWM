#include<iostream>
#include<vector>

using namespace std;

// vector<pair<int, int>> v(41);

// pair<int, int> fibonacci(int n) {
//   if (n == 0) {
//     return { 1, 0 };
//   } else if (n == 1) {
//     return { 0, 1 };
//   } else {
//     if (v[n].first == 0 && v[n].second == 0) {
//       v[n] = { fibonacci(n - 1).first + fibonacci(n - 2).first, fibonacci(n - 1).second + fibonacci(n - 2).second };
//     }
//     return v[n];
//   }
// }

// int main() {
//   int T, n;
//   cin >> T;

//   for (int i = 0; i < T; i++) {
//     cin >> n;
//     pair<int, int> p = fibonacci(n);
//     cout << p.first << " " << p.second << "\n";
//   }

//   return 0;
// }


vector<int> zero(41);
vector<int> one(41);

void fibonacci(int n) {
  for (int i = 2; i <= n; i++) {
    zero[i] = zero[i - 1] + zero[i - 2];
    one[i] = one[i - 1] + one[i - 2];
  }
}

int main() {
  int T, n;
  cin >> T;

  zero[0] = 1;
  zero[1] = 0;
  one[0] = 0;
  one[1] = 1;

  fibonacci(40);

  for (int i = 0; i < T; i++) {
    cin >> n;
    cout << zero[n] << " " << one[n] << endl;
  }

  return 0;
}
