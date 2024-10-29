#include <iostream>
#include <string>
using namespace std;

// 재귀적으로 칸토어 집합을 구성하는 함수
void CantorSet(string& str, int start, int length) {
    if (length == 1) {
        return; // 길이가 1이면 더 이상 처리할 필요가 없음
    }
    
    int divide = length / 3;

    // 가운데 구간을 공백으로 설정
    for (int i = start + divide; i < start + 2 * divide; ++i) {
        str[i] = ' ';
    }

    // 왼쪽 부분과 오른쪽 부분에 대해 재귀적으로 함수 호출
    CantorSet(str, start, divide); // 왼쪽
    CantorSet(str, start + 2 * divide, divide); // 오른쪽
}

int main() {
    int N;
    while (cin >> N) {
        int length = 1;
        for (int i = 0; i < N; ++i) {
            length *= 3;
        }

        // 길이가 length인 문자열을 '-'로 초기화
        string str(length, '-');

        // 칸토어 집합 생성
        CantorSet(str, 0, length);

        // 결과 출력
        cout << str << endl;
    }

    return 0;
}