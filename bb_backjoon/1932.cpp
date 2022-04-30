#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[51][51][51];
int dp_recurisve(int a, int b, int c);
int main()
{
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			for (int k = 0; k < 51; k++)
				dp[i][j][k] = -1;
	dp[0][0][0] = 1;
	while (true)
	{
		int a, b, c;

		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << dp_recurisve(a, b, c) << endl;

	}
	

	

	return 0;
}

int dp_recurisve(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	if (dp[a][b][c] != -1)
		return dp[a][b][c];
	if (a > 20 || b > 20 || c > 20)
	{
		dp[a][b][c] = dp_recurisve(20, 20, 20);
		return dp[a][b][c];
	}
	if (a < b && b < c)
	{
		dp[a][b][c] = dp_recurisve(a, b, c - 1) + dp_recurisve(a, b - 1, c - 1) - dp_recurisve(a, b - 1, c);
		return dp[a][b][c];
	}
	dp[a][b][c] = dp_recurisve(a - 1, b, c) + dp_recurisve(a - 1, b - 1, c) + dp_recurisve(a - 1, b, c - 1) - dp_recurisve(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}