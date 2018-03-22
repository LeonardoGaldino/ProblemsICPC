//Bottom-Up DP solution

#include <iostream>
#include <climits>
#include <string.h>

#define LLI long long int
#define OFFSET 10000
#define INF 0x3f3f3f3f

using namespace std;

LLI dp[2][22222];
LLI v[101];
LLI n;
LLI ans;

int main() {
	LLI t;
	scanf("%lld", &t);
	while(t--) {
		memset(dp, INF, sizeof dp);
		scanf("%lld", &n);
		for(LLI i = 0 ; i < n ; ++i)
			scanf("%lld", &v[i]);
		dp[0][OFFSET] = 0;	
		for(LLI i = 0 ; i < n ; ++i) {
			for(LLI j = 0 ; j < (OFFSET<<1) ; ++j) {
				dp[(i+1)%2][j+v[i]] = min(dp[(i+1)%2][j+v[i]], max(dp[i%2][j], abs(j-OFFSET+v[i])));
				if(j-v[i] >= 0)
					dp[(i+1)%2][j-v[i]] = min(dp[(i+1)%2][j-v[i]], max(dp[i%2][j], abs(j-OFFSET-v[i])));
			}
			memset(dp[i%2], INF, sizeof dp[i%2]);
		}
		LLI res = INF;
		for(int i = 0 ; i < (OFFSET<<1) ; ++i)
			res = min(res, dp[n%2][i]);
		printf("%lld\n", res);
	}
	return 0;
}
