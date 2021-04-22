#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MARR = 800+1;
const int INF = 987654321;

int N, E;
int arr[MARR][MARR];
int dij[MARR];
bool isVisted[MARR];
int v1, v2;

void dijk()
{
	
}


int main()
{
	cin >> N >> E;

	for (int i = 1; i <= N; i++)
	{
		dij[i] = INF;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				arr[i][j] = 0;
			else
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++)
	{
		int n1, n2, weight;
		cin >> n1 >> n2 >> weight;
		arr[n1][n2] = weight;
		arr[n2][n1] = weight;
	}
	cin >> v1 >> v2;

	

	return 0;
}