#include <iostream>
#include <algorithm>
#include <set>
#define MAX 10001
using namespace std;

int N{ 0 }, M{ 0 };
int num[MAX];
int arr[MAX];

void DFS(int _count, int _index)
{
    // 목표 M까지 도달 했다면
    if (_count == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }

    // 목표에 도달하지 못 했다면
    for (int i = _index; i < N; i++)
    {
        arr[_count] = num[i];
        DFS(_count + 1, i); // M까지 들어간다.
    }
}

int main()
{
    cin >> N >> M;

    int temp{ 0 };
    set<int> input;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        input.insert(temp);
    }

    int index{ 0 };
    for (set<int>::iterator it = input.begin(); it != input.end(); it++) 
    {
        num[index] = *it;
        ++index;
    }

    N = static_cast<int>(input.size()); // 중복된 숫자를 제외한 숫자로 갱신
    sort(num, num + N);

    DFS(0, 0);

    return 0;
}