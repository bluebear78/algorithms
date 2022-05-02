#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> dist;
	long long result =0;
	long long oil_money;
	int index_oil =0;

	dist.push_back(0);

	for (int i = 0; i < N - 1; i++)
	{
		int temp;
		cin >> temp;
		dist.push_back(temp);
	}
	
	cin >> oil_money;

	for (int i = 1; i < N; i++)
	{
		result += oil_money * dist[i];

		int current_oil;
		cin >> current_oil;

		if (current_oil < oil_money)
			oil_money = current_oil;
		
	}
	
	cout << result;

}