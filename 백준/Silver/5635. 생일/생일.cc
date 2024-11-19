#include <iostream>
using namespace std;

typedef struct tagInformation
{
    string Name = "";
    int D = 0, M = 0, Y = 0;
}INFO;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    INFO Info{ "", 0, 0, 0 };
    INFO Max{ "", 0, 0, 0 }; // 가장 젊은
    INFO Min{ "", 32, 13, 2011 }; // 가장 늙은 (모든 숫자가 가장 적은 경우)
    for (int i = 0; i < N; ++i)
    {
        cin >> Info.Name >> Info.D >> Info.M >> Info.Y;

        // 가장 늙은
        if (Info.Y < Min.Y)
        {
            Min = Info;
        }
        else if (Info.Y == Min.Y)
        {
            if (Info.M < Min.M)
            {
                Min = Info;
            }
            else if (Info.M < Min.M)
            {
                if (Info.D < Min.D)
                {
                    Min = Info;
                }
            }
        }

        // 가장 젊은
        if (Info.Y > Max.Y)
        {
            Max = Info;
        }
        else if (Info.Y == Max.Y)
        {
            if (Info.M > Max.M)
            {
                Max = Info;
            }
            else if (Info.M > Max.M)
            {
                if (Info.D > Max.D)
                {
                    Max = Info;
                }
            }
        }
    }

    cout << Max.Name << '\n' << Min.Name;

    return 0;
}