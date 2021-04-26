#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

const int MARR = 1000000;
int arr[MARR];
vector<int> result;
int N;
int cnt;

int  trace[MARR];

void LIS()
{
	stack<int> longest_arr;
	result.push_back(arr[0]);
	trace[0] = 0;
	for (int i = 1; i < N; i++)
	{
		//result�� �������κк��� ���� arr�� ũ�� �׳� �ǵڿ� �� �߰��Ѵ�
		if (arr[i] > result[cnt])
		{
			result.push_back(arr[i]);
			cnt++;
			trace[i] = cnt;
		}
		else
		{
			vector<int>::iterator lower = lower_bound(result.begin(), result.end(), arr[i]);
			result[lower - result.begin()] = arr[i];
			trace[i] = lower - result.begin();
		}
	}

	cout << cnt + 1 << "\n";

	for (int i = 0; i < N; i++)
	{
		cout<<trace[i]<<" ";
	}


}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	LIS();

	return 0;
}