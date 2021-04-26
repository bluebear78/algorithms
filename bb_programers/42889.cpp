#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(pair<float, int> i, pair<float, int> j)
{
    if (i.first == j.first)
        return j.second > i.second;
    return j.first < i.first;

}

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<float>failure_rate;
    vector<pair<float, int>> raking;
    failure_rate.resize(N+2,0);
    //memset(failure_rate, 0, sizeof(failure_rate));

    for (int i = 0; i < stages.size(); i++)
    {
        failure_rate[stages[i]]++;
    }

    float number_of_people = stages.size();
    for (int i = 1; i < failure_rate.size()-1; i++)
    {
        float num = failure_rate[i];
        if (number_of_people == 0)
        {
            raking.push_back(make_pair(0, i));
            continue;
        }

        raking.push_back (make_pair((failure_rate[i] / number_of_people),i));
        number_of_people -= num;
    }
    sort(raking.begin(), raking.end(),compare);

    for (pair<float, int> s : raking)
        answer.push_back(s.second);

    return answer;
}

int main()
{
    int N = 500;
    vector<int> stages;
    stages.push_back(10);
    stages.push_back(15);
    stages.push_back(21);
    stages.push_back(21);
    stages.push_back(14);

    solution(N, stages);


    return 0;
}