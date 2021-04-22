#include<iostream>
#include<deque>
using namespace std;

typedef struct _block
{
	int dur;
	bool robot;
}block;
deque<block> de;

int N, K;
void upper()
{
	if (de[0].robot == false && de[0].dur != 0)
	{
		de[0].robot = true;
		de[0].dur--;
	}
}
void moving()
{
	for (int i = N - 2; i >= 0; i--)
	{
		if (de[i].robot)
		{
			if (de[i + 1].robot == false && de[i + 1].dur != 0)
			{
				de[i].robot = false;
				de[i + 1].robot = true;
				de[i + 1].dur--;
			}
		}
	}
	if (de[N - 1].robot)
		de[N - 1].robot = false;
}
void rotation()
{

	block temp = de.back();
	de.pop_back();
	de.push_front(temp);

	if (de[N - 1].robot)
		de[N - 1].robot = false;
}
bool check_block()
{ 
	int cnt = 0;
	for (int i = 0; i < 2*N; i++)
	{
		if (de[i].dur == 0)
		{
			cnt++;
			if (cnt == K)
				return true;

		}
	}
	return false;
}
int move_robot()
{
	int loopcnt = 0;
	while (true)
	{
		loopcnt++;

		//step 1
		rotation();
		//step2
		moving();
		//step3
		upper();
		
		//step4
		if (check_block())
			return loopcnt;
		


	}
}

int main()
{
	cin >> N >> K;
	de.resize(N*2);

	for (int i = 0; i < 2 * N; i++)
	{
		int temp;
		cin >> temp;
		de[i].dur = temp;
		de[i].robot = false;
	}

	cout << move_robot();
	return 0;
}