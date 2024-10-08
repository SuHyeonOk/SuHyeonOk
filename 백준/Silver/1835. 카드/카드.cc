#include <iostream>
#include <deque>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int N = 0;
	cin >> N;

	deque<int> dq;
	dq.push_back(N);
	for (int i = N - 1; i > 0; i--) 
	{
		dq.push_front(i);

		for (int j = 0; j < i; j++) 
		{
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}

	while (false == dq.empty()) 
	{
		cout << dq.front() << ' ';
		dq.pop_front();
	}

    return 0;
}