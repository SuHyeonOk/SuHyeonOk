#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,i,j,k;
    cin>>n>>m;
    
    int arr[100]; 
    for(int p=0;p<100;p++)
    {
        arr[p]=p+1;
    }
    
    while(m-->0)
    {
        cin>>i>>j>>k;
        rotate(arr+i-1,arr+k-1,arr+j);
    }
    
    for(int p=0;p<n;p++)
    {
        cout<<arr[p]<<" ";
    }
    
    return 0;
}