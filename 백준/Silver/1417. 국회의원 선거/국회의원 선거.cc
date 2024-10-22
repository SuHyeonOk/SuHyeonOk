#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    --N;
    int Dasom = 0;
    cin >> Dasom;

    int Input = 0;
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        pq.push(Input);
    }

    int Count = 0;
    bool Find = true;
    while (true == Find)
    {
        Find = false;
        for (int i = 0; i < N; ++i)
        {
            if (Dasom + Count <= pq.top())
            {
               int Temp = pq.top();
               pq.pop();
               pq.push(--Temp);
               ++Count;
               Find = true;
            }
        }
    }

    cout << Count;

    return 0;
}