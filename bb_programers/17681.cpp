#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    vector<int> answer_bit;

    for (int i = 0; i < n; i++)
    {
        answer_bit.push_back(arr1[i] | arr2[i]);
    }

    for (int k : answer_bit)
    {
        string temp;
        for (int i = n - 1; i >= 0; --i) 
        { //8자리 숫자까지 나타냄
            {
                int result = k >> i & 1;
                if (result == 0)
                    temp.push_back(' ');
                else
                    temp.push_back('#');
            }
        }
        answer.push_back(temp);
    }
        

    return answer;
}