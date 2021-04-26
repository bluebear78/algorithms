#include<iostream>

using namespace std;

int N, M, R;
int MARR[101][101] = { 0 };
bool domino[101][101] = { false };
int strikerA;

void show_map()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (domino[i][j] == false)
				cout << "F ";
			else
				cout << "S ";
		}
		cout << "\n";
	}
}

int fallover(int dy,int dx,char dir)
{
	int count = 0;
	
		//서있으면
		int num = MARR[dy][dx];
		
		domino[dy][dx] = false;
		count++;
		//cout << "=========================\n";
		//show_map();

		if (dir == 'E')
		{
			for (int i = 1; i < num; i++)
			{
				if (dy > N && dy <= 0 && (dx + i) > M && (dx + i) <= 0)
					break;

				if(domino[dy][dx+i] ==true)
					count+=fallover(dy, dx + i, dir);
			}
		}
		else if (dir == 'W')
		{
			for (int i = 1; i <num; i++)
			{
				if (dy > N && dy <= 0 && (dx - i) > M && (dx - i) <= 0)
					break;
				if (domino[dy][dx - i] == true)
					count+=fallover(dy, dx - i, dir);
			}
		}
		else if (dir == 'S')
		{
			for (int i = 1; i < num; i++)
			{
				if ((dy + i) > N && (dy + i) <= 0 && dx > M && dx <= 0)
					break;
				if (domino[dy+i][dx] == true)
					count+=fallover(dy + i, dx, dir);
			}
		}
		else
		{
			for (int i = 1; i < num; i++)
			{
				if ((dy - i) > N && (dy - i) <= 0 && dx > M && dx <= 0)
					break;
				if (domino[dy-i][dx] == true)
					count+=fallover(dy - i, dx, dir);
			}
		}
	
	return count;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> MARR[i][j];
			domino[i][j] = true;
		}
	}

	int dy, dx;
	char dir;

	int defense_y, defense_x;

	for (int round = 0; round < R; round++)
	{
		cin >> dy >> dx >> dir;
		cin >> defense_y >> defense_x;

		if (domino[dy][dx] == true)
		{
			strikerA += fallover(dy, dx, dir);
		}
		


		domino[defense_y][defense_x] = true;

	}

	cout << strikerA<<"\n";

	show_map();
	
	

	return 0;
}