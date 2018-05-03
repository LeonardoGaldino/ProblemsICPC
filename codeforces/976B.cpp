// Solves using formulae (almost)
#include <bits/stdc++.h>

#define fr(i,st,nd,q) for(int i = st ; i < nd ; i += q)
#define PII pair<int,int>
#define VI vector<int>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define LLI long long int

using namespace std;

int main() {
	LLI n,m,k;
	scanf("%lld %lld %lld", &n, &m, &k);
	LLI r = 1, c = 1;
	r = min(n, k+1);
	if(k < (n-1)) {
		cout << r << " " << c << endl;
		return 0;
	}
	k -= (n-1);
	c = min(m, k+1);
	if(k < (m-1)) {
		cout << r << " " << c << endl;
		return 0;
	}
	k -= (m-1);
	LLI times = (k/(m-1));
	LLI rem = (k%(m-1));
	r -= times;
	bool oddT = (times&1);
	c = (oddT ? 2 : m);
	if(rem != 0) {
		--r;
		--rem;
		c += (oddT ? rem : -rem);
	}
	cout << r << " " << c << endl;
	return 0;
}
