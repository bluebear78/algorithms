#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();
	for (int i = 1; i <= (s.length() / 2); i++) {
		string result = "";
		string pre = s.substr(0, i);
		int count = 1;
		for (int j = i; j <= s.length(); j = j + i) {
			cout << "_ : " << s.substr(j, i) << endl;
			if (pre == s.substr(j, i)) {
				cout << "1" << endl;
				count++;
			}
			else {
				cout << "2" << endl;
				if (count == 1) {
					cout << "3" << endl;
					result += pre;
					cout << "33 " << result << endl;
				}
				else {
					cout << "4" << endl;
					cout << "44 " << result << endl;
					result += (to_string(count) + pre);
				}
				pre = s.substr(j, i);
				count = 1;
			}
		}
		/* if (s.length() / i != 0){
			result += s.substr((s.length() / i) * i);
		} */
		cout << "# " << result << endl << endl;
		answer = min(answer, (int)result.length());
	}

	return answer;
}



int main() {
	
	cout << solution("aabbacccc") << endl;
	//cout << solution("ababcdcdababcdcd") << endl;
	//cout << solution("abcabcdede") << endl;
	//cout << solution("abcabcabcabcdededededede") << endl;
	//cout << solution("xababcdcdababcdcd") << endl;  
	//cout << solution("aaaaaaaaaa");
	//cout << solution("aaa");
	// 5;
	return 0;
}
 