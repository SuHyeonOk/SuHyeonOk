#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    deque<int> dq;
    for (int i = 1; i <= N; ++i)
    {
        dq.push_back(i);
    }
    
    int Count = 1;
    while (1 < dq.size())
    {
        if (Count % 2 != 0) // 홀수
        {
            dq.pop_front();
        }
        else
        {
            int Temp = dq.front();
            dq.pop_front();
            dq.push_back(Temp);
        }

        ++Count;
        if (N < Count)
        {
            --N;
            Count = N;
        }
    }

    cout << dq.front();

    return 0;
}