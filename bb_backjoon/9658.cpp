#include<iostream>

using namespace std;

int N;
const string p1 = "SK";
const string p2 = "CY";
const int MMAX = 1001;
string dp[MMAX][2];
// [i][0] >> i개가 남았을때 p1 차례
// [i][1] >> i개가 남았을때 p2 차례
int main()
{
	cin >> N;

	dp[1][0] = p2;
	dp[1][1] = p1;
	dp[2][0] = p1;
	dp[2][1] = p2;

	dp[3][0] = p2;
	dp[3][1] = p1;
	dp[4][0] = p1;
	dp[4][1] = p2;

	for (int i = 5; i <= N; i++)
	{
		//p1 차례
		if (dp[i - 1][1] == p1 || dp[i - 3][1] == p1 || dp[i - 4][1] == p1)
			dp[i][0] = p1;
		else
			dp[i][0] = p2;
		//창영이 차례
		if (dp[i - 1][0] == p2 || dp[i - 3][0] == p2 || dp[i - 4][0] == p2)
			dp[i][1] = p2;
		else
			dp[i][1] = p1;
	}

	cout << dp[N][0];



	return 0;
}