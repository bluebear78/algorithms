#include<iostream>
#include<map>

#define MMAX 1000001

using namespace std;

long long arr[MMAX];
long long acumm_arr[MMAX];
map<int, long long> revised;
map<int, long long>::iterator iter;


int N, M, K;
long long result;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	cin >> arr[1];
	acumm_arr[1] = arr[1];
	acumm_arr[0] = 0;

	for (int i = 2; i <= N; i++)
	{
		cin >> arr[i];
		acumm_arr[i] = acumm_arr[i - 1] + arr[i];
	}
	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long c;
		cin >> a >> b >> c;

		switch (a)
		{
		case 1 :
			revised[b] = c;
			break;
		case 2:
			result = acumm_arr[c] - acumm_arr[b - 1];

			for (int j = b; j <= c; j++)
			{
				iter = revised.find(j);
				if (iter != revised.end())
					result += (revised[j] - arr[j]);
			}
			cout << result << "\n";

			break;
		}
	}
	return 0;
}