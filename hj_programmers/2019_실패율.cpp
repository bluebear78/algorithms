#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info{
	int num;
	double fail_cnt;
	double user_cnt;
}Info;

bool cmp(Info a, Info b) {
	double aa = (!a.user_cnt) ? 0 : (a.fail_cnt / a.user_cnt);
	double bb = (!b.user_cnt) ? 0 : (b.fail_cnt / b.user_cnt);
	if (aa == bb)
		return a.num < b.num;
	return aa > bb;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<Info> cnt_stage(N+2); // N개의 stage
	int size = cnt_stage.size(); 
	int tot_user = stages.size();
	for (int i = 1; i < size; i++)// 초기값
		cnt_stage[i].num = i;
	for (int i = 0; i < stages.size(); i++) 
		cnt_stage[stages[i]].fail_cnt++;
	for (int i = 1; i < cnt_stage.size()-1; i++) {
		cnt_stage[i].user_cnt = tot_user;
		tot_user -= cnt_stage[i].fail_cnt;
	}
	sort(cnt_stage.begin()+1, cnt_stage.end()-1, cmp);
	for (int i = 1; i < size - 1; i++) 
		answer.push_back(cnt_stage[i].num);
	return answer;
}

int main() {
	solution(5, { 2,1,2,6,2,4,3,3});
	return 0;
}