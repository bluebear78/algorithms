/*
0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ ������ �ٲ� ���� �ٸ� ���� ����(1+2�� 2+1�� ���� �ٸ� ���). ���� �� ���� ���� ���� �� �� ���� �ִ�.

*/

#include<iostream>

using namespace std;

const int DIV = 1000000000;

int N;
int K;
long long cache[201][201]; // ���� N�� K���� ���鶧 ����� ��

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