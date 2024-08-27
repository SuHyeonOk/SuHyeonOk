#include <bits/stdc++.h>
#define MAX 1000010
#define INF 2147483647
#define MOD 10000
typedef long long ll;
using namespace std;
//

int a, k;
int dp[MAX]; // dp[n] = a에서 n까지 필요한 최소 연산 횟수

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> a >> k;

    for(int i = a+1; i <= k; i++) {
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0 && i / 2 >= a) dp[i] = min(dp[i], dp[i/2]+1);
    }

    cout << dp[k];

    return 0;
}