#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int alphabet[26];
vector<string> V;

bool cmp(int a, int b)
{
	if (a > b) return true;
	
	return false;
}
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string Inp;
		cin >> Inp;
		V.push_back(Inp);
	}
}
void soultion()
{
	for (int i = 0; i < N; i++)
	{
		string s = V[i];
		int pow = 1;
		int len = s.length();

		for (int j = len - 1; j >= 0; j--)
		{
			int tmp = s[j] - 'A';
			alphabet[tmp] = alphabet[tmp]+ pow;
			pow *= 10;
		}
	}
	sort(alphabet, alphabet + 26, cmp);

	int ans = 0;
	int num = 9;

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == 0)
			break;
		ans =ans + (alphabet[i] * num);
		num--;

	}
	cout << ans;
}


void solve()
{
	input();
	soultion();
}

int main()
{
	solve();
	return 0;
}