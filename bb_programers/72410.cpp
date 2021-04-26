#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    //phase 1
    for (char& s : new_id)
        s = tolower(s);
    //phase 2
    for (char s : new_id)
    {
        if (isalpha(s) == 2 || (s) == 0 || s == '-' || s == '_' || s == '.')
            answer.push_back(s);
        if ('0' <= s && s <= '9')
            answer.push_back(s);
    }
    //phase 3
    if (!answer.empty())
    {
        char cache = answer[0];
        for (int i = 1; i < answer.size(); i++)
        {
            if (answer[i] == '.' && cache == '.')
            {
                answer.erase(answer.begin() + i);
                i--;
            }
            cache = answer[i];
        }
    }
    //phase 4
    if(!answer.empty())
        if (answer[0] == '.')
            answer.erase(answer.begin());
    if (!answer.empty())
        if (answer[answer.size() - 1] == '.')
            answer.erase(answer.end()-1);

    //phase 5
    if (answer.empty())
        answer.push_back('a');

    //phase 6
    if (answer.size() >= 16)
        answer.erase(15);
    if (answer[answer.size() - 1] == '.')
        answer.erase(answer.end()-1);

    //phase 7
    for(;answer.size()<=2;)
        answer.push_back(answer[answer.size() - 1]);




    return answer;
}

int main()
{
    cout<<solution("...!@BaT#*..y.abcdefghijklm");
    return 0;
}