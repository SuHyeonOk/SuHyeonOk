#include <iostream>
using namespace std;

int gcd(int a, int b)
{ 
    // 최대 공약수
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b) 
{ 
    // 최소 공배수
    return (a * b) / gcd(a, b);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T{ 0 };
    cin >> T;

    while (T--) 
    {
        int M{ 0 }, N{ 0 }, x{ 0 }, y{ 0 };
        cin >> M >> N >> x >> y;

        int maxi = lcm(M, N); // 멸망해

        int result{ -1 };
        for (int i = x; i <= maxi; i += M)
        {
            int ny{ i % N }; // y값
           
            if (ny == 0) // 이때는 y가 최대값이 됨
            {
                ny = N;
            }

            if (ny == y) // 정답
            { 
                result = i;
                break;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
