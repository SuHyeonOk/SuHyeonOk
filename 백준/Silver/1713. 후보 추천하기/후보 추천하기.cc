#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

typedef struct tagInformation {
    int Student = 0;
    int Voting = 0;
    int Time = 0;  // 추천 받은 시간을 저장하는 변수
} INFO;

bool Compare(INFO& A, INFO& B) {
    return A.Student < B.Student;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    int Recommendation = 0;
    deque<INFO> d;
    int time = 0;

    for (int i = 0; i < M; ++i) {
        cin >> Recommendation;
        time++;  // 시간 증가

        // 이전에 추천 받은 경우가 있는지 확인
        bool Find = false;
        for (auto& info : d) {
            if (Recommendation == info.Student) {
                ++info.Voting;
                Find = true;
                break;
            }
        }

        if (Find) {
            continue;
        }

        if (d.size() < N) { // 액자가 남는 경우
            d.push_back({ Recommendation, 1, time });
        }
        else { // 액자가 남지 않아서 후보 제외하고 추가하기
            // 투표가 가장 적은 학생을 찾는다. 동일 투표수일 경우 더 오래된 학생을 찾는다.
            auto Exception = min_element(d.begin(), d.end(), [](INFO& A, INFO& B) {
                if (A.Voting == B.Voting)
                    return A.Time < B.Time;
                return A.Voting < B.Voting;
                });

            d.erase(Exception);
            d.push_back({ Recommendation, 1, time });
        }
    }

    sort(d.begin(), d.end(), Compare);
    for (auto& info : d) {
        cout << info.Student << ' ';
    }

    return 0;
}
