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
		//result의 마지막부분보다 현재 arr이 크면 그냥 맨뒤에 값 추가한다
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

	cout << cnt+1<<"\n";

	int siz = N - 1;
	while(cnt >= 0 && siz >= 0)
	{
		if (trace[siz] == cnt)
		{
			longest_arr.push(arr[siz]);
			//cout << arr[siz] << " ";
			cnt--;
			
		}
		siz--;
		
	}


	while (!longest_arr.empty())
	{
		cout<<longest_arr.top()<<" ";
		longest_arr.pop();

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