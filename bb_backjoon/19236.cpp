#include<iostream>
using namespace std;

int dy[9] = {0,1, 1, 0, -1,-1,-1,0,1};
int dx[9] = {0,0,-1,-1, -1, 0, 1,1,1};

const int DIE = 99;
const int MAX = 5;
const int SHARK = 100;

typedef struct _point
{
	int idx;
	int dir;
}point;

point arr[MAX][MAX];

typedef struct _cache
{
	point arr[MAX][MAX];
}cache;


cache cache_shark[MAX][MAX];

point** move(point** temp)
{
	int idx_count = 1;


	while(idx_count <=16)
	{
		bool flag = false;
		for (int i = 1; i <= 4; i++)
		{
			if (flag == true)
				break;
			for (int j = 1; j <= 8; j++)
			{
				if (flag == true)
					break;

				bool moving_poss = false;
				if (temp[i][j].idx == idx_count)
				{
					idx_count++;
					int next_step = temp[i][j].dir;
					int next_y = i + dy[next_step];
					int next_x = i + dx[next_step];

					while (!moving_poss)
					{
						if (temp[next_y][next_x].idx != SHARK && next_y >= 1 && next_y <= 4 && next_x >= 1 && next_x <= 4)
						{
							flag = true;
							moving_poss = true; // 바꿀 수 있는 공간
							point ca1 = temp[i][j];
							temp[i][j] = temp[next_y][next_x];
							temp[next_y][next_x] = ca1;
						}
						else
						{
							//이동못하는 경우
							if (temp[next_y][next_x].dir == 8)
								temp[next_y][next_x].dir = 1;
							else
								temp[next_y][next_x].dir += 1;
						}
					}
				}
			}
		}
	}
	return temp;
}

void backtracking(int i,int j)
{

}

int main()
{
	int temp_idx, temp_dir;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cin >> temp_idx >> temp_dir;
			arr[i][j].idx = temp_idx;
			arr[i][j].dir = temp_dir;
		}
	}
	
	int result = 0;

	result += arr[1][1].idx;
	arr[1][1].idx = SHARK;

	backtracking(1, 1);

	return 0;
}