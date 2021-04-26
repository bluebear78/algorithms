#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;//ũ���ο��� �Ű��� ���� �͵��� ��� �δ� �ٱ���

    for (int i = 0; i < moves.size(); i++) {
        int emptyCnt = 0;//��������� �����ֱ� ���� ����
        int value;

        for (int j = 0; j < board.size(); j++) {
            value = board[j][moves[i] - 1];//ũ������ ���η� �����δٴ� ���� �����Ͽ� j�� �켱�����κ���

            if (value == 0) emptyCnt++;
            else break;
        }

        //���� ��� �κ��� ��� �ִٸ� �Ʒ��� �ڵ带 �����ϸ� �ȵ��� �ǹ��Ѵ�.
        if (emptyCnt < board.size()) {
            basket.push_back(value);//ũ������ �̾ƿ°��� �־��ְ�
            board[emptyCnt][moves[i] - 1] = 0;//�̾ƿ°��� ���� 0���� �Ͽ� ��������� ���

            //�������� ���� �� �Ʒ��� ���� ������
            if (basket.size() >= 2 && value == basket[basket.size() - 2]) {
                basket.pop_back();
                basket.pop_back();
                answer += 2;//�ѹ��� �ΰ��� ������ ������Ƿ� +2
            }
        }
    }
    return answer;
}
