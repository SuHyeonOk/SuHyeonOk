#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

int N{ 0 }, M{ 0 };
vector<int> vec(MAX, 0);

void DFS(int _count)
{
    // 목표 M까지 도달 했다면
    if (_count == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << vec[i] << ' ';
        }
        cout << '\n';

        return;
    }

    // 목표에 도달하지 못 했다면
    for (int i = 1; i <= N; i++)
    {
        vec[_count] = i;
        DFS(_count + 1); // M까지 들어간다.
    }
}

int main() 
{
    cin >> N >> M;
    DFS(0);

    return 0;
}