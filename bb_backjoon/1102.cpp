#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 17;
const int INF = 987654321;
int arr[MAX][MAX];
int dp[MAX][1 << MAX];
int N;
int P;
int isVisited = 1 << MAX;
string str;

int countBits(int n)
{
	int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}
int minCost(int idx, int curState)
{
	if (countBits(curState) - 1 >= P)
		return 0;

	int& result = dp[idx][curState];
	if (result != -1)
		return result;
	result = INF;

	for (int i = 0; i < N; i++)
	{
		if ((curState & (1 << i)) == 0)
		{
			int nextState = curState | (1 << i);
			for (int j = 0; j < N; j++)
			{
				if (nextState & (1 << j))
				{
					result = min(result, arr[idx][i] + minCost(j, nextState));
				}
			}
		}
	}
	return result;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> str;
	cin >> P;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'Y')
			isVisited |= (1 << i);
	}

	if (P == 0)
		cout << 0 << "\n";
	else
	{
		memset(dp, -1, sizeof(dp));
		int result = INF;

		for (int i = 0; i < N; i++)
		{
			if (str[i] == 'Y')
			{
				result = min(result, minCost(i, isVisited));
			}
		}

		if (result == INF)
			cout << -1 << "\n";
		else
			cout << result << "\n";
	}
	return 0;
}