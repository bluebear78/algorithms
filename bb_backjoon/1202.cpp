#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
vector<pair<int, int>> stones;
vector<bool> check;
vector<int> bag;
int result = 0;

bool comp1(const pair<int,int>& a,const pair<int,int>& b)
{
	return a.first < b.first;
}


bool compare(pair<int,int> p1, pair<int,int> p2) {
	return p1.second < p2.second;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	check.resize(N);
	for (int i = 0; i < N; i++)
	{
		int weight, value;
		cin >> weight >> value;
		stones.push_back(make_pair(weight, value));
	}
	for (int i = 0; i < K; i++)
	{
		int bag_weight;
		cin >> bag_weight;
		bag.push_back(bag_weight);
	}

	sort(stones.begin(), stones.end());
	sort(bag.begin(), bag.end());

	for (int k = 0; k < K; k++)
	{
		if (stones.empty())
			break;

		auto iter = lower_bound(stones.begin(), stones.end(), make_pair(bag[k] + 1,0),comp1);
		auto find_max = max_element(stones.begin(), iter, compare);
		result+= (*find_max).second;
		stones.erase(find_max);
	}
	
	cout << result << "\n";

	return 0;
}