#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101

using namespace std;

// E, W, S, N;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int N, M, R;
int board[MAX][MAX];
bool result[MAX][MAX]; // true : 안쓰러짐, false : 쓰러짐

bool isPossible(int y, int x) {
    if (y >= 1 && x >= 1 && y <= N && x <= M) return true;
    return false;
}

int main() {
    int retScore = 0;
    cin >> N >> M >> R;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> board[y][x];
            result[y][x] = true;
        }
    }

    for (int round = 1; round <= R; round++) {
        int ty, tx;
        char td;
        int move = 0;
        // 1. 공격수
        cin >> ty >> tx >> td;
        int nd = (td == 'E' ? 0 : (td == 'W') ? 1 : (td == 'S') ? 2 : 3);
        if (isPossible(ty, tx) && result[ty][tx]) {
            do {// 쓰러지지 않았으면
                if (result[ty][tx]) {
                    move = max(board[ty][tx], move);
                    retScore++;
                    result[ty][tx] = false;
                }
                ty += dy[nd]; tx += dx[nd];
                move--;
            } while (isPossible(ty, tx) && move > 0);
        }

        // 2. 수비수
        cin >> ty >> tx;
        if (!result[ty][tx]) result[ty][tx] = true;
    }
    cout << retScore << endl;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++)
            cout << (result[y][x] ? "S" : "F") << " ";
        cout << "\n";
    }
    return 0;
}
;