#include<iostream>

using namespace std;


const int AMAX = 1000001;
const int INF = 987654321;
pair<int,int> dp[AMAX];
//memory , È½¼ö

int main()
{
	dp[1] = { 0,0 };
	dp[2] = { 1,1 };
	dp[3] = { 1,1 };

	int N;
	cin >> N;

	for (int i = 4; i <= N; i++)
	{
		int result = INF;
		int idx = -1;
		if (i % 2 == 0)
		{
			idx = i / 2;
			result = dp[i / 2].second;
		}
		if (i % 3 == 0)
		{
			if (result > dp[i / 3].second)
			{
				result = dp[i / 3].second;
				idx = i / 3;
			}
		}
		if (result > dp[i - 1].second)
		{
			result = dp[i - 1].second;
			idx = i - 1;
		}

		dp[i].first = idx;
		dp[i].second = result+1;
	}

	cout << dp[N].second << "\n";
	
	int mark = dp[N].first;
	cout << N<<" ";
	while (mark != 1)
	{
		cout << mark<<" ";
		mark = dp[mark].first;
	}
	cout << 1;
	return 0;
}