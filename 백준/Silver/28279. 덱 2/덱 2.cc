#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Input = 0, X = 0;
    deque<int> Ds;
    while (N--)
    {
        cin >> Input;

        if (1 == Input)
        {
            cin >> X;
            Ds.push_front(X);
        }
        else if (2 == Input)
        {
            cin >> X;
            Ds.push_back(X);
        }
        else if (3 == Input)
        {
            if (true == Ds.empty())
            {
                cout << -1 << '\n';
                continue;
            }

            cout << Ds.front() << '\n';
            Ds.pop_front();
        }
        else if (4 == Input)
        {
            if (true == Ds.empty())
            {
                cout << -1 << '\n';
                continue;
            }

            cout << Ds.back() << '\n';
            Ds.pop_back();
        }
        else if (5 == Input)
        {
            cout << Ds.size() << '\n';
        }
        else if (6 == Input)
        {
            if (true == Ds.empty())
            {
                cout << 1 << '\n';
                continue;
            }
           
            cout << 0 << '\n';
        }
        else if (7 == Input)
        {
            if (true == Ds.empty())
            {
                cout << -1 << '\n';
                continue;
            }

            cout << Ds.front() << '\n';
        }
        else if (8 == Input)
        {
            if (true == Ds.empty())
            {
                cout << -1 << '\n';
                continue;
            }

            cout << Ds.back() << '\n';
        }
    }

    return 0;
}