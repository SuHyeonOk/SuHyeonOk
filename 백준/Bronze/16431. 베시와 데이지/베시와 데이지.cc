#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int Bx, By, Dx, Dy, Jx, Jy, B, D;
    cin>>Bx>>By>>Dx>>Dy>>Jx>>Jy;
    B = max(abs(Jx-Bx), abs(Jy-By));
    D = abs(Jx-Dx) + abs(Jy-Dy);
    if (B == D)
        cout<<"tie";
    else if (B < D)
        cout<<"bessie";
    else
        cout<<"daisy";
    return 0;
}