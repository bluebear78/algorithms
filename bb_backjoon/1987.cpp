#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 20;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int R, C;
int result;
string board[MAX];

void dfs(int y, int x, long long alphabet, int cnt)
{
	alphabet |= (1 << (board[y][x] - 'A'));

	for (int i = 0; i < 4; i++)
	{
		int ny = y + moveDir[i].y;
		int nx = x + moveDir[i].x;

		if (0 <= ny && ny < R && 0 <= nx && nx < C)
			if (!(alphabet & (1 << (board[ny][nx] - 'A'))))
				dfs(ny, nx, alphabet, cnt + 1);

	}
	result = max(result, cnt);
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> board[i];

	result = -1;
	dfs(0, 0, (long long)1 << 26, 1);
	cout << result << "\n";
	return 0;
}