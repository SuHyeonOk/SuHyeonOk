#include <iostream>
#include <algorithm>
using namespace std;

typedef struct tagInformation
{
    int Count = 0;
    int SamNum = 0;
}INFO;

INFO SamCount(int _A, int _B, int _C)
{
    INFO Result = { 0 ,0 };
    if (_A == _B && _B == _C)
    {
        Result = { 3, _A };
        return Result;
    }
    else if (_A == _B || _A == _C)
    {
        Result = { 2, _A };
        return Result;
    }
    else if (_B == _C)
    {
        Result = { 2, _B };
        return Result;
    }

    return Result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int A = 0, B = 0, C = 0, Count = 0, Max = 0;
    int BestA = 0, BestB = 0, BestC = 0;
    INFO Temp = { 0, 0 };

    while (N--)
    {
        cin >> A >> B >> C;

        Temp = SamCount(A, B, C);
        int TempCount = Temp.Count;

        if (Count < TempCount)
        {
            Count = TempCount;
        }
        else
        {
            if (A + B + C > BestA + BestB + BestC)
            {
                BestA = A;
                BestB = B;
                BestC = C;
            }
            //else  if (A + B + C == BestA + BestB + BestC)
            //{
            //    int TempMax = max({ A, B, C });
            //    int BestMax = max({ BestA, BestB, BestC });

            //    if (TempMax > BestMax)
            //    {
            //        BestA = A;
            //        BestB = B;
            //        BestC = C;
            //    }
            //}
        }

        if (TempCount == 0)
        {
            Max = max(Max, 100 * max({ BestA, BestB, BestC }));
        }
        else if (TempCount == 2)
        {
            Max = max(Max, 1000 + (Temp.SamNum * 100));
        }
        else // 3
        {
            Max = max(Max, 10000 + (Temp.SamNum * 1000));
        }
    }

    cout << Max;

    return 0;  
}       