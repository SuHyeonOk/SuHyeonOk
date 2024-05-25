#include <iostream>
using namespace std;

int main()
{
    int N = 0, M = 0, answer = 0;
    string problem;
    cin >> N >> M;
    
    while (N--)
    {
        cin >> problem;
        
        int cnt = 0;
        for (char c : problem)
        {
            if (c == 'O')
            {
                ++cnt;
            }
        }
        if (cnt * 2 > M) // 과반수 확인
        {
            ++answer;
        }
    }
    
    cout << answer;
    
    return 0;
}