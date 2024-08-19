#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

typedef struct tagInformation
{
    int Student = 0;
    int Voting = 0;
}INFO;

bool Compaie(INFO& A, INFO& B)
{
    return A.Student < B.Student;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    deque<INFO> d;
    int Recommendation = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> Recommendation;

        // 이전에 추천 받은 경우가 있는지 확인
        bool Find = false;
        deque<INFO>::iterator it = d.begin();
        for (it = d.begin(); it != d.end(); ++it)
        {
            if (Recommendation == it->Student)
            {
                ++it->Voting;
                Find = true;
                break;
            }
        }

        if (true == Find)
        {
            continue;
        }

        if (d.size() < N) // 액자가 남는 경우
        {
            // 처음 추천 받는 경우
            d.push_back({ Recommendation, 1 });
        }
        else // 액자가 남지 않아서 후보 제외 하고 추가하기
        {
            int Min = 1001;
            deque<INFO>::iterator Exception = d.begin();
            for (it = d.begin(); it != d.end(); ++it)
            {
                if (Min > it->Voting) // 투표가 가장 적은 학생
                {
                    Min = it->Voting;
                    Exception = it;
                }
            }

            d.erase(Exception);
            d.push_back({ Recommendation, 1 });
        }
    }

    sort(d.begin(), d.end(), Compaie);
    for (deque<INFO>::iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << it->Student << ' ';
    }

    return 0;
}