#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    int Input = 0;
    for (int i = 0; i < N * N; i++)
    {
        cin >> Input;
        pq.push(Input);

        if (pq.size() > N)
        {
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}