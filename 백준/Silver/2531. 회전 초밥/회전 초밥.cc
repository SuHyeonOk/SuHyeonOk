#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int arr[30001];
int check[3001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0, d = 0, k = 0, c = 0;
	cin >> N >> d >> k >> c;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	// 슬라이딩 윈도우
	int Count, Coupon, Max = 0;
	for (int i = 0; i < N; i++)
	{
		Count = 0; // 중복된 스시 체크
		Coupon = 1; // 쿠폰 스시가 있는지 확인
		for (int j = i; j < i + k; j++) 
		{				
			if (check[arr[j % N]] == 1)
			{
				Count++; // 이미 먹은 초밥일 경우 중복 수 표시	
			}
			else
			{
				check[arr[j % N]] = 1; // 처음 먹어보는 초밥일 경우 체크		
			}

			if (arr[j % N] == c)
			{
				Coupon = 0; // 쿠폰 스시 있을 시
			}
		}

		Max = max(Max, k - Count + Coupon); //연속으로 먹을 수 있는 최대접시 - 중복접시 + 쿠폰스시	
		memset(check, 0, sizeof(check));
	}

	cout << Max;
}