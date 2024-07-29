#include <iostream>
#include <vector>
using namespace std;

int N, Ans;
vector<int> vec;

void DFS(int sum) 
{
    size_t Size = vec.size();
    if (Size == 2)
    {
        Ans = max(Ans, sum);
        return;
    }

    for (int i = 1; i < Size - 1; i++)
    {
        int Add = vec[i - 1] * vec[i + 1];
        int Temp = vec[i];

        vec.erase(vec.begin() + i);
        DFS(sum + Add);
        vec.insert(vec.begin() + i, Temp);
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vec.resize(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> vec[i];
    }

    DFS(0);
    cout << Ans << endl;

    return 0;
}
