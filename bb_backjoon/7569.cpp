#include<iostream>
#include<queue>
using namespace std;

const int MATURE = 1;
const int UNMATUR = 0;
const int BLANK = -1;
const int MAX_AR = 100;


const int dx[6] = {1,0,-1,0,0,0};
const int dy[6] = {0,-1,0,1,0,0};
const int dz[6] = {0,0,0,0,-1,1};

typedef struct _point {
	int z;
	int y;
	int x;
}point;

int M;//가로칸
int N;//세로칸
int H;//상자수
int arr[MAX_AR][MAX_AR][MAX_AR]; // 상자높이,세로,가로
int num_of_tomato;
int tomato = 0;
int day = 0;

//상자 세로 가로
void dfs(queue<point> q)
{
	while (true)
	{
		if (q.empty() || tomato==num_of_tomato)
			break;
		day++;
		int now_size = q.size();
		for (int i = 0; i < now_size; i++)
		{
			point p = q.front();
			q.pop();

			for (int k = 0; k < 6; k++)
			{
				int new_z = p.z + dz[k];
				int new_y = p.y + dy[k];
				int new_x = p.x + dx[k];

				if (new_z < 0 || new_z >= H)
					continue;
				if (new_y < 0 || new_y >= N)
					continue;
				if (new_x < 0 || new_x >= M)
					continue;
				if (arr[new_z][new_y][new_x] != UNMATUR)
					continue;

				tomato++;
				arr[new_z][new_y][new_x] = MATURE;
				q.push({ new_z,new_y,new_x });
			}
		}
	}

	if (tomato == num_of_tomato)
		cout << day;
	else
		cout << -1;
}

int main()
{

	cin >> M >> N >> H;
	num_of_tomato = M * N * H;

	queue<point> q;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int x;
				cin >> arr[i][j][k];
				if (arr[i][j][k] == MATURE)
				{
					tomato++;
					q.push({ i,j,k });
				}
				else if (arr[i][j][k] == BLANK)
					num_of_tomato--;
			}
		}
	}

	dfs(q);


	return 0;
}