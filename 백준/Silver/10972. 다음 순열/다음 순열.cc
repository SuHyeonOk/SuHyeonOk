#include <iostream>
#include <vector>
using namespace std;

bool next_permutation(vector<int>& a, int n)
{
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i])
    {
        i -= 1; // 뒤에서부터 어디까지 내림차순인지 찾아보기
    }

    // while문을 빠져나왔을때의 i가 내림차순의 시작하는 부분
    if (i <= 0)
    {
        return false;
    }

    int j = n - 1;
    while (a[j] <= a[i - 1])
    {
        j -= 1; // 내림차순 바로 앞의 숫자보다 처음으로 큰 j를 뒤에서부터 찾아보기
    }

    swap(a[i - 1], a[j]);
    j = n - 1; // 순열의 마지막 자리

    while (i < j) // 내림차순의 시작부분부터 마지막 짜리까지 뒤집어준다.
    {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    if (next_permutation(vec, N))
    {
        for (int i = 0; i < N; ++i)
        {
            cout << vec[i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << -1;
    }

    return 0;
}