#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    string Pattern = "";
    cin >> N >> Pattern;

    string Start = "";
    string End = "";
    bool Find = false;
    size_t PatternSize = Pattern.size();
    for (size_t i = 0; i < PatternSize; i++)
    {
        if (false == Find)
        {
            if (Pattern[i] == '*')
            {
                Find = true;
                continue;
            }

            Start += Pattern[i];
        }
        else
        {
            End += Pattern[i];
        }
    }
    int StartSize = Start.size();
    int EndSize = End.size();


    string Input = "";
    while(N--)
    {
        cin >> Input;
        Find = false;

        int InputSize = Input.size();
        if (InputSize < StartSize + EndSize)
        {
            cout << "NE" << '\n';
            continue;
        }

        for (int i = 0; i < StartSize; i++)
        {
            if (Input[i] != Start[i])
            {
                Find = true;
                continue;
            }
        }

        if (true == Find)
        {
            cout << "NE" << '\n';
            continue;
        }

        int j = 1;
        for (int i = EndSize - 1; i >= 0; i--)
        {
            if (Input[InputSize - j] != End[i])
            {
                Find = true;
                continue;
            }
            j++;
        }

        if (true == Find)
        {
            cout << "NE" << '\n';
            continue;
        }

        cout << "DA" << '\n';
    }

    return 0;
}