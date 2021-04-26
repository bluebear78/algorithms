#include<iostream>

using namespace std;

const int MAX = 1001;
const long long DIV = 1000000003;
int N;
int K;
long long cache[MAX][MAX];

void preCalculate()
{
	for (int i = 1; i <= 3; i++)
		cache[i][1] = i;

	for (int i = 4; i <= N; i++)
	{
		int maxChoose = i / 2; //�� �̻� �Ѿ�� ������ 0

		for (int choose = 1; choose <= maxChoose; choose++)
		{
			if (choose == 1)
				cache[i][choose] = i;
			else
				cache[i][choose] = (cache[i - 2][choose - 1] + cache[i - 1][choose]) % DIV;
			//choose ��° ���� ���°�� + choose ��° ���� ���� �ʴ� ���
		}
	}
}

int main()
{
	cin >> N;
	cin >> K;
	preCalculate();



	cout << cache[N][K] << endl;
	return 0;
}