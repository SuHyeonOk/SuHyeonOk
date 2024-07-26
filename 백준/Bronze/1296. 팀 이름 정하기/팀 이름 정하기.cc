#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Name = "";
    cin >> Name;

    int N = 0;
    cin >> N;

    string TeamNames[50];
    for (int i = 0; i < N; ++i)
    {
        cin >> TeamNames[i];
    }
    sort(TeamNames, TeamNames + N);

    int Max = -1;
    string BastName = "";
    for (int i = 0; i < N; ++i)
    {
        string Temp = "";
        Temp = Name + TeamNames[i];

        int L = 0, O = 0, V = 0, E = 0;
        size_t Length = Temp.length();
        for (size_t j = 0; j < Length; ++j)
        {
            if ('L' == Temp[j])
            {
                ++L;
            }
            else if ('O' == Temp[j])
            {
                ++O;
            }
            else if ('V' == Temp[j])
            {
                ++V;
            }
            else if ('E' == Temp[j])
            {
                ++E;
            }
        }

        int Result = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
        if (Max < Result)
        {
            Max = Result;
            BastName = TeamNames[i];
        }
    }

    cout << BastName;

    return 0;
}