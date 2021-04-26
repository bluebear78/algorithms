/*
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

*/

#include<iostream>

using namespace std;

const int DIV = 1000000000;

int N;
int K;
long long cache[201][201]; // 숫자 N을 K개로 만들때 경우의 수

void printArr()
{
	cout << "\n";
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
			cout << cache[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	cin >> N >> K;


	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
			cache[i][j] = 0;
	}
	for (int i = 0; i <= N; i++)
		cache[i][1] = 1;

	for (int j = 2; j <= K; j++)
	{
		for (int i = 0; i <= N; i++)
	{		
			for (int k = 0; k <= i; k++)
			{
				cache[i][j] = (cache[i][j] + cache[k][j-1]) % DIV;
			}
		}
	}
	cout << cache[N][K];
	//printArr();
	return 0;
}