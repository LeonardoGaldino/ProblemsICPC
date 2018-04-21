// Preprocess weight and connections and greedy it 
#include <iostream>

typedef long long int LLI;

using namespace std;

LLI w[30];
LLI c[30];

void pre() {
	w[0] = 1;
	w[1] = 3;
	c[0] = 0;
	c[1] = 2;
	for(LLI i = 2 ; i <= 20 ; ++i) {
		w[i] = w[i-1]*3;
		c[i] = c[i-1]*3 + w[i-1]*2;
	}
}

int main() {
	pre();
	LLI t;
	scanf("%lld", &t);
	while(t--) {
		LLI n;
		scanf("%lld", &n);
		bool hasPrinted = false;
		for(LLI i = 20 ; i >= 0 ; --i) {
			if(n >= w[i]) {
				printf("%lld%s", n/w[i], ((!i)?"\n" : " "));
				n %= w[i];
				hasPrinted = true;
			}
			else if(hasPrinted)
				printf("0%s", ((!i) ?"\n" : " "));
		}
	}

	return 0;
}

