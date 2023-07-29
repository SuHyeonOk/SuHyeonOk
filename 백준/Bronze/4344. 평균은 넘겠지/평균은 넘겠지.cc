#pragma once // 헤더의 중복 선언을 방지
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <string>
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// ◆ 4344번 평균은 넘겠지
	int testCount; // 세로 테스트 개수
	std::cin >> testCount;
	cout << fixed; // 이친구를 적어야 함! 소수점 3자리 precision와 친구임

	for (int i = 0; i < testCount; i++) // 세로
	{
		int score; // 가로 계산 개수
		std::cin >> score;
		double mean = 0.0; // 결과 평균값
		vector<int> v;
		int input = 0;

		for (int j = 0; j < score; j++) // 가로
		{
			std::cin >> input;
			v.push_back(input);
			mean += input;
		}

		mean = mean / score;

		double count = 0;
		for (int j = 0; j < score; j++)
		{
			if (mean < v[j])
			{
				count++;
			}
		}

		double result = 0.0;
		result = count / v.size() * 100; // 분자 / 분모 == 개수 / 전체개수

		cout.precision(3); // 소수점 자리 3자리수까지만 나오도록
		cout << result << "%" << endl;
	}
}