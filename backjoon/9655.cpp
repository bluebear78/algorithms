#include<iostream>

using namespace std;

int N;
const string sang = "SK";
const string chang = "CY";
const int MMAX = 1001;
string dp[MMAX][2];
// [i][0] >> i개가 남았을때 상근이 차례
// [i][1] >> i개가 남았을때 창영이 차례
int main()
{
	cin >> N;
	
	dp[1][0] = sang;
	dp[1][1] = chang;
	dp[2][0] = chang;
	dp[2][1] = sang;
	dp[3][0] = sang;
	dp[3][1] = chang;
	dp[4][0] = sang;
	dp[4][1] = chang;

	for (int i = 5; i <= N; i++)
	{
		//상근이차례
		if (dp[i - 1][1] == sang || dp[i - 3][1] == sang || dp[i - 4][1] == sang)
			dp[i][0] = sang;
		else
			dp[i][0] = chang;
		//창영이 차례
		if (dp[i - 1][0] == chang || dp[i - 3][0] == chang || dp[i - 4][0] == chang)
			dp[i][1] = chang;
		else
			dp[i][1] = sang;
	}

	cout << dp[N][0];
	


	return 0;
}