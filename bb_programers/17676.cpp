#define _CRT_SECURE_NO_WARNINGS

//https://programmers.co.kr/learn/courses/30/lessons/17676
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define BUFF_SIZE 86400000

int buff[BUFF_SIZE] = { 0 };

int solution(vector<string> lines) {
    int answer = 0;


    for (int i = 0; i < lines.size(); i++)
    {
        int end = 0;
        int elapsed_time;
        int y, m, d, hh, mm, ss, zzz;
        double elapsed_double;
        sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%d.%d %lfs", &y, &m, &d, &hh, &mm, &ss, &zzz, &elapsed_double);
        elapsed_time = (int)(elapsed_double * 1000);

        end += hh * 60;
        end += mm;
        end *= 60;
        end += ss;
        end *= 1000;
        end += zzz;

        for (int j = end - (elapsed_time - 1) - 999; j <= end; j++)
        {
            if (j < 0 || j >= BUFF_SIZE)
                continue;
            buff[j] += 1;
            answer = max(answer, buff[j]);
        }
    }

    return answer;
}

int main()
{
    vector<string> s;
    string s1 = "2016-09-15 20:59:57.421 0.351s";
    s.push_back(s1);

    string s2 = "2016-09-15 20:59:58.233 1.181s";
    s.push_back(s2);
    string s3 = "2016-09-15 20:59:58.299 0.8s";
    s.push_back(s3);
    string s4 = "2016-09-15 20:59:58.688 1.041s";
    s.push_back(s4);
    string s5 = "2016-09-15 20:59:59.591 1.412s";
    s.push_back(s5);

    solution(s);


    return 0;
}