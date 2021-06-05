#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V, E;
const int VMAX = 401;
const int INF = 987654321;
int path[VMAX][VMAX];
int arr[VMAX][VMAX];

int floyd_wasshal()
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
				path[i][j] = arr[i][j];
	}
	///path[1][1] = INF;

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (path[i][k] + path[k][j] < path[i][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}



	int result = INF;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i == j)
				continue;
			result = min(result, path[i][j] + path[j][i]);
		}
	}
	if (result == INF)
		return -1;
	return result;
}

int main()
{
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
	}

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	cout<<floyd_wasshal();
	return 0;
}