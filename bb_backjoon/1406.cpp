#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<list>
#include<functional>
#include<string>
using namespace std;

list<char> li;
list<char>::iterator iter;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	int T;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
		li.push_back(s[i]);
	iter = li.end();
	
	cin >> T;
	while (T--)
	{
		char order;
		cin >> order;
		

		switch (order)
		{
		case 'L':
			if (iter != li.begin())
				iter--;
			break;
		case 'D':
			if (iter != li.end())
				iter++;
			break;
		case 'B':
			if (iter != li.begin())
			{
				iter = li.erase(--iter);
			}
			break;
		case 'P':
			char temp;
			cin >> temp;
			li.insert(iter, temp);
			break;
		default:
			break;
		}
	}
	for (iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter;
	}
	cout << "\n";

	return 0;
}