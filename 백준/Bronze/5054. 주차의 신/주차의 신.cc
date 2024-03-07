#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int t=0;
    cin >> t;

    while(t--)
    {
        int min=100, max=-1; 
        int n=0, road=0, input=0;
        
        cin >> n;
        for(int j=0; j<n; j++)
        {
            cin >> input;      
        
           if(input<min)
               min=input;
           if(input>max)
               max=input;  
        }
        road=(max-min)*2;
        cout << road << endl;
    }
    return 0;
}