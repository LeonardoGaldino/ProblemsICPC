// PD solution
#include <iostream>
#include <string.h>

typedef long long int LLI;

using namespace std;

LLI memo[10000][5];
LLI coins[] = {50, 25, 10, 5, 1};
LLI numCoins = 5;

LLI computeWays(LLI n, LLI minimumCoinIdx) {
	if(n < 0)
		return 0;
	if(~memo[n][minimumCoinIdx])
		return memo[n][minimumCoinIdx];
	LLI ans = 0;
	for(LLI i = minimumCoinIdx ; i < numCoins ; ++i) {
		ans += computeWays(n-coins[i], i);
	}

	return (memo[n][minimumCoinIdx] = ans);	
}

int main() {
	LLI n;
	while(scanf("%lld", &n) == 1) {
		memset(memo, -1, sizeof memo);
		for(LLI i = 0 ; i < numCoins ; ++i)
			memo[0][i] = 1;
		printf("%lld\n", computeWays(n,0));
	}
	return 0;
}
