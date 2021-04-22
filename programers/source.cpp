#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;//크레인에서 옮겨져 오는 것들을 모아 두는 바구니

    for (int i = 0; i < moves.size(); i++) {
        int emptyCnt = 0;//빈공간들을 세어주기 위한 변수
        int value;

        for (int j = 0; j < board.size(); j++) {
            value = board[j][moves[i] - 1];//크레인이 세로로 움직인다는 것을 생각하여 j를 우선적으로보기

            if (value == 0) emptyCnt++;
            else break;
        }

        //만약 모든 부분이 비어 있다면 아래의 코드를 실행하면 안됨을 의미한다.
        if (emptyCnt < board.size()) {
            basket.push_back(value);//크레인이 뽑아온것을 넣어주고
            board[emptyCnt][moves[i] - 1] = 0;//뽑아온곳의 값은 0으로 하여 비어있음을 명시

            //가장위의 값과 그 아래의 값이 같을때
            if (basket.size() >= 2 && value == basket[basket.size() - 2]) {
                basket.pop_back();
                basket.pop_back();
                answer += 2;//한번에 두개의 인형이 사라지므로 +2
            }
        }
    }
    return answer;
}
