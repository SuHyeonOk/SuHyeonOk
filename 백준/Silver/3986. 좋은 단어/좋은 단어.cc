#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Count = 0;
    string Input = "";
    while (N--)
    {
        cin >> Input;
        
        stack<char> Ss;
        size_t Length = Input.length();
        for (size_t i = 0; i < Length; i++)
        {
            if (false == Ss.empty() && Ss.top() == Input[i])
            {
                Ss.pop();
                continue;
            }
            Ss.push(Input[i]);
        }

        if (true == Ss.empty())
        {
            ++Count;
        }
    }

    cout << Count;

    return 0;
}