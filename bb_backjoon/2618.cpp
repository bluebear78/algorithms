#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MARR = 1002;

typedef struct _point
{
	int x;
	int y;
	int distance;
}point;
point dp[MARR][2]; //N번째 사건을 K-경찰차가 처리했을때에 최소값
int N,W;
vector<pair<int, int>> accident;

void call_police()
{
	point temp;
	dp[0][0] = {0,N,N};
	dp[0][1] = { 0,1,1};

	for (int i = 1; i <= W; i++)
	{
		int new_distance1 = abs(accident[i-1].first - dp[i - 1][0].x) + abs(accident[i-1].second - dp[i - 1][0].y); //1번차가 이동하는 경우
		int new_distance2 = abs(accident[i-1].first - dp[i - 1][0].x) + abs(accident[i-1].second - dp[i - 1][1].y); // 2번차가 이동하는 경우
		if (new_distance1 < new_distance2)
		{
			//1번차가 사건을 처리하는 경우
			dp[i][0] = { new_distance1,dp[i - 1][0].x,dp[i - 1][0].y };
			//2번차가 사건을 처리하는 경우
			dp[i][1] = { new_distance1,accident[i - 1].first,accident[i - 1].second };
		}
		else
		{
			//1번차가 사건을 처리하는 경우
			dp[i][0] = { new_distance2,accident[i - 1].first,accident[i - 1].second };
			//2번차가 사건을 처리하는 경우
			dp[i][1] = { new_distance2,dp[i - 1][1].x,dp[i - 1][1].y };
		}
	}

	cout << min(dp[W][0].distance, dp[W][1].distance);

}
int main()
{
	cin >> N;
	cin >> W;

	for (int i = 0; i < W; i++)
	{
		int x, y;
		cin >> x >> y;
		accident.push_back({ x,y });
	}
	call_police();
}