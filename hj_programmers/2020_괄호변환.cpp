#include <iostream>
#include <string>

using namespace std;

string solution(string w) {
	string answer = "";
	int left = 0, right = 0;
	bool check = false;
	if (w.length() == 0) return answer;
	for (int i = 0; i < w.length(); i++) {
		if (w[i] == '(') left++;
		if (w[i] == ')') right++;
		if (right > left) check = true;
		if (left == right) {
			if (check) {
				answer += "(";
				answer += solution(w.substr(i + 1));
				answer += ")";
				for (int j = 1; j < i; j++) {
					if (w[j] == '(') answer += ")";
					else if (w[j] == ')') answer += "(";
				}
			}
			else {
				answer += w.substr(0, i + 1);
				answer += solution(w.substr(i + 1));
			}
			return answer;
		}
	}
	return answer;
}
int main() {
	cout << solution("(()())()") << endl;
}
