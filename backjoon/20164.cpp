#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define sz(x) (int)(x).size()

string n, nx;
int min_val, max_val;
int a, b, c;
int ret;

int cal(string x) 
{
	ret = 0;
	for (int i = 0; i < sz(x); i++)
		ret += (x[i] - '0') % 2;
	return ret;
}

void divide(string x, int sum)
{
	if (sz(x) >= 3)
	{
		for (int i = 1; i < sz(x); i++)
		{
			for (int j = i + 1; j < sz(x); j++) 
			{
				a = stoi(x.substr(0, i));
				b = stoi(x.substr(i, j - i));
				c = stoi(x.substr(j));

				nx = to_string(a + b + c);
				divide(nx, sum + cal(nx));

			}
		}
	}
	else if (sz(x) == 2)
	{
		nx = to_string(x[0] - '0' + x[1] - '0');
		divide(nx, sum + cal(nx));
	}
	else if (sz(x) == 1)
	{
		min_val = min(min_val, sum + cal(n));
		max_val = max(max_val, sum + cal(n));
	}
}
int main()
{
	cin >> n;
	min_val = INT_MAX;
	max_val = INT_MIN;
	divide(n, 0);
	cout << min_val << " " << max_val;
	return 0;
}