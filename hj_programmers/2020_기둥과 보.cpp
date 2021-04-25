#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N;

map<tuple<int, int, int>, int> m;

bool cmp(vector<int> v1, vector<int> v2) {
	return  v1[0] == v2[0] ? (v1[1] == v2[1] ? v1[2] < v2[2] : v1[1] < v2[1]) : v1[0] < v2[0];
}
bool check() {
	for (auto r : m) {
		int x, y, a; tie(x, y, a) = r.first;
		if (a == 0) { // 기둥
			if (y == 0 || m.count(make_tuple(x - 1, y, 1)) || m.count(make_tuple(x, y, 1)) || m.count(make_tuple(x, y - 1, 0)))
				continue;
			else
				return false;
		}
		else // 보
		{
			if (m.count(make_tuple(x, y - 1, 0)) || m.count(make_tuple(x + 1, y - 1, 0))
				|| (m.count(make_tuple(x - 1, y, 1)) + m.count(make_tuple(x + 1, y, 1)) == 2))
				continue;
			else
				return false;
		}
	}
	return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (auto build : build_frame) {
		tuple<int, int, int> b = make_tuple(build[0], build[1], build[2]); // (x,y,기둥/보)
		int toggle = build[3]; // 추가/삭제
		if (toggle == 1){ // ADD
			m[b] = true;
			if (!check())
				m.erase(b);
		}
		else {
			m.erase(b);
			if (!check())
				m[b] = true;
		}
	}
	for (auto r : m) {
		int x, y, a; 
		tie(x, y, a) = r.first;
		answer.push_back({ x,y,a });
	}
	sort(answer.begin(), answer.end(), cmp);
	return answer;
}
int main() {
	// map 크기, ( x, y, 기둥/보, 설치/삭제 ) 
	solution(5, { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} });
	//solution(5, { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} });
	return 0;
}