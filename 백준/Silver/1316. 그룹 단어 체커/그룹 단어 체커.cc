#include <iostream>
using namespace std;

bool GroupFind(string& _str)
{
    size_t size{ _str.size() };
    char current{ ' ' };
    bool bFind{ false };

    for (size_t i = 0; i < size; i++)
    {
        current = _str[i];
        bFind = false;

        for (size_t j = i + 1; j < size; j++)
        {
            if (true == bFind)
            {
                if (current == _str[j])
                {
                    return false;
                }
            }
            else
            {
                if (current != _str[j])
                {
                    bFind = true;
                }
            }
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 }, result{ 0 };
    cin >> N;

    string str{ " " };

    while (N--)
    {
        cin >> str;

        if (true == GroupFind(str))
        {
            ++result;
        }
    }

    cout << result;

    return 0;
}