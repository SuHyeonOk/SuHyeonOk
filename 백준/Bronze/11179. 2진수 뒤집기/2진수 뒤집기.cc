#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long solve(long long x)
{
    string str="";
    while(x>0)
    {
        if(x%2==1)
        {
            str+="1";
        }
        else
        {
            str+="0";
        }
        x/=2;
    }

    long long ans=0;
    for(int i=0; i<str.size(); i++)
    {
        ans= ans*2 + (str[i]-'0');
    }

    return ans;
}


int main()
{
    long long x; cin>>x;
    cout<<solve(x);
    
    return 0;
}
