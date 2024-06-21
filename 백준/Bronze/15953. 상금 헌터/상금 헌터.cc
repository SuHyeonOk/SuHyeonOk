#include <iostream>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        int na = 0; 
        int nb = 0;
            
        if(a==0)
        {
            na=0;
        }
        else if(a==1)
        {
            na=5000000;
        }
        else if(a<=3)
        {
            na=3000000;
        }
        else if(a<=6)
        {
             na=2000000;
        }
        else if(a<=10)
        {
            na=500000;
        }
        else if(a<=15)
        {
            na=300000;
        }
        else if(a<=21)
        {
            na=100000;
        }
            
        if(b==0)
        {
            nb=0;
        }
        else if(b==1)
        {
            nb=5120000;
        }
        else if(b<=3)
        {
            nb=2560000;
        }
        else if(b<=7)
        {
            nb=1280000;
        }
        else if(b<=15)
        {
            nb=640000;
        }
        else if(b<=31)
        {
            nb=320000;
        }
            
        cout<<na+nb<<"\n";
    }
    
    return 0;
}