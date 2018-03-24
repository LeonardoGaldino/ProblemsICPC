// Binary Search on answer solution

#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX 200003
#define INF 0x3f3f3f3f
#define LLI long long int

using namespace std;

LLI v[MAX];
LLI n, k;

bool check_bs(LLI _try) {
	LLI count = k-1;
	for(LLI i = 0 ; i < n-k+1 ; ++i) {
		if((v[i+k-1]-v[i]) > _try) {
			++count;
			if(!i || i == n-k)
				return false;
		}
		else
			count = 0;
		if(count == k)
			return false;
	}
	return true;
}

int main() {
	scanf("%lld %lld", &n, &k);
	for(LLI i = 0 ; i < n ; ++i)
		scanf("%lld", &v[i]);
	sort(v, v+n);

	LLI lo = 0, hi = 2000000001;
	while(hi-lo > 1) {
		LLI mid = (((hi-lo)>>1)+lo);
		if(check_bs(mid))
			hi = mid;
		else
			lo = mid;
	}
	printf("%lld\n", (check_bs(lo) ? lo : hi));
	return 0;
}
