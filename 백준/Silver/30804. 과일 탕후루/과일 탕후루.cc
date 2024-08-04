#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;
    
    queue<int> q;
    int visited[10]{ 0 };
    int Type = 0, Ans = 0;

    while (N--)
    {
        int fruit;
        cin >> fruit;

        q.push(fruit);

        if (visited[fruit]++ == 0)
        {
            ++Type;
        }

        while (Type > 2)
        {
            fruit = q.front();
            q.pop();

            if (--visited[fruit] == 0)
            {
                --Type;
            }
        }

        Ans = max(Ans, static_cast<int>(q.size()));
    }

    cout << Ans;

    return 0;
}