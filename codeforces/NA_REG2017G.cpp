#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>

using namespace std;

int n,m;
int dp[105][22222][2];
int v[105];

int go(int st, int eat, int av, int prev, int rested) {
	if(st == n)
		return dp[st][av][rested] = max(eat, dp[st][av][rested]);
	if(eat <= dp[st][av][rested])
		return dp[st][av][rested];
	int t1 = go(st+1, eat+min(v[st], av), int(2.0/3.0*av), av, 0);
	int t2 = go(st+1, eat, (rested?m:prev), m, 1);
	return dp[st][av][rested] = max(dp[st][av][rested], max(t1,t2));
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d", &v[i]);
	memset(dp, -1, sizeof dp);
	int t = go(0, 0, m, m, 0);
	printf("%d\n", t);
	/*
	for(int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j <= MAX ; ++j) {
			if(dp[i][j].first == -1)
				continue;
			int temp = int(((2.0*double(dp[i][j].first))/3.0)); // Próximo m, caso coma
			int temp2 = min(v[i], dp[i][j].first); // Quanto vai ter comido, caso coma
			temp2 += j;
			if(temp2 >= MAX)
				continue;
			if(dp[i+1][temp2].first < temp)
				dp[i+1][temp2] = {temp, dp[i][j].first};
			else if(dp[i+1][temp2].first == temp && dp[i+1][temp2].second < dp[i][j].second)
				dp[i+1][temp2] = {temp, dp[i][j].first};

			if(dp[i+1][j].first <= dp[i][j].second)
				dp[i+1][j] = { dp[i][j].second, m };
		}
	}
	int ans = 0;
	for(int i = MAX-1 ; i >= 0 ; --i) {
		if(~dp[n][i].first) {
			printf("%d\n", i);
			break;
		}
	}*/
	return 0;
}