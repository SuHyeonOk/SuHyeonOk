#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string Name = "";
    cin >> Name;

    int alpha[97]{ 0 };
    for (char i : Name)
    {
        alpha[i]++;
    }

    string Start = "", End = "";
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (alpha[i] % 2)
        {
            Start += i;
        }

        for (int j = 0; j < alpha[i] / 2; j++)
        {
            End += i;
        }
    }

    if (Start.size() > 1)
    {
        printf("I'm Sorry Hansoo");
    }
    else
    {
        cout << End << Start;
        reverse(End.begin(), End.end());
        cout << End;
    }
}