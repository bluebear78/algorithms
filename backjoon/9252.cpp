#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MARR = 1001;
int dp[MARR][MARR];
char result[MARR];

void LCS(string s1, string s2)
{
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= s2.size(); i++)
	{
		for (int j = 1; j <= s1.size(); j++)
		{
			if (s2[i - 1] == s1[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int cnt = dp[s2.size()][s1.size()];
	int result_size = cnt;

	int temp = s1.size();
	for (int i = s2.size(); i >= 1; i--)
	{
		for (int j = temp; j >= 1; j--)
		{
			if (dp[i][j - 1] != dp[i][j])
			{
				if (dp[i][j] == dp[i - 1][j])
				{
					temp = j;
					break;
				}
				result[cnt] = s2[i - 1];
				cnt--;
				temp = j-1;
				break;
			}
		}
	}

	cout << result_size << "\n";
	for (int i = 1; i <= result_size; i++)
		cout << result[i];
}

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	LCS(s1,s2);

	return 0;
}