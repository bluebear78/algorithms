#include <vector>

using namespace std;

//이중 벡터 구해서 그냥 bfs차례대로 돌려서 구역 구하면 댐 참 쉽죠-ㅇ-
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	vector<vector<int>> v(10,(10,0));
	

	//	for(:int i)
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;

}
int main() {
	solution(6,4,{ {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });
	return 0;

}