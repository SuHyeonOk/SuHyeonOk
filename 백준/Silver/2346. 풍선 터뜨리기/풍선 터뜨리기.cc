#include <iostream>
#include <deque>
#define MAX 1000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    deque<pair<int, int>> Ds;
    int Input = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> Input;
        Ds.push_back({ i, Input });
    }

    int Num = 0, Count = 1, TempCount = 0;
    while (false == Ds.empty())
    {
        if (0 < Count)
        {
            --Count;

            if (0 == Count)
            {
                cout << Ds.front().first << ' ';
                Count = Ds.front().second;
                Ds.pop_front();
            }
            else
            {
                Num = Ds.front().first;
                TempCount = Ds.front().second;
                Ds.pop_front();
                Ds.push_back({ Num, TempCount });
            }
        }
        else
        {
            ++Count;

            if (0 == Count)
            {
                cout << Ds.back().first << ' ';
                Count = Ds.back().second;
                Ds.pop_back();
            }
            else
            {
                Num = Ds.back().first;
                TempCount = Ds.back().second;
                Ds.pop_back();
                Ds.push_front({ Num, TempCount });
            }
        }
    }

    return 0;
}