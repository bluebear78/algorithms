#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

const int MAX = 1001;
int arr[MAX][MAX];
int cache[MAX][MAX][2];
int N, M;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int dfs()
{
	queue<pair<pair<int, int>, int>> qu;
	qu.push(make_pair(make_pair(1, 1), 1));
	cache[1][1][1] = 1;
	while (!qu.empty())
	{
		int y = qu.front().first.first;
		int x = qu.front().first.second;
		int block = qu.front().second;
		qu.pop();

		if (y == N && x == M)
			return cache[y][x][block];

		for (int k = 0; k < 4; k++)
		{
			int new_y = y + dy[k];
			int new_x = x + dx[k];

			if (1 <= new_x && new_x <= M && 1 <= new_y && new_y <= N)
			{
				//벽이 있고 벽을 뚧을 수 있으면
				if (arr[new_y][new_x] == 1 && block == 1)
				{
					cache[new_y][new_x][0] = cache[y][x][1] + 1;
					qu.push(make_pair(make_pair(new_y, new_x), 0));
				}
				//벽이 없고 방문한적이 없으면
				else if (arr[new_y][new_x] == 0 && cache[new_y][new_x][block] == 0)
				{
					cache[new_y][new_x][block] = cache[y][x][block] + 1;
					qu.push(make_pair(make_pair(new_y, new_x), block));
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	cout << dfs();
	return 0;
}