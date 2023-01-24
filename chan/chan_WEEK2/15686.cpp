#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct xy {
	int x, y;
};

int N, M;
bool check[13];
vector<xy> house;
vector<xy> pick;
vector<xy> chicken;
int Min = 999999999;


//M개 치킨집 조합 구하기
void getchicken(int x, int cnt) {
	if (cnt == M) { //M과 같을 때 치킨 거리 구함
		int res = 0;
		for (int i = 0; i < house.size(); i++) {
			int Min_dist = 999999999;
			//각 집에서 가장 가까운 치킨집 찾기
			for (int j = 0; j < pick.size(); j++) {
				Min_dist = min(Min_dist, abs(house[i].x - pick[j].x) + abs(house[i].y - pick[j].y));
			}
			res += Min_dist;
		}
		Min = min(Min, res);
		return;
	}
    //모든 치킨 집을 다 넣어서 계산 해봄
	for (int i = x; i < chicken.size(); i++) {
		if (check[i] == true)
			continue;
		check[i] = true;
		pick.push_back({ chicken[i].x,chicken[i].y });
		getchicken(i, cnt + 1);
		check[i] = false;
		pick.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			scanf("%d", &n);
			if (n == 1)
				house.push_back({ i,j });
			else if (n == 2)
				chicken.push_back({ i,j });
		}
	}
	getchicken(0, 0);
	cout << Min << '\n';
	return 0;
}