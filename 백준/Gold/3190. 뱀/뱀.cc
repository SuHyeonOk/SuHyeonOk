#include <iostream>
#include <queue>
#include <deque>
#define APPLE 1
#define EMPTY 0
using namespace std;

int N, Time;
int board[101][101];
pair<int, char> datas[100];

int dx[4] = { 0, 1, 0, -1 }; // 오른쪽, 아래, 왼쪽, 위
int dy[4] = { 1, 0, -1, 0 };
int direction = 0; // 시작 방향 (오른쪽)

void Rotation(char _Direction) {
    if (_Direction == 'D') {
        direction = (direction + 1) % 4; // 오른쪽 회전
    }
    else {
        direction = (direction + 3) % 4; // 왼쪽 회전
    }
}

void simulate() {
    deque<pair<int, int>> snake;
    snake.push_front({ 1, 1 }); // 시작 위치
    board[1][1] = 2; // 뱀의 위치를 2로 표시

    int Index = 0;

    while (true) {
        int headX = snake.front().first;
        int headY = snake.front().second;
        int newX = headX + dx[direction];
        int newY = headY + dy[direction];

        // 종료 조건 1. 벽에 부딪히는 경우
        if (newX <= 0 || newY <= 0 || newX > N || newY > N) {
            Time++;
            break;
        }

        // 종료 조건 2. 자기 몸과 부딪히는 경우
        if (board[newX][newY] == 2) {
            Time++;
            break;
        }

        // 머리를 다음 위치로 이동
        if (board[newX][newY] == APPLE) {
            board[newX][newY] = 2; // 사과를 먹으면 머리만 이동
            snake.push_front({ newX, newY });
        }
        else {
            // 사과가 없으면 머리 이동 후 꼬리 제거
            board[newX][newY] = 2;
            snake.push_front({ newX, newY });
            int tailX = snake.back().first;
            int tailY = snake.back().second;
            board[tailX][tailY] = EMPTY; // 꼬리 제거
            snake.pop_back();
        }

        Time++;

        // 방향 전환
        if (Index < 100 && Time == datas[Index].first) {
            Rotation(datas[Index].second);
            Index++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> N >> K;

    for (int i = 0; i < K; ++i) {
        int X, Y;
        cin >> X >> Y;
        board[X][Y] = APPLE;
    }

    int L;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        cin >> datas[i].first >> datas[i].second;
    }

    simulate();
    cout << Time;

    return 0;
}
