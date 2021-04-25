#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

#define NONE "0"

using namespace std;

map<string, int> m;
vector<int> v[30];

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	int idx = 0;
	for (string str_info : info) {
		string word; // buf
		stringstream ss(str_info);
		vector<string> tokens;
		while (ss >> word) {
			tokens.push_back(word);
		}

		string language = (tokens[0] == "cpp") ? "1"
			: (tokens[0] == "java") ? "2"
			: (tokens[0] == "python") ? "3"
			: "0";
		string job = (tokens[1] == "backend") ? "1"
			: (tokens[1] == "frontend") ? "2"
			: "0";
		string career = (tokens[2] == "junior") ? "1"
			: (tokens[2] == "senior") ? "2"
			: "0";
		string food = (tokens[3] == "chicken") ? "1"
			: (tokens[3] == "pizza") ? "2"
			: "0";

		string code = language + job + career + food;
		int point = atoi(tokens[4].c_str());


		if (m.find(code) == m.end()) {
			m[code] = idx++;
		}

		v[m[code]].push_back(point);
	}

	// sort
	for (int i = 0; i < idx; i++) {
		sort(v[i].begin(), v[i].end());
	}

	for (string str_query : query) {
		string word;
		stringstream ss(str_query);
		vector<string> tokens;
		while (ss >> word) {
			tokens.push_back(word);
		}

		string language = (tokens[0] == "cpp") ? "1"
			: (tokens[0] == "java") ? "2"
			: (tokens[0] == "python") ? "3"
			: "0";
		string job = (tokens[2] == "backend") ? "1"
			: (tokens[2] == "frontend") ? "2"
			: "0";
		string career = (tokens[4] == "junior") ? "1"
			: (tokens[4] == "senior") ? "2"
			: "0";
		string food = (tokens[6] == "chicken") ? "1"
			: (tokens[6] == "pizza") ? "2"
			: "0";

		string code = language + job + career + food;
		int point = atoi(tokens[7].c_str());

		vector<string> v_language;
		vector<string> v_job;
		vector<string> v_career;
		vector<string> v_food;

		// lan
		if (language == NONE) { // 0 -> 1,2,3
			v_language.push_back("1");
			v_language.push_back("2");
			v_language.push_back("3");
		}
		else {
			v_language.push_back(language);
		}

		// job
		if (job == NONE) {
			v_job.push_back("1");
			v_job.push_back("2");
		}
		else {
			v_job.push_back(job);
		}

		// career
		if (career == NONE) {
			v_career.push_back("1");
			v_career.push_back("2");
		}
		else {
			v_career.push_back(career);
		}

		// food
		if (food == NONE) {
			v_food.push_back("1");
			v_food.push_back("2");
		}
		else {
			v_food.push_back(food);
		}

		int query_count = 0;
		int language_size = v_language.size();
		for (int idx1 = 0; idx1 < language_size; idx1++) { //lan
			string q = v_language[idx1];
			int job_size = v_job.size();
			for (int idx2 = 0; idx2 < job_size; idx2++) { // job
				string tq1 = q;
				q += v_job[idx2];
				int career_size = v_career.size();
				for (int idx3 = 0; idx3 < career_size; idx3++) { //career
					string tq2 = q;
					q += v_career[idx3];
					int food_size = v_food.size();
					for (int idx4 = 0; idx4 < food_size; idx4++) { // food
						string tq3 = q;
						q += v_food[idx4];
						if (m.find(q) != m.end()) {
							auto it = lower_bound(v[m[q]].begin(), v[m[q]].end(), point);
							if (it != v[m[q]].end()) {
								int dist = distance(it, v[m[q]].end());
								query_count += dist;
							}
						}
						q = tq3;
					}
					q = tq2;
				}
				q = tq1;
			}
		}
		answer.push_back(query_count);
	}

	return answer;
}

int main() {
	vector<string> info = { "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	solution(info, query);

	return 0;
}