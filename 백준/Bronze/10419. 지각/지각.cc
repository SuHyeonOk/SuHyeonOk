#include <iostream>
using namespace std;

int main() 
{
    int ques, s, t, class_time;    
    cin >> ques;
    
    while (ques--)
    {
        s = 0, t = 0;
        int ans = 0;
        cin >> class_time;
        while (true)
        {
            if (class_time < s + t) 
            { 
                t--; 
                break;
            }
            
            t++;
            s = t * t;
        }
        cout << t << '\n';
    }
    
    return 0;
}