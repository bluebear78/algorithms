#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPossible(vector<int> &vec, int now) {
	for (int i = 0; i < vec.size(); i++)
		if ((vec[i] & now) == vec[i]) // 최소 공통
			return false;
	return true;
}

int solution(vector<vector<string>> relation) {
	int n = relation.size();
	int m = relation[0].size();
	vector<int> ans;
	for (int i = 1; i < (1 << m); i++) { // 11111까지
		set<string> s; // set에 넣어서 확인
		for (int j = 0; j < n; j++) { // row size
			string str = "";
			for (int k = 0; k < m; k++) { // column size
				if (i&(1 << k))
					str += relation[j][k]; //
			}
			cout << str << endl;
			s.insert(str);
		}
		// 동일한 게 있는지 검사할 필요 없이 n개인지 검사하면 됨
		if (s.size() == n && isPossible(ans, i)) 
			ans.push_back(i);
	}
	return ans.size();
}

int main() {
	solution({ {"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} });
	return 0;
}
