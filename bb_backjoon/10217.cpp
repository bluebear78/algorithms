#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 987654321;

vector<pair<int, pair<int, int>>> idx[101];
int memo[101][10001];
void KCM(int target, int max_cost)
{
	for (int i = 0; i <= target; i++)
	{
		for (int j = 0; j <= max_cost; j++)
			memo[i][j] = INF;
	}
	memo[1][0] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,1} });
	//cost,time,idx

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int time = pq.top().second.first;
		int here = pq.top().second.second;
		pq.pop();

		if (memo[here][cost] < time)
			continue;

		for (int i = 0; i < idx[here].size(); i++)
		{
			int nextCost = cost + idx[here][i].second.first;
			int nextTime = time + idx[here][i].second.second;
			int there = idx[here][i].first;


			if (nextCost > max_cost)
				continue;

			if (memo[there][nextCost] > nextTime)
			{
				for (int i = nextCost; i <= max_cost; i++)
				{
					if (memo[there][i] > nextTime)
						memo[there][i] = nextTime;
				}
				pq.push({ -nextCost,{nextTime,there} });
			}
		}
	}
	int ret = INF;
	for (int i = 1; i <= target; i++)
		ret = min(ret, memo[target][i]);

	if (ret == INF)
		cout << "Poor KCM" << "\n";
	else
		cout << ret << "\n";
	
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, M, K;
		cin >> N >> M >> K;

		for (int i = 1; i <= N; i++)
		{
			while (!idx[i].empty())
				idx[i].pop_back();
		}
		for (int k = 0; k < K; k++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;

			idx[u].push_back({ v,{c,d} });
		}
		KCM(N, M);
	}
	return 0;
}