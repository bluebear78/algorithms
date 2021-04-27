#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int rankm(int ans)
{
    switch (ans)
    {
    case 6: return 1;
    case 5: return 2;
    case 4: return 3;
    case 3: return 4;
    case 2: return 5;
    default:
        return 6;
    }
}

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    vector<int> answer;
    answer.resize(2);
    
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
 
    int cache = 0;
    int zero_count = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zero_count++;
            continue;
        }
        for (int j = cache; j < win_nums.size(); j++)
        {
            cache = j + 1;
            if (lottos[i] == win_nums[j])
            {
                answer[0]++;
                answer[1]++;
                break;
            }
            if (lottos[i] < win_nums[j])
            {
                cache--;
                break;
            }
        }
    }

    answer[0] = rankm(answer[0] + zero_count);
    answer[1] = rankm(answer[1]);
    return answer;
}

int main()
{
    vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
    
    vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
    //[44, 1, 0, 0, 31, 25]	[31, 10, 45, 1, 6, 19]   

    solution(lottos, win_nums);

    return 0;
}