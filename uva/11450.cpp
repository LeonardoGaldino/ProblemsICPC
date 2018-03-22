#include <iostream>
#include <string.h>

#define INF 0x3f3f3f3f
#define LLI long long int

using namespace std;

bool dp[21][201];
int prices[21][21];
int num[21];
int n;
int money;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &money, &n);
		for(int i = 0 ; i < n ; ++i) {
			scanf("%d", &num[i]);
			for(int j = 0 ; j < num[i] ; ++j)
				scanf("%d", &prices[i][j]);
		}
		memset(dp, false, sizeof dp);
		dp[0][money] = true;
		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j <= money ; ++j) {
				if(dp[i][j]) {
					for(int k = 0 ; k < num[i] ; ++k) {
						if( (j-prices[i][k]) >= 0)
							dp[i+1][j-prices[i][k]] = true;
					}
				}
			}
		}
		int i = 0;
		for(; i <= money ; ++i) {
			if(dp[n][i])
				break;
		}
		if(i > money)
			puts("no solution");
		else
			printf("%d\n", money-i);
	}
	return 0;
}
