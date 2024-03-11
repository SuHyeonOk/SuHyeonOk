#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
  int n, x;
  vector<int> v;
    
  cin >> n;

  for(int i=1; i<=n; i++)
  {
    cin >> x;
    v.insert(v.begin() + x, i);
  }

  for(int i = n - 1; i >= 0; i--)
  {
    cout << v[i] << " ";
  }

  return 0;
}