#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;

const char R = 'R';
const char G = 'G';
const char B = 'B';
const char P = 'P';
const char Y = 'Y';
const char BOM = 'T';
const char Blank = '.';


char map[13][7];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
bool visited[13][7] = { 0 };

typedef struct _point {
	int y;
	int x;
}point;

vector<point> dfs(int y, int x,char c)
{
	stack<point> st;
	st.push({ y,x });
	
	vector<point> mem;
	
	if (visited[y][x] == true)
		return mem;

	mem.push_back({ y,x });
	visited[y][x] = true;


	while (!st.empty())
	{
		point now_p = st.top();
		st.pop();

		visited[now_p.y][now_p.x] = true;

		for (int k = 0; k < 4; k++)
		{
			int next_y = dy[k] + now_p.y;
			int next_x = dx[k] + now_p.x;

			if (map[next_y][next_x] == c && visited[next_y][next_x] != true)
			{
				visited[next_y][next_x] = true;
				st.push({ next_y,next_x });
				mem.push_back({ next_y,next_x });
			}

		}
	}
	return mem;
}

int chain()
{
	int num_chain = 0;
	bool breaking = false;
	while (true)
	{
		breaking = false;
		memset(visited, 0, sizeof(visited));

		//터지는거 확인
		for (int i = 1; i <= 12; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (map[i][j] == R || map[i][j] == G || map[i][j] == B || map[i][j] == P || map[i][j] == Y)
				{
					vector<point> temp = dfs(i, j, map[i][j]);
					if (temp.size() >= 4)
					{
						breaking = true;
						for (int i = 0; i < temp.size(); i++)
							map[temp[i].y][temp[i].x] = Blank;
					}
				}
			}
		}
		//터지는게없으면 종료
		if (breaking == false)
			break;

		for (int i = 1; i <= 12; i++)
		{		for (int j = 1; j <= 6; j++)
			{
				cout << map[i][j] << " ";
			}
		cout << "\n";
		}


		//칸 내리기
		for (int i = 1; i <= 12; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (map[i][j] == BOM)
				{
					for (int g = i; g > 1; g--)
					{
						map[g][j] = map[g - 1][j];
					}
					map[1][1] = Blank;
				}
			}
		}
		num_chain++;
	}
	return num_chain;
}

int main()
{
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			cin >> map[i][j];

	cout << chain();


	return 0;
}