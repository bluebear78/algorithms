#define MMAX 1001

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;


int T;
int N, K;
int W;
int delay[MMAX];
vector<int> graph[MMAX];
int dp[MMAX];
queue<int> zero_que;
int connected[MMAX];


int main()
{
	cin >> T;
	while (T--)
	{
		memset(graph, 0, sizeof(graph));
		memset(dp, 0, sizeof(dp));
		memset(connected, 0, sizeof(connected));

		cin >> N >> K;

		for (int i = 1; i <= N; i++)
			cin >> delay[i];

		for (int i = 0; i < K; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			connected[to]++;
		}
		for (int i = 1; i <= N; i++)
		{
			if (connected[i] == 0)
			{
				zero_que.push(i);
				dp[i] = delay[i];
			}

		}
		cin >> W;

		while (true)
		{
			if (zero_que.empty())
			{
				break;
			}

			int this_node = zero_que.front();
			zero_que.pop();

			for (int i = 0; i < graph[this_node].size(); i++)
			{
				int next_node = graph[this_node][i];
				dp[next_node] = max(dp[next_node], dp[this_node] + delay[next_node]);
				connected[next_node]--;

				if (connected[next_node] == 0)
					zero_que.push(next_node);
			}

		}
	
		cout << dp[W];
	return 0;
}