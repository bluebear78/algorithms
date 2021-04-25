#include <string>
#include <vector>
#include<iostream>

using namespace std;

int distance(int num,int hand_index)
{
    switch (abs(num - hand_index))
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 1;
    case 4:
        return 2;
    case 5:
        return 3;
    case 6:
        return 2;
    case 7:
        return 3;
    case 8:
        return 4;
    case 9:
        return 3;
    case 10:
        return 4;
    default:
        return NULL;
    }

}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lefthand = 10;
    int righthand = 12;
  

    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
            numbers[i] = 11;
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer.push_back('L');
            lefthand = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer.push_back('R');
            righthand = numbers[i];
        }
        else
        {
            int left_dist = distance(numbers[i],lefthand);
            int right_dist = distance(numbers[i], righthand);

            if (left_dist < right_dist)
            {
                answer.push_back('L');
                lefthand = numbers[i];
            }
            else if (left_dist == right_dist)
            {
                if (hand == "left")
                {
                    answer.push_back('L');
                    lefthand = numbers[i];
                }
                else
                {
                    answer.push_back('R');
                    righthand = numbers[i];
                }
            }
            else
            {
                answer.push_back('R');
                righthand = numbers[i];
            }

          
        }

    }

    return answer;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(5);

    string hand = "right";

    cout << solution(arr, hand);

    return 0;
}