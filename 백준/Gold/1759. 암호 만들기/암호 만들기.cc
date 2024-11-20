#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char arr[15];

// _Consonant : 자음 개수, _Vowel : 모음 개수
void Backtracking(int _Depth, string _Str, int _Consonant, int _Vowel) 
{
	_Str.push_back(arr[_Depth]);
	if (arr[_Depth] == 'a' || arr[_Depth] == 'e' || arr[_Depth] == 'i' || arr[_Depth] == 'o' || arr[_Depth] == 'u')
	{
		_Vowel++;
	}
	else
	{
		_Consonant++;
	}

	if (_Str.length() == L) 
	{
		if (_Consonant >= 2 && _Vowel >= 1) // 자음, 모음 개수 충족
		{
			cout << _Str << '\n';
		}
		return;
	}

	for (int i = _Depth + 1; i < C; i++)
	{
		Backtracking(i, _Str, _Consonant, _Vowel);
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + C);

	for (int i = 0; i <= C - L; i++)
	{
		Backtracking(i, "", 0, 0);
	}

	return 0;
}