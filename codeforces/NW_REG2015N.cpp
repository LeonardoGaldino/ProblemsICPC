// Hash table solution
#include <iostream>
#include <string.h>

using namespace std;

int frequencies[1011];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {		
		memset(frequencies, 0, sizeof frequencies);
		int num;
		scanf("%d", &num);
		while(num--) {
			int a;
			scanf("%d", &a);
			++frequencies[a];
		}
		int maxi = 0;
		for(int i = 1 ; i <= 1000 ; ++i) {
			maxi = max(maxi, frequencies[i]);
		}
		for(int i = 1 ; i <= 1000 ; ++i) {
			if(frequencies[i] == maxi) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
