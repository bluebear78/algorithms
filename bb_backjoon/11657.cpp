#include<iostream>
#include<vector>
using namespace std;

const int INF = 987654321;

int N;
int M;
long long Dist[6001];
vector<pair<pair<int, int>,long long>> Edge;
//간선을 저장한 vector <<from,to>,cost>
void Bellman_Ford()
{
	Dist[1] = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < Edge.size(); j++)
		{
			int From = Edge[j].first.first;
			int To = Edge[j].first.second;
			long long Cost = Edge[j].second;

			if (Dist[From] == INF) 
				continue;
			if (Dist[To] > Dist[From] + Cost)
				Dist[To] = Dist[From] + Cost;
		}
	}
	

	//음의 cycle이 있는지 검증
	for (int i = 0; i < Edge.size(); i++)
	{
		int From = Edge[i].first.first;
		int To = Edge[i].first.second;
		long long Cost = Edge[i].second;

		if (Dist[From] == INF)
			continue;
		if (Dist[To] > Dist[From] + Cost)
		{
			cout << -1 << "\n";
			return;
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (Dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << Dist[i] << "\n";
	}
}
int main()
{
	cin >> N >> M;
	N++;
	for (int i = 1; i <= N; i++)
		Dist[i] = INF;

	for (int i = 0; i < M; i++)
	{
		int from, to;
		long long cost;
		cin >> from >> to >> cost;
		Edge.push_back(make_pair(make_pair(from, to), cost));
	}
	Bellman_Ford();

	return 0;
}