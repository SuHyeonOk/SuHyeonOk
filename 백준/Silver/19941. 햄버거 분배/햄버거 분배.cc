#include <iostream>
#include <string>
using namespace std;
 
int main() 
{
  string arr = "";
  int n = 0, k = 0, cnt = 0, sw = 0;
  cin >> n >> k;
  cin >> arr;
  
  for(int i=0; i<n; i++) 
  {
    if(arr[i]!='P')
    {
        continue;
    }
 
    for(int j=i-k; j<=i + k; j++) 
    {
      if(0 <= j && j < n && arr[j] == 'H') 
      {
        arr[j]='-';
        cnt++;
        break;
      }
    }
  }
 
  cout << cnt;
    
  return 0;
}
