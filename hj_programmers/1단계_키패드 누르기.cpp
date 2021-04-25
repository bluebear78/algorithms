#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Pos {
	int y, x;
};

struct qPos {
	int y, x, dist;
};

int phone[4][3] = { {1,2,3},{4,5,6},{7,8,9},{-1,0,-1} };
map<string, string> m_hand;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int distance(Pos start, int target) {
	bool visited[4][3] = { false };
	queue<qPos> q;

	visited[start.y][start.x] = true;
	q.push({ start.y, start.x, 0});
	
	while (!q.empty()) {
		qPos cur = q.front();
		q.pop();

		if (target == phone[cur.y][cur.x] ) {
			return cur.dist;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (visited[ny][nx]) continue;
			if (!(ny >= 0 && nx >= 0 && ny < 4 && nx < 3)) continue;
			visited[ny][nx] = true;
			q.push({ ny, nx, cur.dist + 1 });
		}
	}
	
	return 0;
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	m_hand["right"] = "R";
	m_hand["left"] = "L";
	m_hand["1"] = "L";
	m_hand["4"] = "L";
	m_hand["7"] = "L";
	m_hand["3"] = "R";
	m_hand["6"] = "R";
	m_hand["9"] = "R";
	Pos left = {3,0}, right = {3,2}; // init
	for (int num: numbers) {
		string moveHand = "";
		if (m_hand.find(to_string(num)) != m_hand.end()) {
			moveHand = m_hand[to_string(num)];
		}
		else {
			int d_left = distance(left, num);
			int d_right = distance(right, num);
			moveHand = (d_left == d_right ? m_hand[hand] :
				(d_left < d_right ? "L" : "R"));
			//cout << d_left << "," << d_right << endl;
		}
		
		Pos target = { (num == 0) ? Pos{3,1} : Pos{(num - 1) / 3, (num - 1) % 3} };

		if (moveHand == "R") {
			right = target;
		}
		else {
			left = target;
		} 
		answer += moveHand;
	}
	return answer;
}

int main() {
	m_hand["right"] = "R";
	m_hand["left"] = "L";
	m_hand["1"] = "L";
	m_hand["4"] = "L";
	m_hand["7"] = "L";
	m_hand["3"] = "R";
	m_hand["6"] = "R";
	m_hand["9"] = "R";

	cout << solution({ 1,3,4,5,8,2,1,4,5,9,5 }, "right") << endl;
	return 0;
}