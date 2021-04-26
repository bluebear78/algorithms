#include <string>
#include <vector>
#include<iostream>
#include<sstream>

using namespace std;

typedef struct _spec
{
    string detail_spec[4];
    int score;
}spec;

vector<int> solution(vector<string> info, vector<string> query) 
{
    vector<int> answer;
    vector<spec> info_split;
    vector<spec> query_split;
    for (string& s : info)
    {
        stringstream   ss(s);
        string partial;
        int count = 0;
        spec temp;
        while (ss >> partial)
        {
            if (count == 4)
                temp.score = stoi(partial);
            else
            {
                temp.detail_spec[count] = partial;
                count++;
            }
        }
        info_split.push_back(temp);
    }

    for (string& s : query)
    {
        stringstream   ss(s);
        string partial;
        int count = 0;
        spec temp;
        while (ss >> partial)
        {
            if (partial != "and")
            {
                if (count == 4)
                    temp.score = stoi(partial);
                else
                {
                    temp.detail_spec[count] = partial;
                    count++;
                }
            }
          
        }
        query_split.push_back(temp);
    }

    for (spec& q : query_split)
    {
        int count = 0;
        for (spec& s : info_split)
        {
            bool flag = true;
            if (q.score > s.score)
                break;
            for (int i = 0; i < 4; i++)
            {
                if (q.detail_spec[i] == "-")
                    continue;
                if (q.detail_spec[i] != s.detail_spec[i])
                {
                    flag = false;
                    break;
                }
                
            }
            if (flag)
                count++;
        }
        answer.push_back(count);
    }

    return answer;
}


int main()
{
    vector<string> info;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");

    vector<string>query;
    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");


    solution(info, query);



    return 0;
}