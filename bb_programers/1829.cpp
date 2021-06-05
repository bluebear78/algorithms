#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    bool isvisited[101][101] = { false };

    for (int i = 0; i <n; i++)
    {
        for(int j=0;j<m;j++)
        {
            if (isvisited[j][i] == false && picture[j][i] != 0)
            {
                int area_count = 0;
                int color = picture[j][i];
                number_of_area++;

                queue<pair<int, int>> st;
                st.push(make_pair(i, j));
                //isvisited[j][i] = true;

                while (!st.empty())
                {
                    int cur_x = st.front().first;
                    int cur_y = st.front().second;
                    isvisited[cur_y][cur_x] = true;
                    st.pop();
                    area_count++;

                    for (int k = 0; k < 4; k++)
                    {
                        int new_x = cur_x + dx[k];
                        int new_y = cur_y + dy[k];

                        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
                            continue;//맵밖으로 가면 넘김
                        if (isvisited[new_y][new_x] == true)
                            continue; // 이미 방문한곳이면 넘김
                        if (picture[new_y][new_x] != color)
                            continue; // 다른 영역이면 넘김
                        st.push(make_pair(new_x, new_y));
                    }
                }

                max_size_of_one_area = max(max_size_of_one_area, area_count);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    int m = 6;
    int n = 4;
    vector<vector<int>> pict;
    vector<int> a = { 1,1,1,0 };
    pict.push_back(a);
    vector<int> b = { 1,1,1,0 };
    pict.push_back(b);
    vector<int> c = { 0,0,0,1 };
    pict.push_back(c);
    vector<int> d = {0,0,0,1};
    pict.push_back(d);
    vector<int> e = { 0,0,0,1 };
    pict.push_back(e);
    vector<int> f = { 0,0,0,1 };
    pict.push_back(f);
    //	6, 4, [[1, 1, 1, 0], [1, 1, 1, 0], [0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]
    //output : 2,6
    //1 1 1 0
    //1 1 1 0
    //0 0 0 1
    //0 0 0 1
    //0 0 0 1
    solution(m, n, pict);

    return 0;
}