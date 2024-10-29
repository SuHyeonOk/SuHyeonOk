#include <iostream>
#include <string>
using namespace std;

void GenerateCantorSet(string &Line, int Start, int Length)
{
    if (Length == 1)
    {
        return;
    }

    int SectionLength = Length / 3;
    
    for (int i = Start + SectionLength; i < Start + 2 * SectionLength; i++)
    {
        Line[i] = ' ';
    }

    GenerateCantorSet(Line, Start, SectionLength);
    GenerateCantorSet(Line, Start + 2 * SectionLength, SectionLength);
}

int main()
{
    int N;
    while (cin >> N)
    {
        int Length = 1;
        for (int i = 0; i < N; i++)
        {
            Length *= 3;
        }

        string Line(Length, '-');
        GenerateCantorSet(Line, 0, Length);
        cout << Line << endl;
    }

    return 0;
}