#include <iostream>
#include <unordered_map>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N{ 0 }, M{ 0 }, card{ 0 };
    unordered_map<int, int> m;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> card;
        m[card]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> card;
        cout << m[card] << " ";
    }

    return 0;
}