#include <iostream>
using namespace std;

int main() 
{
    double K = 0, N = 0, M = 0;
    cin >> K >> N >> M;
    
    if (K*N > M)
    {
        cout << K * N - M << '\n';
    }
    else
    {
        cout << "0" << '\n';
    }
    
    return 0;
}