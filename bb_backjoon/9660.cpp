#include<iostream>

using namespace std;

long long N;
const string sang = "SK";
const string chang = "CY";
const int MMAX = 6;
string dp[MMAX][2];
// [i][0] >> i���� �������� ����� ����
// [i][1] >> i���� �������� â���� ����
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
		//���������
		if (dp[4][1] == sang || dp[2][1] == sang || dp[1][1] == sang)
			dp[5][0] = sang;
		else
			dp[5][0] = chang;
		//â���� ����
		if (dp[4][0] == chang || dp[2][0] == chang || dp[1][0] == chang)
			dp[5][1] = chang;
		else
			dp[5][1] = sang;

		for (int j = 1; j <= 5; j++)
		{
			dp[j-1][1] = dp[j][1];
			dp[j-1][0] = dp[j][0];
		}

	}

	cout << dp[5][0];



	return 0;
}