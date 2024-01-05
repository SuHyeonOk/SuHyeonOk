#include <iostream>
#include <map>
using namespace std;

string arr[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    size_t n{ 0 };
    cin >> n;

    int max_value{ 1 };
    string input{ "" };
    map<string, int> m;
    for (size_t i = 0; i < n; i++)
    {
        cin >> input;
        
        map<string, int>::iterator it = m.find(input);
        if (m.end() == it) // 같은 값이 없는 경우
        {
            m.insert({ input, 1 });
        }
        else // 같은 값이 있는 경우
        {
            ++it->second;

            if (max_value < it->second)
            {
                max_value = it->second;
            }
        }
    }

    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (max_value == it->second)
        {
            cout << it->first << '\n';
            break;
        }
    }

    return 0;
}