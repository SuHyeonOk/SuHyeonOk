#include <iostream>
using namespace std;

int main(void)
{
    int N = 0;
    cin >> N;

    int ACount = 0, BCount = 0;
    int A = 0, B = 0;

    for (int n = 0; n < N; n++)
    {
        cin >> A >> B;

        if (A > B)
        {
            ACount++;
        }
        else if (A < B)
        {
            BCount++;
        }
    }

    cout << ACount << " " << BCount << "\n";

    return 0;
}
