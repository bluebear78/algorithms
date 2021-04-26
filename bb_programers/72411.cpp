#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int cnt[27]; //길이가 i인 주문중 최대 주문횟수
unordered_map<string, int> um;//string 조합이 주문된 횟수
vector<string> menu[27][21]; // 길이가 i이고 j번 주문된 조합
void comb(string s, int idx, string made)
{
    if (made.size() > 1)
    {
        um[made]++;
        cnt[made.size()] = max(cnt[made.size()], um[made]);
        menu[made.size()][um[made]].push_back(made);
    }
    for (int i = idx + 1; i < s.size(); i++)
    {
        made.push_back(s[i]);
        comb(s, i, made);
        made.pop_back();
    }
}


vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;

    //preprocessing
    for (string& s : orders)
    {
        sort(s.begin(), s.end());
        comb(s, -1, "");
    }

    //query
    for (int i : course)
    {
        if (cnt[i] > 1)
        {
            for (string s : menu[cnt[i]][i])
                answer.push_back(s);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
int main()
{
    vector<string> str_vector;
    vector<int> course;

    str_vector.push_back("ABCFG");
    str_vector.push_back("AC");
    str_vector.push_back("CDE");
    str_vector.push_back("ACDE");
    str_vector.push_back("BCFG");
    str_vector.push_back("ACDEH");

    course.push_back(2);
    course.push_back(3);
    course.push_back(4);

    vector<string> s = solution(str_vector, course);

    for (string& str : s)
        cout << str << "\n";


    return 0;
}