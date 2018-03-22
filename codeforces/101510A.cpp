// Complete Search solution

#include <iostream>

using namespace std;

int main() {
	int v[5];
	for(int i = 0 ; i < 5 ; ++i)
		scanf("%d", &v[i]);
	int c = 0;
	for(int i = 0 ; i < 5 ; ++i) {
		for(int j = i+1 ; j < 5 ; ++j) {
			for(int k = j+1 ; k < 5 ; ++k) {
				if(v[i] + v[j] > v[k] &&
				   v[i] + v[k] > v[j] &&
				   v[j] + v[k] > v[i])
					++c;
			}
		}
	}
	printf("%d\n", c);
	return 0;
}